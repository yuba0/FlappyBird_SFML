#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "PipeManager.h"
#include "Score.h"
#include "Background.h"
#include "CollisionManager.h"

class Game
{
public:
    Game();                // Constructeur du jeu
    void run();            // Démarre la boucle principale du jeu

private:
    // Méthodes privées pour gérer le jeu
    void handleEvents();   // Gère les événements utilisateur
    void update();         // Met à jour les éléments du jeu
    void render();         // Affiche les éléments du jeu
    void restart();        // Réinitialise le jeu
    bool checkCollisions();// Vérifie les collisions

    // Méthodes auxiliaires
    void renderGameOver(); // Affiche le message de fin de partie

    // Fenêtre du jeu
    sf::RenderWindow window;

    // Instances des éléments du jeu
    Bird bird;
    PipeManager pipeManager;
    Score score;
    Background background;
    CollisionManager collisionManager;

    // Enumération pour les états du jeu
    enum class GameState { Ready, Playing, GameOver };
    GameState gameState;
};

#endif // GAME_H
