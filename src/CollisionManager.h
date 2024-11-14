#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Bird.h"
#include "PipeManager.h"

class CollisionManager
{
public:
    CollisionManager();                                    // Constructeur par défaut

    bool checkBirdPipeCollision(const Bird &bird, const PipeManager &pipeManager) const;
    // Vérifie les collisions entre l'oiseau et tous les tuyaux

    bool checkBirdGroundCollision(const Bird &bird) const; // Vérifie si l'oiseau touche le sol
};

#endif // COLLISIONMANAGER_H
