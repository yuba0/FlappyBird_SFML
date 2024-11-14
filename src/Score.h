#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>

class Score
{
public:
    Score();                              // Constructeur pour initialiser le score et charger la police

    void incrementScore();                // Incrémente le score actuel
    void resetScore();                    // Réinitialise le score actuel à zéro
    void render(sf::RenderWindow &window); // Affiche le score actuel et le meilleur score sur la fenêtre

    int getCurrentScore() const;          // Retourne le score actuel
    int getHighScore() const;             // Retourne le meilleur score

private:
    int currentScore;                     // Score actuel de la partie en cours
    int highScore;                        // Meilleur score atteint
    sf::Font font;                        // Police utilisée pour afficher le score
    sf::Text scoreText;                   // Texte affichant le score actuel
    sf::Text highScoreText;               // Texte affichant le meilleur score
};

#endif // SCORE_H
