# 🌌 fract_ol

**fract_ol** est un projet graphique de l'école 42 qui explore les fractales en utilisant la **MiniLibX**, une bibliothèque graphique légère.  
Il permet la visualisation interactive de fractales telles que Mandelbrot, Julia, et bien d'autres variantes.

---

![Fractol Screenshot](https://github.com/user-attachments/assets/8da18bd0-3fae-49d0-adb8-8b2196388b62)

---

## 📦 Objectifs du projet

- Générer et afficher différentes fractales mathématiques.
- Utiliser la bibliothèque **MiniLibX** (macOS/Linux).
- Implémenter un système de zoom/dézoom et de déplacement fluide.
- Ajouter des interactions clavier et souris.
- Bonus : palettes dynamiques, nouvelles formules, etc.

---

## 🧠 Fractales supportées

- Mandelbrot  
- Julia (modifiable dynamiquement à la souris)  
- Burning Ship  
- Autres variantes selon les bonus  

---

## 🎮 Contrôles

| Action                             | Touche / Souris               |
|------------------------------------|-------------------------------|
| Zoom avant/arrière                 | Molette souris / `+` / `-`    |
| Déplacement                        | Flèches / `W` `A` `S` `D`     |
| Changer palette de couleurs        | `TAB`                         |
| Réinitialiser la vue               | `R`                           |
| Quitter le programme               | `ESC`                         |
| Modifier les paramètres de Julia  | Clic gauche + déplacement souris |

---

## 🛠️ Compilation & Exécution

### Prérequis

- macOS ou Linux
- Make
- MiniLibX (fournie ou à installer selon la plateforme)
- GCC

### Compilation

```bash
make
