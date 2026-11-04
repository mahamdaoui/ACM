/* TOOL Consulting - script du site (aucune dépendance) */
(function () {
  "use strict";
  document.documentElement.classList.remove("no-js");

  // Menu mobile
  var nav = document.querySelector(".nav");
  var bascule = document.querySelector(".nav__bascule");
  if (nav && bascule) {
    bascule.addEventListener("click", function () {
      var ouvert = nav.classList.toggle("nav--ouverte");
      bascule.setAttribute("aria-expanded", ouvert ? "true" : "false");
      bascule.setAttribute("aria-label", ouvert ? "Fermer le menu" : "Ouvrir le menu");
    });
    document.addEventListener("keydown", function (e) {
      if (e.key === "Escape" && nav.classList.contains("nav--ouverte")) {
        nav.classList.remove("nav--ouverte");
        bascule.setAttribute("aria-expanded", "false");
        bascule.focus();
      }
    });
  }

  // Apparition au défilement
  var blocs = document.querySelectorAll(".apparait");
  if ("IntersectionObserver" in window && !window.matchMedia("(prefers-reduced-motion: reduce)").matches) {
    var obs = new IntersectionObserver(function (entrees) {
      entrees.forEach(function (e) {
        if (e.isIntersecting) { e.target.classList.add("visible"); obs.unobserve(e.target); }
      });
    }, { rootMargin: "0px 0px -8% 0px" });
    blocs.forEach(function (b) { obs.observe(b); });
  } else {
    blocs.forEach(function (b) { b.classList.add("visible"); });
  }

  // Année du pied de page
  var annee = document.getElementById("annee");
  if (annee) annee.textContent = new Date().getFullYear();

  // Formulaire de contact
  // Si l'attribut data-endpoint est renseigné (Formspree, Azure Function, Power Automate...), envoi en JSON.
  // Sinon, ouverture de la messagerie de l'internaute avec le message prérempli.
  var form = document.getElementById("formulaire-contact");
  if (form) {
    var etat = form.querySelector(".formulaire__etat");
    var afficher = function (texte) { etat.textContent = texte; etat.classList.add("visible"); };
    form.addEventListener("submit", function (e) {
      e.preventDefault();
      if (!form.reportValidity()) return;
      var d = new FormData(form);
      if (d.get("site_web")) return; // pot de miel anti-robots
      var endpoint = form.getAttribute("data-endpoint");
      if (endpoint) {
        var bouton = form.querySelector("button[type=submit]");
        bouton.disabled = true;
        fetch(endpoint, {
          method: "POST",
          headers: { "Content-Type": "application/json", "Accept": "application/json" },
          body: JSON.stringify(Object.fromEntries(d.entries()))
        }).then(function (r) {
          if (!r.ok) throw new Error(r.status);
          form.reset();
          afficher("Merci, votre message est bien envoyé. Nous vous répondons sous 48 heures ouvrées.");
        }).catch(function () {
          afficher("L’envoi n’a pas abouti. Écrivez-nous directement à info@toolconsulting.com.");
        }).finally(function () { bouton.disabled = false; });
        return;
      }
      var corps = [
        "Nom : " + d.get("nom"),
        "Société : " + (d.get("societe") || "-"),
        "Téléphone : " + (d.get("telephone") || "-"),
        "Courriel : " + d.get("email"),
        "",
        d.get("message")
      ].join("\n");
      window.location.href = "mailto:info@toolconsulting.com?subject=" +
        encodeURIComponent("[Site web] " + d.get("sujet")) + "&body=" + encodeURIComponent(corps);
      afficher("Votre messagerie s’ouvre avec le message prérempli : il ne reste qu’à l’envoyer.");
    });
  }
})();
