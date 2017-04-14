Skarlaki I/O par Skalarki Electronics Ltd
=========================================

Introduction
------------

Le logiciel Skalarki I/O est un software servant également de drivers
pour les différents composants fabriqués par
[Skalarki](http://skalarki-electronics.eu). Ces derniers permettent de
connecter des éléments matériels d'un simulateur de cockpit d'A320 à un
logiciel d'interfaçage comme JeeHell FMGS, ou directement dans des
simulateurs, comme par exemple Project Magenta.


Connectivité avec FMGS
----------------------

À l'allumage, Skarlaki offre dans son interface un panel où l'on peut
trouver la liste des composants reconnus, avec un indicateur lorsque
ceux-ci sont connectés.

![Skalarki IO](skalarki_main.png)

Pour configurer Skalarki, il est tout d'abord nécessaire de quitter le
mode SDK, si celui-ci est actif. Ensuite, le bouton **Settings...**
permet d'ouvrir la fenêtre de configuration de Skalarki. Cela permet de
dégriser le panel

![Skalarki Settings](skalarki.png)

Ici, la sélection du module JeeHell FMGS coule de source. Cela dégrise
le panel **SKALARKI Server Settings**. Celui-ci permet la configuration
du multi-postes en utilisant le logiciel FMGS. En effet : Skalarki I/O
va envoyer ses données à un serveur d'un module de FMGS (dans cet
exemple de configuration), appelé Hardware Connect.

Nous avons découvert cela avec un `netstat` lancé après la suite de
FMGS. Le module Hardware Connect est en fait en écoute sur le port
25253, et en observant la configuration de Skalarki I/O, il se trouve
que c'est avec lui qu'il communique.

Conclusion
----------

Si Skarlaki offre une solution pour ses produits, celle-ci n'est pas
forcément celle qui nous convient. D'ailleurs, aucune certitude quant à
l'état des périphériques lorsque survient un problème d'entrée/sortie,
et que le périphérique doit être réinitialisé.