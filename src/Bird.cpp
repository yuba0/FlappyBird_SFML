#include "Bird.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Bird::Bird()
    : position(200, 300),  // Position initiale de l'oiseau
      velocity(0),
      gravity(0.5f),
      jumpStrength(-8.0f)
{
    if (!texture.loadFromFile("assets/bird/bird1.png"))
    {
        std::cerr << "Erreur: Impossible de charger la texture de l'oiseau" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Bird::jump()
{
    velocity = jumpStrength;
}

void Bird::updatePosition()
{
    // Applique la gravité à la vitesse
    velocity += gravity;
    // Met à jour la position verticale en fonction de la vitesse
    position.y += velocity;

    // Limite l'oiseau à l'écran pour éviter qu'il ne sorte par le bas
    if (position.y > 550)  // Limite inférieure
    {
        position.y = 550;
        velocity = 0;
    }
    else if (position.y < 0)  // Limite supérieure
    {
        position.y = 0;
        velocity = 0;
    }

    sprite.setPosition(position);
}

void Bird::render(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Bird::reset()
{
    position = sf::Vector2f(200, 300);
    velocity = 0;
    sprite.setPosition(position);
}

sf::FloatRect Bird::getBounds() const
{
    return sprite.getGlobalBounds();
}

