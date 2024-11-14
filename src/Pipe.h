#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>

class Pipe
{
public:
    Pipe(float x);                 // Constructeur pour initialiser le tuyau à une position donnée

    void move();                   // Déplace le tuyau vers la gauche
    void render(sf::RenderWindow &window); // Affiche le tuyau sur la fenêtre
    bool isOffScreen() const;      // Vérifie si le tuyau est sorti de l'écran (pour réutilisation ou suppression)

    sf::FloatRect getTopBounds() const;    // Retourne les limites du tuyau supérieur
    sf::FloatRect getBottomBounds() const; // Retourne les limites du tuyau inférieur

    void reset(float x);           // Réinitialise la position et l'écart du tuyau pour une réutilisation
    // Ajout d'un getter pour la position


private:
    sf::Texture texture;           // Texture commune pour les deux tuyaux (supérieur et inférieur)
    sf::Sprite spriteTop;          // Sprite pour le tuyau supérieur
    sf::Sprite spriteBottom;       // Sprite pour le tuyau inférieur

    sf::Vector2f position;         // Position du tuyau (pour le déplacement horizontal)
    float speed;                   // Vitesse de déplacement du tuyau
};

#endif // PIPE_H
