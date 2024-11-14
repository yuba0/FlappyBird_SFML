#ifndef PIPEMANAGER_H
#define PIPEMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Pipe.h"
#include "Bird.h"

class PipeManager
{
public:
    PipeManager();                        // Constructeur pour initialiser le gestionnaire de tuyaux

    void updatePipes();                   // Met à jour la position des tuyaux et gère leur création
    void render(sf::RenderWindow &window); // Affiche tous les tuyaux sur la fenêtre
    bool checkCollisionWithBird(const Bird &bird) const; // Vérifie les collisions avec l'oiseau
    void reset();                         // Réinitialise les tuyaux pour un nouveau départ

    const std::vector<Pipe>& getPipes() const { return pipes; } // Retourne la liste des tuyaux

private:
    std::vector<Pipe> pipes;              // Vecteur contenant tous les tuyaux actifs
    int spawnInterval;                    // Intervalle entre chaque paire de tuyaux en pixels
    int spawnTimer;                       // Compteur pour déterminer quand créer de nouveaux tuyaux
};

#endif // PIPEMANAGER_H
