#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>

class Bird
{
public:
    Bird();                 // Constructeur pour initialiser l'oiseau

    void jump();            // Fait sauter l'oiseau
    void updatePosition();  // Met à jour la position de l'oiseau en fonction de la gravité
    void render(sf::RenderWindow &window);  // Affiche l'oiseau sur la fenêtre
    void reset();           // Réinitialise la position de l'oiseau

    sf::FloatRect getBounds() const;  // Retourne les limites de l'oiseau pour la détection de collision
    sf::Vector2f getPosition() const { return position; }  // Retourne la position de l'oiseau

private:
    sf::Sprite sprite;      // Sprite pour représenter l'oiseau
    sf::Texture texture;    // Texture de l'image de l'oiseau
    sf::Vector2f position;  // Position de l'oiseau
    float velocity;         // Vitesse verticale de l'oiseau
    float gravity;          // Gravité appliquée à l'oiseau
    float jumpStrength;     // Force de saut appliquée quand l'oiseau saute
};

#endif // BIRD_H
