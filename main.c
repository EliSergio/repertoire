#include "proto.h"

void main(){
	int reponse = 0;

	do{
			options();

			printf("\nvous voulez continuez o/n\n\n");
			printf("pour oui appyuer 1 et 0 non\n");
			scanf("%d", &reponse);
			getchar();

	}while(reponse == 1);
}