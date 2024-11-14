#include "Game.h"
#include "Bird.h"
#include "PipeManager.h"
#include "Score.h"
#include "Background.h"
#include "CollisionManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

Game::Game()
    : window(sf::VideoMode(400, 600), "Flappy Bird"),
      bird(),
      pipeManager(),
      score(),
      background(),
      collisionManager(),
      gameState(GameState::Ready)
{
    window.setFramerateLimit(60);  // Limite de 60 FPS
}

void Game::run()
{
    while (window.isOpen())
    {
        handleEvents();
        if (gameState == GameState::Playing)
        {
            update();
            if (checkCollisions())
            {
                gameState = GameState::GameOver;
            }
        }
        render();
    }
}

void Game::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        {
            if (gameState == GameState::Ready)
            {
                gameState = GameState::Playing;
            }
            if (gameState == GameState::Playing)
            {
                bird.jump();
            }
            else if (gameState == GameState::GameOver)
            {
                restart();
            }
        }
    }
}

void Game::update()
{
    bird.updatePosition();
    pipeManager.updatePipes();
    background.move();
    score.incrementScore();
}

bool Game::checkCollisions()
{
    // Vérifie les collisions entre l'oiseau et les tuyaux, ainsi que l'oiseau et le sol
    return collisionManager.checkBirdPipeCollision(bird, pipeManager) ||
           collisionManager.checkBirdGroundCollision(bird);
}

void Game::render()
{
    window.clear();
    background.render(window);
    pipeManager.render(window);
    bird.render(window);
    score.render(window);

    if (gameState == GameState::GameOver)
    {
        renderGameOver();
    }

    window.display();
}

void Game::restart()
{
    gameState = GameState::Ready;
    bird.reset();
    pipeManager.reset();
    score.resetScore();
}

void Game::renderGameOver()
{
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/OpenSans-Regular.ttf"))  // Assure-toi d'avoir une police
    {
        std::cerr << "Erreur: Impossible de charger la police" << std::endl;
        return;
    }
    sf::Text gameOverText("Game Over", font, 50);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2, 200);
    window.draw(gameOverText);
}

