#include "PipeManager.h"
#include "Pipe.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <iostream>


PipeManager::PipeManager()
    : spawnInterval(150),  // Intervalle entre chaque paire de tuyaux en pixels
      spawnTimer(0)
{
    // Ajoute une paire de tuyaux initiale
    pipes.emplace_back(Pipe(800));
}

void PipeManager::updatePipes()
{
    spawnTimer += 1;

    // Ajoute une nouvelle paire de tuyaux lorsque le spawnTimer atteint l'intervalle défini
    if (spawnTimer >= spawnInterval)
    {
        pipes.emplace_back(Pipe(800));  // Position initiale en dehors de l'écran, à droite
        spawnTimer = 0;
    }

    // Met à jour la position de chaque tuyau et supprime ceux qui sont hors de l'écran
    for (auto &pipe : pipes)
    {
        pipe.move();
    }

    // Supprime les tuyaux sortis de l'écran
    if (!pipes.empty() && pipes.front().isOffScreen())
    {
        pipes.erase(pipes.begin());
    }
}


void PipeManager::render(sf::RenderWindow &window)
{
    for (auto &pipe : pipes)
    {
        pipe.render(window);
    }
}

bool PipeManager::checkCollisionWithBird(const Bird &bird) const
{
    for (const auto &pipe : pipes)
    {
        if (pipe.getTopBounds().intersects(bird.getBounds()) || 
            pipe.getBottomBounds().intersects(bird.getBounds()))
        {
            return true;
        }
    }
    return false;
}

void PipeManager::reset()
{
    pipes.clear();
    pipes.emplace_back(Pipe(800));  // Réinitialise avec une paire de tuyaux au début
    spawnTimer = 0;
}
