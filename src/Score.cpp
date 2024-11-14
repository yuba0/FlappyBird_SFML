#include "Score.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Score::Score()
    : currentScore(0), highScore(0)
{
    // Chargement de la police pour l'affichage du score
    if (!font.loadFromFile("assets/fonts/OpenSans-Regular.ttf"))
    {
        std::cerr << "Erreur: Impossible de charger la police" << std::endl;
    }

    // Configuration de l'affichage du score actuel
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(20, 20);  // Position en haut à gauche

    // Configuration de l'affichage du meilleur score
    highScoreText.setFont(font);
    highScoreText.setCharacterSize(20);
    highScoreText.setFillColor(sf::Color::Yellow);
    highScoreText.setPosition(20, 60);  // Position en dessous du score actuel
}

void Score::incrementScore()
{
    currentScore += 1;

    // Met à jour le meilleur score si le score actuel le dépasse
    if (currentScore > highScore)
    {
        highScore = currentScore;
    }
}

void Score::resetScore()
{
    currentScore = 0;
}

void Score::render(sf::RenderWindow &window)
{
    // Met à jour les textes de score avant de les afficher
    scoreText.setString("Score: " + std::to_string(currentScore));
    highScoreText.setString("High Score: " + std::to_string(highScore));

    // Affiche le score actuel et le meilleur score
    window.draw(scoreText);
    window.draw(highScoreText);
}

int Score::getCurrentScore() const
{
    return currentScore;
}

int Score::getHighScore() const
{
    return highScore;
}
