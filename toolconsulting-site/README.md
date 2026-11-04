# Site web TOOL Consulting (refonte 2026)

Site statique, sans WordPress ni base de données : HTML, CSS et un petit script JavaScript, sans framework ni dépendance externe. Pages légères (environ 300 Ko pour tout le site), polices hébergées localement, aucun traceur tiers.

## Arborescence

| Dossier | Rôle |
|---|---|
| `src/pages/` | contenu de chaque page (métadonnées en tête, puis HTML) |
| `src/partials/` | en-tête (`head.html`) et pied de page (`foot.html`) communs |
| `src/icons/` | icônes Lucide (licence ISC) |
| `public/` | site prêt à publier (généré) + feuille de style, script, images, polices |
| `build.py` | assemble `src/` vers `public/` |

## Modifier le site

1. Modifier le texte dans `src/pages/*.html` (ou le style dans `public/assets/css/style.css`).
2. Lancer `python3 build.py` (Python 3, aucune dépendance) : il génère `public/<page>/index.html`, le `sitemap.xml`, insère les icônes (`{{icon:nom}}`) et applique la typographie française.
3. Prévisualiser : `cd public && python3 -m http.server 8000`, puis ouvrir http://localhost:8000.

## Mettre en ligne

Le dossier `public/` se publie tel quel sur n'importe quel hébergement statique :

- **Azure Static Web Apps** (recommandé, cohérent avec l'écosystème Microsoft) : `staticwebapp.config.json` contient les redirections 301 des anciennes URL WordPress, la page 404 et les en-têtes de sécurité et de cache.
- **Netlify / Cloudflare Pages** : `_redirects` et `_headers` font la même chose.
- **Hébergement mutualisé actuel** : copier `public/` à la racine (les redirections sont alors à reporter dans `.htaccess`).

Les URL `/a-propos/`, `/services/` et `/contact/` sont conservées ; les anciennes pages produits redirigent vers les ancres de `/solutions/`.

## Formulaire de contact

Sans configuration, le formulaire ouvre la messagerie de l'internaute avec le message prérempli vers info@toolconsulting.com. Pour un envoi direct, renseigner `data-endpoint` dans `src/pages/contact.html` avec l'URL d'un service qui accepte du JSON (flux Power Automate « Lors de la réception d'une requête HTTP », Azure Function, Formspree…).

## Charte

Couleurs, polices et règles de la charte TOOL Consulting : marine #1D4D77 pour la structure, orange #F39229 / #DF7F2A pour les accents, texte anthracite #3A3A3C ; Cambria et Calibri (avec Caladea et Carlito, mêmes chasses, licence SIL OFL, en repli web) ; icônes Lucide blanches dans une pastille marine ou bleue ; logo uniquement sur fond blanc ; aucune photo d'illustration ni emoji.
