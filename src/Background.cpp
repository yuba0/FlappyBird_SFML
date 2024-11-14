#include "Background.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Background::Background()
    : scrollSpeed(-1.0f)  // Vitesse de défilement
{
    // Chargement de l'image de fond
    if (!backgroundTexture.loadFromFile("assets/background/background_day.png"))
    {
        std::cerr << "Erreur: Impossible de charger l'image de fond" << std::endl;
    }
    backgroundSprite1.setTexture(backgroundTexture);
    backgroundSprite2.setTexture(backgroundTexture);

    // Position initiale des deux segments de l'arrière-plan
    backgroundSprite1.setPosition(0, 0);
    backgroundSprite2.setPosition(backgroundTexture.getSize().x, 0);  // Place le second segment juste après le premier

    // Chargement de l'image du sol
    if (!groundTexture.loadFromFile("assets/ground/ground.png"))
    {
        std::cerr << "Erreur: Impossible de charger l'image du sol" << std::endl;
    }
    groundSprite1.setTexture(groundTexture);
    groundSprite2.setTexture(groundTexture);

    // Positionnement initial des deux segments du sol pour le défilement
    groundSprite1.setPosition(0, 500);  // Ajuste la position verticale selon l'écran
    groundSprite2.setPosition(groundTexture.getSize().x, 500);  // Place le second segment juste après le premier
}

void Background::move()
{
    // Déplace les segments de l'arrière-plan vers la gauche
    backgroundSprite1.move(scrollSpeed, 0);
    backgroundSprite2.move(scrollSpeed, 0);

    // Réinitialise la position des sprites pour un défilement continu
    if (backgroundSprite1.getPosition().x + backgroundTexture.getSize().x <= 0) {
        backgroundSprite1.setPosition(backgroundSprite2.getPosition().x + backgroundTexture.getSize().x, 0);
    }
    if (backgroundSprite2.getPosition().x + backgroundTexture.getSize().x <= 0) {
        backgroundSprite2.setPosition(backgroundSprite1.getPosition().x + backgroundTexture.getSize().x, 0);
    }

    // Déplace les segments de sol vers la gauche
    groundSprite1.move(scrollSpeed, 0);
    groundSprite2.move(scrollSpeed, 0);

    // Réinitialise la position du sol pour un défilement infini
    if (groundSprite1.getPosition().x + groundTexture.getSize().x < 0)
    {
        groundSprite1.setPosition(groundSprite2.getPosition().x + groundTexture.getSize().x, 500);
    }
    if (groundSprite2.getPosition().x + groundTexture.getSize().x < 0)
    {
        groundSprite2.setPosition(groundSprite1.getPosition().x + groundTexture.getSize().x, 500);
    }
}

void Background::render(sf::RenderWindow &window)
{
    // Affiche les deux segments de l'arrière-plan
    window.draw(backgroundSprite1);
    window.draw(backgroundSprite2);

    // Affiche les deux segments du sol
    window.draw(groundSprite1);
    window.draw(groundSprite2);
}
