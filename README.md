# ZOOLAND

## Simulateur de Zoo en C++

Ce projet consiste à créer un jeu de simulation, en *langage de programmation **C++***, permettant la gestion d'un zoo en tour par tour. 

Ce simulateur de Zoo revisité est inspiré du célèbre jeu ***"ZOOTYCOON"***


## Comment utiliser le programme ?
Une fois le programme téléchargé, ouvrez celui-ci avec votre invite de commande.

Puis, lancez la commande suivante qui permet de compiler tous les fichiers du programme :
 ```console 
 g++ .\includes\*.h *.cpp -o main 
 ```
 
Puis lancez l'exécutable du programme :
```
 .\main.exe 
 ```
 
 
## Consignes de l'exercice 
Notre simulateur de Zoo doit se baser sur les données ci-dessous :
***[https://docs.google.com/spreadsheets/d/1LHXIDm7j5kan1B9-40uPYAEBp8GY4cxpyNoVweuNUr0/edit?usp=sharing](https://docs.google.com/spreadsheets/d/1LHXIDm7j5kan1B9-40uPYAEBp8GY4cxpyNoVweuNUr0/edit?usp=sharing)***

De plus, notre programme doit mettre en place plusieurs éléments :
 - Un scénario avec : 2 couples de tigre, 2 couples d'aigle, 1 coq, et 10  
   poules sur "10 ANS" ; 
 - Des Classes (Animaux, tigre, poules, zoo etc..) doivent être présentes dans notre code ; 
 - La gestion de 4 actions :
	 - Acheter/Vendre un animal ;
	 - Acheter de la nourriture pour les animaux ;
	 - Acheter/Vendre les enclos des animaux ;
 - Un déroulement en tour par tour, avec une durée de 1 mois par tour.
 - La gestion de 10 événements :
    - Grossesses des femelles ;
    - Naissance ;
    - Mort Infantile ;
    - Fin de vie ;
    - Surpopulation dans les enclos;
    - Maladie;
	 - Exceptionnels par mois :
	      - Incendie ;
	      - Vol ;
	      - Nuisibles ;
	      - Viande avariée.
