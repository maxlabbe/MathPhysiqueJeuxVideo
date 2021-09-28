# Construction d’un moteur physique de jeux vidéo - Phase 1

## Compiler et faire fonctionner le programme
### Sur Windows
#### Prérequis 
  - Microsoft Visual Studio 2019 / C++
#### Lancer le programme
  - Télécharger et décompresser le dossier du code
  - Depuis Visual Studio, "Ouvrir un projet ou une solution".
  - Sélectionner MPJV.sln
  - Depuis la barre en haut de la fenêtre de Visual Studio, faire "Générer" puis "Générer la solution"
  - Toujours depuis la barre, faire "Déboguer" puis "Démarrer le débogage" ou "Executer sans débogage"

## Actions possibles
A l'exécution, une console et une fenêtre doivent apparaître.
Depuis la fenêtre, plusieurs actions sont possibles : AZERTY(QWERTY)
  - Bouger la caméra :
    - Z(Q) -> Déplace la caméra vers l'avant
    - S(S) -> Déplace la caméra vers l'arrière
    - Q(A) -> Déplace la caméra vers la gauche
    - D(D= -> Déplace la caméra vers la droite
    - CTRL-Gauche -> Déplace la caméra vers le bas
    - Espace -> Déplace la caméra vers le haut
    - Déplacer la souris en faisant un clic droit permet de changer l'orientation de la caméra
  - Lancer un projectile :
    - Clic gauche -> Tir un projectile depuis la position de la caméra et avec une vitesse initiale pointant devant nous
    - J(J) -> Sélectionne le projectile léger
    - K(K) -> Sélectionne le projectile moyen 
    - L(L) -> Sélectionne le projectile lourd
