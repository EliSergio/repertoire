#include "proto.h"

int rech(int id_chercher){
	FILE *doc = NULL;

		doc = fopen("test.txt", "r");

	if(doc == NULL){
		printf("l'ouverture a echoue!!\n");
		exit(0);
	}

	do{
		fscanf(doc, "%d %d %s %s %s ", &pers.id, &pers.numero, pers.nom, pers.prenom, pers.adresse_mail);
		if(pers.id == id_chercher){
			fclose(doc);
			return 1;
		}
	}while(!feof(doc));

	fclose(doc);
	
	return -1;
}

/*------------------------------------------------------------------------------*/

void ajouter(){
	int nouveau_id;
	FILE *doc = NULL;

		doc = fopen("test.txt", "a");

	if(doc == NULL){
		printf("l'ouverture a echoue!!\n");
		exit(0);
	}

	printf("entrer l'id de la personne\n");
	scanf("%d", &nouveau_id);
	fflush(stdin);

	while(rech(nouveau_id) == 1){
		printf("cette id existe deja\n veuillez entrer un nouveau\n");
		scanf("%d", &nouveau_id);
	}

	pers.id = nouveau_id;

	printf("entrer le numero\n");
	scanf("%d", &pers.numero);
	printf("entrer son nom\n");
	scanf("%s", pers.nom);
	printf("entrer son prenom\n");
	scanf("%s", pers.prenom);
	printf("entrer l'adresse email\n");
	scanf("%s", pers.adresse_mail);

	fprintf(doc, "%d %d %s %s %s \n", pers.id, pers.numero, pers.nom, pers.prenom, pers.adresse_mail);

	fclose(doc);
}

/*------------------------------------------------------------------------------*/

void recherche(){
	int id_chercher;

	printf("entrer l'id de la personne a rechercher!!\n");
	scanf("%d", &id_chercher);
	getchar();

	FILE *doc = NULL;
		doc = fopen("test.txt", "r");

	if(doc == NULL){
		printf("l'ouverture a echoue!!\n");
		exit(0);
	}

	do{
		fscanf(doc, "%d %d %s %s %s ", &pers.id, &pers.numero, pers.nom, pers.prenom, pers.adresse_mail);

		if(id_chercher == pers.id){
			printf("***voici les renseignement sur cette personne***\n");
			printf("ID : %d\n", pers.id);
			printf("NUMERO : %d\n", pers.numero);
			printf("NOM : %s\n", pers.nom);
			printf("PRENOM : %s\n", pers.prenom);
			printf("EMAIL : %s\n", pers.adresse_mail);
		}

	}while(!feof(doc));

	fclose(doc);
}

/*------------------------------------------------------------------------------*/

void supprimer(){
	int id_chercher;
	char reponse;

	printf("entrer l'id de la personne a supprimer\n");
	scanf("%d", &id_chercher);
	fflush(stdin);

	if(rech(id_chercher) == 1){
		printf("vous voulez vraiment le supprimer o/n\n");
		scanf("%c", &reponse);
		fflush(stdin);

		if(reponse == 'o' || reponse == 'O'){
			FILE *doc, *nouveau_doc = NULL;

			doc = fopen("test.txt", "r");
			nouveau_doc = fopen("nouveau.txt", "a");

				if(doc == NULL || nouveau_doc == NULL){
					printf("l'ouverture a echoue!!\n");
					exit(0);
				}

			do{
				fscanf(doc, "%d %d %s %s %s ", &pers.id, &pers.numero, pers.adresse_mail, pers.nom, pers.prenom);

				if(id_chercher != pers.id){
					fprintf(nouveau_doc, "%d %d %s %s %s \n", pers.id, pers.numero, pers.adresse_mail, pers.nom, pers.prenom);
				}
			}while(!feof(doc));
			
			fclose(doc);
			fclose(nouveau_doc);
			remove("test.txt");
			rename("nouveau.txt", "test.txt");

			printf("suppession avec succes \n");
		}
	}

	else{
		printf("ce id n'existe pas!!\n");
	}

}

/*------------------------------------------------------------------------------*/

void modifier(){

	int id_chercher;
	char reponse;

	printf("entrer l'id de la personne a modifier\n");
	scanf("%d", &id_chercher);
	fflush(stdin);

	if(rech(id_chercher) == 1){
		printf("voulez vous vraiment le modifier o/n\n");
		scanf("%c", &reponse);
		fflush(stdin);

		if(reponse == 'o' || reponse == 'O'){
			FILE *doc, *nouveau_doc = NULL;
			doc = fopen("test.txt", "r");
			nouveau_doc = fopen("nouveau.txt", "a");


	if(doc == NULL || nouveau_doc == NULL){
		printf("l'ouverture a echoue!!\n");
		exit(0);
	}

			do{
				fscanf(doc, "%d %d %s %s %s ", &pers.id, &pers.numero, pers.adresse_mail, pers.nom, pers.prenom);

				if(id_chercher == pers.id){
					pers.id = id_chercher;

					printf("Entrer nom\n");
					scanf("%s", pers.nom);
					printf("Entrer prenom\n");
					scanf("%s", pers.prenom);
					printf("Entrer le numero\n");
					scanf("%d", &pers.numero);
					printf("Entrer l'email\n");
					scanf("%s", pers.adresse_mail);
				}
				fprintf(nouveau_doc, "%d %d %s %s %s \n", pers.id, pers.numero, pers.adresse_mail, pers.nom, pers.prenom);

			}while(!feof(doc));

			fclose(doc);
			fclose(nouveau_doc);
			remove("test.txt");
			rename("nouveau.txt", "test.txt");
			printf("modification avec succes \n");
		}
		else
			printf("la modification a ete annulee\n");
	}
	else
		printf("ce id n'existe pas\n");
}

/*------------------------------------------------------------------------------*/

void affichage(){
	FILE *doc = NULL;

	doc = fopen("test.txt", "r");

	if(doc == NULL){
		printf("l'ouverture a echoue!!\n");
		exit(0);
	}

	printf("\tvoici la liste des personnes\n");

	do{
		fscanf(doc, "%d %d %s %s %s ", &pers.id, &pers.numero, pers.adresse_mail, pers.nom, pers.prenom);
			printf("*---------------------*\n");
			printf("ID : %d\n", pers.id);
			printf("NOM : %s\n", pers.nom);
			printf("PRENOM : %s\n", pers.prenom);
			printf("NUMERO : %d\n", pers.numero);
			printf("EMAIL : %s\n", pers.adresse_mail);
			printf("*---------------------*\n");
	}while(!feof(doc));

	fclose(doc);

}

/*------------------------------------------------------------------------------*/

void options(){

		int choix;

			system("cls");

			printf("***BIENVENUE DANS UN REPERTOIRE***\n");
			printf("\t-----MENU-----\n");

			printf("1.Ajouter une personne\n");
			printf("2.Modifier une personne\n");
			printf("3.Rechercher une personne\n");
			printf("4.supprimer une personne\n");
			printf("5.Afficher toute les peronnes\n");
			printf("6.quitter\n");

		while(choix < 1 || choix > 6){
			printf("votre choix?\n");
			scanf("%d", &choix);
		}

		switch(choix){
			case 1:
				ajouter();
				break;

			case 2:
				modifier();
				break;

			case 3:
				recherche();
				break;

			case 4:
				supprimer();
				break;

			case 5:
				affichage();
				break;

			case 6:
				exit(0);
		}
}


