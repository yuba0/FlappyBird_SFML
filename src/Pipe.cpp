#include "Pipe.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

Pipe::Pipe(float x)
    : position(x, 0),
      speed(-5.0f)  // Vitesse de défilement vers la gauche
{
    if (!texture.loadFromFile("assets/pipes/pipe.png"))  // Utilise une seule texture pour les deux tuyaux
    {
        std::cerr << "Erreur: Impossible de charger la texture du tuyau" << std::endl;
    }

    float gap = 150.0f;  // Taille de l'écart
    float topHeight = static_cast<float>(std::rand() % 200 + 100);

    // Initialisation du tuyau inférieur
    spriteBottom.setTexture(texture);
    spriteBottom.setPosition(position.x, topHeight + gap);
    spriteBottom.setColor(sf::Color::Red);  // Test de couleur pour le tuyau inférieur

    // Initialisation du tuyau supérieur avec une rotation
    spriteTop.setTexture(texture);
    spriteTop.setRotation(180);  // Tourne le tuyau supérieur de 180°
    spriteTop.setPosition(position.x + texture.getSize().x, topHeight);  // Ajuste la position pour aligner les tuyaux
    spriteTop.setColor(sf::Color::Red);  // Test de couleur pour le tuyau supérieur
}

void Pipe::move()
{
    // Déplace les tuyaux vers la gauche
    position.x += speed;
    spriteTop.setPosition(position.x + texture.getSize().x, spriteTop.getPosition().y);
    spriteBottom.setPosition(position.x, spriteBottom.getPosition().y);
}

void Pipe::render(sf::RenderWindow &window)
{
    window.draw(spriteTop);
    window.draw(spriteBottom);
}

bool Pipe::isOffScreen() const
{
    return position.x + spriteTop.getGlobalBounds().width < 0;
}

sf::FloatRect Pipe::getTopBounds() const
{
    return spriteTop.getGlobalBounds();
}

sf::FloatRect Pipe::getBottomBounds() const
{
    return spriteBottom.getGlobalBounds();
}

void Pipe::reset(float x)
{
    position.x = x;
    float topHeight = static_cast<float>(std::rand() % 200 + 100);

    spriteTop.setPosition(position.x + texture.getSize().x, topHeight);
    spriteBottom.setPosition(position.x, topHeight + 150.0f);  // Recrée l'écart entre les tuyaux
}
