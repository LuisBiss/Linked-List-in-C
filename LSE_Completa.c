#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(int argc, char *argv[]) 
{
	typedef struct 
	{
		int dado;
		struct no *prox;
	} no;
	
	no *lista, *p, *q;
	int esc, cont, pos,i;
	lista = NULL;
	
	printf("\n O que deseja fazer na Lista? \n 1. Inserir um dado � esquerda (�nicio da lista) \n 2. Fazer inser��o � direita (final da lista) \n 3. Fazer inser��o intermedi�ria \n 4. Sair do menu e ver a Lista \n", setlocale(LC_ALL,""));
	
	do {
		switch (esc) {	
		
		case 1:
			p = malloc (sizeof(no));
			printf("Digite o dado na lista: ");
			scanf("%i", &p ->dado);
			p -> prox = lista;
			lista = p;
			printf("\n O que deseja fazer na Lista? \n 1. Inserir um dado � esquerda (�nicio da lista) \n 2. Fazer inser��o � direita (final da lista) \n 3. Fazer inser��o intermedi�ria \n 4. Sair do menu e ver a Lista \n", setlocale(LC_ALL,""));
		break;

		case 2:
			if (lista == NULL) 
			{  // Check se a lista permite inser��o � direita
				p=malloc(sizeof(no)); 
				printf("Digite o dado na lista: ");
				scanf("%i", &p ->dado);
				lista = p;
				printf("O dado foi inserido a esquerda pois n�o tem dados suficientes na lista.");
			} else 
			{
				p = malloc(sizeof(no));
				printf("Digite o dado na lista: ");
				scanf("%i", &p -> dado);
				p -> prox = NULL; //final da lista
				q = lista;
				while (q-> prox!= NULL)
				{
					q = q->prox;
				}
				printf("ender�o entregue ao p: %i", q->prox, setlocale(LC_ALL,""));
				q->prox = p;
			};
			printf("\n O que deseja fazer na Lista? \n 1. Inserir um dado � esquerda (�nicio da lista) \n 2. Fazer inser��o � direita (final da lista) \n 3. Fazer inser��o intermedi�ria \n 4. Sair do menu e ver a Lista \n", setlocale(LC_ALL,""));
		break;
		
		case 3:
			if (lista == NULL) 
			{  // Check se a lista existe
				printf("sem dados na Lista. \n");
			} else
				{
					cont = 1;
					q = lista;
					while (q -> prox != NULL)
					{
						q = q->prox;
						cont++;
					}
					printf("Escreva em qual posi��o deseja fazer a inser��o %i \n", cont++);
					scanf("%i", &pos);
					
					if(pos > cont++ )
					{
						printf("posi��o inv�lida", setlocale(LC_ALL,""));
					} else
						{
							if(pos == cont++)
							{
								//Inser��o � direita para o dado no final da lista
								p = malloc(sizeof(no));
								printf("Digite o dado na lista: ");
								scanf("%i",&p->dado);
								p->prox = NULL;
								q = lista;
								while(q->prox != NULL)
								{
									q = q->prox;
								}
								q->prox = p;
							} else 
								{
									p = malloc(sizeof(no));
									printf("Digite o dado na lista: ");
									scanf("%i",&p->dado);
									q = lista;
									for(i = 0; i < pos - 2;i++)
									{
										q = q->prox;
									}
									p->prox = q->prox;
									q->prox = p;
								}
						}
				}
		printf("\n O que deseja fazer na Lista? \n 1. Inserir um dado � esquerda (�nicio da lista) \n 2. Fazer inser��o � direita (final da lista) \n 3. Fazer inser��o intermedi�ria \n 4. Sair do menu e ver a Lista \n", setlocale(LC_ALL,""));
		break;
		
		case 4:
		 return(0);
		};
		
		scanf("%i", &esc);
	} while (esc != 4);
	
	printf("Lista:\n");
	p = lista;
	while (p -> prox != NULL)
	{
	  printf("%i \n", p -> dado);
	  p = p -> prox;
	}; printf("%i \n", p -> dado);
};
