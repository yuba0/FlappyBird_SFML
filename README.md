# FlappyBird-SFML

Jeu de Flappy Bird avec interface graphique en C++ utilisant SFML

## Description

Ce projet est une réplique du jeu Flappy Bird, développée en C++ avec la bibliothèque SFML. Le jeu simule le jeu original (sans audio) et l'objectif est de naviguer entre des tuyaux sans toucher les obstacles.

## Fonctionnalités

- Défilement de l'arrière-plan et du sol pour un effet de mouvement fluide.
- Contrôle de l'oiseau avec la touche `Espace` pour le faire sauter.
- Détection des collisions avec les tuyaux ou le sol, entraînant un Game Over.
- Système de score, comptabilisant le nombre de tuyaux franchis.
- Possibilité de redémarrer le jeu après un Game Over.

## Technologies Utilisées

- **Langage** : C++
- **Bibliothèque** : SFML (Simple and Fast Multimedia Library) pour l’interface graphique, la gestion des événements et le rendu.
- **Make** : Outil pour gérer la compilation du projet.

## Exemples de Captures d'Écran

![Screenshot 1](assets/screenshots/screenshot1.png)
![Screenshot 2](assets/screenshots/screenshot2.png)


## Installation

### Prérequis

- **Compilateur C++** compatible avec C++11.
- **SFML 2.5** : Téléchargez et installez la bibliothèque SFML en suivant les instructions sur le site officiel : [SFML Download](https://www.sfml-dev.org/download.php).

### Instructions de Compilation

1. **Clonez le dépôt GitHub** :

   ```bash
   git clone https://github.com/ton-utilisateur/FlappyBird-SFML.git
   cd FlappyBird-SFML
