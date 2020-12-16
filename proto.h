#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Personne{
	int id;
	int numero;
	char adresse_mail[50];
	char nom[50];
	char prenom[50];
}Individu;

Individu pers;


int rech(int id_chercher);
void ajouter();
void recherche();
void supprimer();
void modifier();
void affichage();
void options();
