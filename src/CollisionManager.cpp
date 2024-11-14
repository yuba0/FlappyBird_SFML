#include "CollisionManager.h"
#include "Bird.h"
#include "PipeManager.h"
#include <SFML/Graphics.hpp>

CollisionManager::CollisionManager()
{
    // Constructeur par défaut
}

bool CollisionManager::checkBirdPipeCollision(const Bird &bird, const PipeManager &pipeManager) const
{
    // Parcourt tous les tuyaux pour vérifier les collisions avec l'oiseau
    for (const auto &pipe : pipeManager.getPipes())
    {
        if (bird.getBounds().intersects(pipe.getTopBounds()) || bird.getBounds().intersects(pipe.getBottomBounds()))
        {
            return true;  // Collision détectée
        }
    }
    return false;  // Pas de collision
}

bool CollisionManager::checkBirdGroundCollision(const Bird &bird) const
{
    // Vérifie si l'oiseau a touché le sol
    return bird.getPosition().y >= 500;  // Ajuste la valeur selon la hauteur du sol
}
