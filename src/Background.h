#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background
{
public:
    Background();                        // Constructeur pour initialiser le fond et le sol

    void move();                         // Déplace le sol pour créer un effet de défilement
    void render(sf::RenderWindow &window); // Affiche le fond et le sol sur la fenêtre

private:
    sf::Texture backgroundTexture;       // Texture de l'arrière-plan
    sf::Sprite backgroundSprite1;        // Premier sprite de l'arrière-plan pour le défilement
    sf::Sprite backgroundSprite2;        // Deuxième sprite de l'arrière-plan pour le défilement
    
    sf::Texture groundTexture;           // Texture du sol
    sf::Sprite groundSprite1;            // Premier segment de sol pour le défilement
    sf::Sprite groundSprite2;            // Deuxième segment de sol pour le défilement

    float scrollSpeed;                   // Vitesse de défilement du sol
};

#endif // BACKGROUND_H
