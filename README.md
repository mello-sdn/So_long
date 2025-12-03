# So_long
<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/so_longm.png" alt="So_long Badge"/>
</div>

## 📝 Résumé
L'objectif est de créer un petit jeu 2D où le joueur doit collecter tous les objets présents sur la carte avant de s'échapper par une sortie

**Objectifs principaux :**
- Apprendre les bases de la programmation graphique avec MiniLibX & Gestion des événements
- Implémenter un parsing
- Comprendre la gestion de sprites et textures
---

## 🎮 Theme du jeu (Jujutsu Kaisen)

<div align="center">
  <img width="1040" height="563" alt="2025-12-03 18_39_33-so_long (Ubuntu)" src="https://github.com/user-attachments/assets/728b90be-555b-4383-97da-4a94e08ec244" />
  <img width="1040" heig<img width="1760" height="720" alt="2025-12-03 18_42_22-so_long (Ubuntu)" src="https://github.com/user-attachments/assets/c647d1be-bbee-4abf-82e8-efb25d357629" />
</div>

## 🔧 Installation

### Cloner le projet
```bash
git clone https://github.com/mello-sdn/So_long.git
cd so_long
```

### Compilation
```bash
make
```
---

## 💻 Utilisation

### Lancer le jeu
```bash
# Avec une carte par défaut
./so_long maps/map.ber

```

### Contrôles
- **W** ou **↑** : Déplacer vers le haut
- **A** ou **←** : Déplacer vers la gauche
- **S** ou **↓** : Déplacer vers le bas
- **D** ou **→** : Déplacer vers la droite
- **ESC** : Quitter le jeu

### Objectif
1. Collecter tous les collectibles (Doigt de Sukuna) présents sur la carte
2. Atteindre la sortie (E) pour terminer le niveau
---

## 🗺️ Format de Carte (.ber)

### Composants de la Carte
```
1 = Mur
0 = Espace vide
C = Collectible
E = Sortie
P = Position de départ du joueur
```
---
### Règles de Validation
- La carte doit être rectangulaire
- La carte doit être entourée de murs (1)
- La carte doit contenir 1 sortie (E), au moins 1 collectible (C) et 1 position de départ (P)
- Il doit exister un chemin valide vers tous les collectibles et la sortie
- Extension du fichier : `.ber`

---

### Ressources
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [So_long Tester](https://github.com/augustobecker/so_long_tester)
- [Sprite Resources](https://itch.io/game-assets/free) ou s'aider de l'ia pour créer des assets personnalisés
---

---

## 💡 Conseils

- Bien faire attention si un collectible n'est pas accessible après le passage de Floodfill retourner une erreur
- Utilisez valgrind pour détecter les leaks : `valgrind --leak-check=full ./so_long maps/map.ber`
- Faire attention à la fermeture des FD : `valgrind --track-fds=yes./so_long maps/map.ber`
- Testez avec des cartes invalides pour vérifier vos erreurs

---

## ✔️ Note Finale
<img width="200" height="170" alt="2025-12-03 19_08_11-Intra Projects so_long – Brave" src="https://github.com/user-attachments/assets/1a945968-f47e-4d42-bbea-e8dfbd49b23a" />
<br>
