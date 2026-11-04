#!/usr/bin/env python3
"""Assemble le site TOOL Consulting : src/pages/*.html -> public/<slug>/index.html.

Aucune dépendance. Usage : python3 build.py
- En-tête et pied de page communs : src/partials/head.html et foot.html
- Métadonnées en tête de chaque page, dans un commentaire <!-- cle: valeur -->
- {{icon:nom}} insère l'icône Lucide src/icons/nom.svg
- Typographie française appliquée au texte : espace fine insécable avant ; ! ? et insécable avant : et dans « »
"""
import json
import re
import time
from pathlib import Path

RACINE = Path(__file__).resolve().parent
SRC = RACINE / "src"
PUBLIC = RACINE / "public"
SITE = "https://toolconsulting.com"
NBSP, NNBSP = " ", " "


def icone(nom: str) -> str:
    svg = (SRC / "icons" / f"{nom}.svg").read_text(encoding="utf-8")
    svg = re.sub(r"\s*\n\s*", " ", svg).strip()
    svg = re.sub(r'\s(width|height)="24"', "", svg)
    return svg.replace("<svg", '<svg aria-hidden="true" focusable="false"', 1)


def typo_francaise(html: str) -> str:
    """Corrige les espaces du texte visible, sans toucher aux balises, scripts ni styles."""
    morceaux = re.split(r"(<script.*?</script>|<style.*?</style>|<[^>]+>)", html, flags=re.S)
    for i, m in enumerate(morceaux):
        if not m or m.startswith("<"):
            continue
        m = m.replace("'", "’")
        m = re.sub(r"[  ]+([;!?])", NNBSP + r"\1", m)
        m = re.sub(r"[  ]+:(?=\s|$)", NBSP + ":", m)
        m = re.sub(r"«[  ]*", "«" + NBSP, m)
        m = re.sub(r"[  ]*»", NBSP + "»", m)
        m = re.sub(r"(\d) (\d{3})\b", r"\1" + NNBSP + r"\2", m)
        morceaux[i] = m
    return "".join(morceaux)


def lire_page(chemin: Path):
    texte = chemin.read_text(encoding="utf-8")
    entete = re.match(r"\s*<!--(.*?)-->", texte, flags=re.S)
    meta = {}
    for ligne in entete.group(1).strip().splitlines():
        cle, _, valeur = ligne.partition(":")
        meta[cle.strip()] = valeur.strip()
    return meta, texte[entete.end():]


def construire():
    version = time.strftime("%Y%m%d%H%M")
    head = (SRC / "partials" / "head.html").read_text(encoding="utf-8")
    foot = (SRC / "partials" / "foot.html").read_text(encoding="utf-8")
    plan = []
    for chemin in sorted((SRC / "pages").glob("*.html")):
        meta, corps = lire_page(chemin)
        slug = meta["slug"]
        url = SITE + ("/" if slug == "index" else f"/{slug}/")
        jsonld = ""
        if meta.get("jsonld") == "organisation":
            jsonld = '<script type="application/ld+json">' + json.dumps({
                "@context": "https://schema.org",
                "@type": "ProfessionalService",
                "name": "TOOL Consulting",
                "url": SITE + "/",
                "logo": SITE + "/assets/img/logo-tool-consulting@2x.png",
                "email": "info@toolconsulting.com",
                "telephone": "+212522589795",
                "address": {
                    "@type": "PostalAddress",
                    "streetAddress": "274, lotissement Lina, Plateau, 2e étage, Sidi Maârouf",
                    "addressLocality": "Casablanca",
                    "addressCountry": "MA",
                },
                "areaServed": ["MA", "FR", "Afrique"],
                "sameAs": ["https://www.linkedin.com/company/tool-consulting/"],
            }, ensure_ascii=False, separators=(",", ":")) + "</script>"
        page = head + corps + foot
        page = page.replace("{{titre}}", meta["titre"]).replace("{{description}}", meta["description"])
        page = page.replace("{{url}}", url).replace("{{version}}", version).replace("{{jsonld}}", jsonld)
        page = page.replace("{{pied_classe}}", " pied--colle" if meta.get("pied") == "colle" else "")
        page = re.sub(r"\{\{courant:([\w-]+)\}\}", lambda m: ' aria-current="page"' if m.group(1) == slug else "", page)
        page = re.sub(r"\{\{icon:([\w-]+)\}\}", lambda m: icone(m.group(1)), page)
        page = typo_francaise(page)
        if slug == "404":
            cible = PUBLIC / "404.html"
        elif slug == "index":
            cible = PUBLIC / "index.html"
        else:
            cible = PUBLIC / slug / "index.html"
            plan.append(url)
        if slug == "index":
            plan.insert(0, url)
        cible.parent.mkdir(parents=True, exist_ok=True)
        cible.write_text(page, encoding="utf-8")
        print("écrit", cible.relative_to(RACINE))

    jour = time.strftime("%Y-%m-%d")
    urls = "".join(f"  <url><loc>{u}</loc><lastmod>{jour}</lastmod></url>\n" for u in plan)
    (PUBLIC / "sitemap.xml").write_text(
        '<?xml version="1.0" encoding="UTF-8"?>\n'
        '<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">\n' + urls + "</urlset>\n", encoding="utf-8")
    print("écrit public/sitemap.xml")


if __name__ == "__main__":
    construire()
