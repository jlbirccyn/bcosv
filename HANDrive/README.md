# HANDrive

système de conduite manuelle pour personnes à mobilité réduite 
(n'ayant pas l'usage des jambes/pieds)
accelérateur + frein


## contexte

lors de l'open camp OSV, le propriétaire de l'OSVéhicle est une association / collectivité, 
la voiture est mise en autopartage.

## problématique

lorsqu'une PMR souhaite conduire de façon autonome un véhicule partagé, 
le système de conduite standard n'est pas adapté 
aux conditions nécessaires requises par la personnes (plusieurs cas possible : paraplegique, ou amputé d'un bras gauche, par exemple)

cahier des charges : 
- l'utilisateur est propriétaire du système d'accélération / freinage 
(évite les problemes de dégradations / entretients, et du non investissement d'une collectivité du systeme d'accéleration pour l'ensemble de la flotte / du parc)
- l'utilisateur apporte avec lui le systeme d'accélération lorsqu'il souhaite utiliser n'importe quel véhicule en autopartage.
- une OSV à un conneteur au niveau du volant (ou du tableau de bord, ou de la proximité de la colonne de direction), qui permet de brancher le systeme d'acceleration
- une OSV à un interupteur d'activation / desactivation du systeme d'accelération
- on ajoute à une OSV un controleur / calculateur (arduino) pour recuperer l'info d'un potentiometre et l'envoyer à l'OSV














contraintes/limitations pour CampOSV : 
en 3 jours, on se limite à la fabrication du systeme d'accélération, 
le frein manuel etant puremment mécanique, 
et le matériel disponible pour la fabrication n'etant pas disponible sur l'événement, 
cette partie sera réporrté à un autre moment.
pour ce qui est de la partie mécanique du systeme d'accélaration (le cercle en métal), 
n'ayant pas sur place le matériel nécessaire à la fabrication, nous nous limitons à la partie éléctronique







## législation

pour ce type d'aide technique à la conduite, la PMR doit avoir un permis de conduire adapté à cette aide technique (et donc passer une visite médicale dans une prefecture)
(10 changment de vitesse adapté) <--juridique / tehnique --> (boite automatique)
(20 mécanisme de freinage adapté) <--- juridique / tehnique --> (frein mécanique)
(25 mécanisme acélération adapté) <-- juridique / tehnique --> (accélérateur)

la législation en terme d'homologation du matériel : 
- frein doit etre mécanique (pas de panne possible pour cet élément de sécurité)
- l'accélérateur doit etre mécanique ou éléctronique, car en cas de panne, le véhicule ralenti tout seul.
il y a une homologation a passer (se renseigner concretement)


évolution possible : 
- faire une poignée de volant / commodo / télécommande , avec des interrupteurs qui commandent les cligniotants, le klaxon, ou d'autres fonctions du véhicule.

# Conception du système

Du point de vue du conducteur, le système est donc formé de la pédale d'accélérateur, d'une manette remplissant le même rôle mais pour la main, d'un bouton permettant de passer d'un mode de conduite par la pédale à un mode de conduite par la manette et d'un témoin affichant le mode courant. Au démarrage du système, le mode actif est le mode de conduite par la pédale.

Selon les informations trouvées dans la documentation, la pédale envoie au calculateur une tension analogique délivrée par un capteur de type potentiomètre. Il s'avère que le capteur est un capteur à effet hall qui délivre (peut-être) une tension comprise entre 0V et 12V.

Le système est destiné à être inséré entre la pédale d'accélérateur et le calculateur.

En entrée, le système reçoit
- la position de la pédale sous la forme d'une tension analogique. 
- la position de la manette (potentiomètre) sous la forme d'une tension analogique
- la position on ou off du bouton poussoir de changement de mode.
- 
En sortie, le système 
- construit une tension analogique qui recopie la tension d'entrée de la pédale ou la tension d'entrée de la manette selon le mode.
- pilote l'allumage du témoin selon le mode.

## Electronique

HANDrive est construit autour d'un Arduino Uno. Une électronique additionnelle est nécessaire pour :
- adapter le niveau d'entrée de la pédale afin qu'il puisse être lu par l'Arduino
- construite une tension analogique en sortie
- adapter cette tension analogique, qui est comprise entre 0 et 5V, vers une tension analogique entre 0 et 12V

