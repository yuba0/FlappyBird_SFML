#ifndef CONFIG_H
#define CONFIG_H

namespace Config
{
    // Fenêtre du jeu
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    const int FRAME_RATE = 60;

    // Paramètres de l'oiseau
    const float BIRD_START_X = 200.0f;         // Position initiale en X
    const float BIRD_START_Y = 300.0f;         // Position initiale en Y
    const float GRAVITY = 0.5f;                // Gravité appliquée à l'oiseau
    const float JUMP_STRENGTH = -8.0f;         // Force de saut de l'oiseau

    // Paramètres des tuyaux
    const int PIPE_SPAWN_INTERVAL = 200;       // Intervalle de création de tuyaux (en pixels)
    const float PIPE_SCROLL_SPEED = -5.0f;     // Vitesse de défilement des tuyaux

    // Paramètres du sol
    const float GROUND_HEIGHT = 500.0f;        // Hauteur du sol par rapport au bas de l'écran
    const float GROUND_SCROLL_SPEED = -2.0f;   // Vitesse de défilement du sol

    // Paramètres du score
    const int SCORE_FONT_SIZE = 30;            // Taille de la police pour le score
    const int HIGH_SCORE_FONT_SIZE = 20;       // Taille de la police pour le meilleur score

    // Autres configurations
    const float PIPE_GAP = 150.0f;             // Espace entre les tuyaux supérieur et inférieur
}

#endif // CONFIG_H
