#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


typedef struct no
{
	char nome[15];
	struct no *prox;
	
}Tno;

typedef Tno *Tlista;

/*PROTÓTIPOS*/

Tlista busca_in(Tlista L,char *palavra);
Tlista busca_rem(Tlista L[],char *palavra);
int chave(char *palvra);
int insere_in(Tlista L[10],char *palavra);
int rem(Tlista hash[10],char *palavra);
void inicializar(Tlista L[10]);
int alt(char *velho,char *novo,Tlista hash[10]);
int menu();
void mostra(Tlista hash[10]);
void mostra2(Tlista hash[],int lis);


Tlista busca_in(Tlista L,char *nome)
{	
	Tlista aux1,aux2;
	aux1=L;
	aux2=L->prox;
	
	while(aux2)
	{	
		
		if(strcmp(nome,aux2->nome)<0)
		{
	
			return aux1;
		}
		aux1=aux1->prox;
		aux2=aux2->prox;
	}
	
	return aux1;
}

Tlista busca_rem(Tlista hash[10],char *nome)
{	

	Tlista aux,ant;
	int ch=chave(nome);
	int i;
	
	
	
	Tlista aux1,aux2;
	aux1=hash[ch];
	aux2=hash[ch]->prox;
	
	if(hash[ch]!=NULL)
	{
		
		if(strcmp(nome,hash[ch]->nome)==0)
		{	
		
			return hash[ch];
		}
		else
		{
		
			while(aux2)
			{
				if(strcmp(nome,aux2->nome)==0)
				{
					return aux1;
				}
				aux1=aux1->prox;
				aux2=aux2->prox;
			}
		
		}
	}
	else
	return NULL;
}


int alt(char *velho,char *novo,Tlista hash[10])
{
	Tlista aux;
	int ch=chave(velho);	
	aux=hash[ch];
	
	
	if(aux!=NULL)
	{
		
		while(aux)
		{
			if(strcmp(aux->nome,velho)==0)
			{
				rem(hash,velho);
				insere_in(hash,novo);
				return 1;
			}
			else
			{
				return 0;
			}
		}
	
	}
	return 0;	
}


int chave(char *nome)
{	
	int resul;
	int cont=0;
	int i;
	
	resul=strlen(nome);
	
	for(i=0;i<resul;i++)
	{
		cont=nome[i]+cont;
	}
	
	return cont%10;
}


int menu()
{	
	int op;
	
	printf("digite(1)para inserir\n");
	printf("digite(2)para remover\n");
	printf("digite(3)para alterar\n");
	printf("digite(4)para buscar\n");
	printf("digite(5)para exibir uma unica lista\n");
	printf("digite(6)para exibir todas as listas\n");
	printf("digite(7)para sair\n");
	
		
	scanf("%d",&op);

	return op;

}



int rem(Tlista hash[10],char *palavra)
{
	Tlista aux,ant,aux2;
	int ch;
	
	ch=chave(palavra);
	
	aux2=hash[ch];
		
		if(hash[ch]!=NULL)
		{

			if(strcmp(hash[ch]->nome,palavra)==0)
			{	
				
				ant=hash[ch];
				hash[ch]=hash[ch]->prox;
				free(ant);
				return 1;
		
			}
			else
			{	aux=busca_rem(hash,palavra);
				if(aux->prox!=NULL)
				{
				ant=aux->prox;
				aux->prox=aux->prox->prox;
				free(ant);
				return 1;
				}
			
						
			}
		}
return 0;
}

int insere_in(Tlista hash[10],char *palavra)
{	
	Tlista novo=(Tlista)(malloc(sizeof(Tno)));
	strcpy(	novo->nome,palavra);
	novo->prox=NULL;
	
	Tlista aux,ant,aux2;
	int ch;
	char nomeAux[15];
	
	ch=chave(palavra);
	
	aux2=hash[ch];
	
	if(aux2!=NULL)
		while(aux2)
		{
			if(strcmp(aux2->nome,palavra)==0)
			{
				return -1;
			}
			aux2=aux2->prox;
		}
	
	
	if(hash[ch]==NULL)
	{
		hash[ch]=novo;
		novo->prox=NULL;
		aux=hash[ch];
		
	}
	else
	{		aux=hash[ch];
			if(strcmp(novo->nome,hash[ch]->nome)<0)
			{
				novo->prox=hash[ch];
				hash[ch]=novo;	
			}
			else
			{
				aux=busca_in(hash[ch],aux->nome);
				if(aux->prox==NULL)
				{
					aux->prox=novo;
					novo->prox=NULL;
				}
				else
				{
					ant=aux->prox;
					aux->prox=novo;
					novo->prox=ant;
				}
			}
			

		}
	return ch;		
	}



void inicializar(Tlista hash[10])
{	
	int i;
	
	for(i=0;i<10;i++)
	{
		hash[i]=NULL;
	
	}	
}


void mostra2(Tlista hash[],int lis)
{
		Tlista aux;
		aux=hash[lis];
		
		printf("elementos da lista %d\n",lis);
		
		while(aux)
		{	
			printf("%s\n",aux->nome);
			aux=aux->prox;
		}
	printf("%\n");
}	

	
void mostra(Tlista hash[10])
{	
	int i;
	Tlista aux;
	for(i=0;i<10;)
	{
		aux=hash[i];
		
		printf("elementos da lista %d\n\n",i);		
		while(aux)
		{	
			printf("%s\n",aux->nome);
			aux=aux->prox;
		}
		i++;
	}
	printf("\n\n\n");
		
}
		
void main()
{
	

int resul;
Tlista hash[10];
Tlista aux,aux2;
int opc;

int lis;
char palavra1[15];
char palavra2[15];
	
	
inicializar( hash);

do
{	
	opc=menu();
	system("cls");	
	switch(opc)
	{
		case 1:
			printf("digite a palavra que deseja inserir\n");
			scanf("%s",palavra1);
			
			fflush(stdin);
			resul=insere_in(hash,palavra1);
			
			if(resul==-1)
			{
				printf("esta palavra ja foi inserida\n\n");
			}
			else
			
			printf("palvra inserida na lista %d\n",resul);			
			break;
			
		case 2:
			printf("digite a palavra a ser removida\n");
			scanf("%s",palavra1);
			
			resul=rem(hash,palavra1);
			if(resul==0)
			{
				printf("nao foi possivel remover\n\n");
			}
			else
			{
				printf("a palavra fo removida\n\n");
			}
			break;
		
		case 3:
			printf("digite a palavra que deseja remover e a nova plavara\n");
			scanf("%s  %s",palavra1,palavra2);
			fflush(stdin);
			
			resul=alt(palavra1,palavra2,hash);
			if(resul==0)
			{
				printf("nao foi possivel alterar");
			}
			else
			{
				printf("elemento foi alterado ");
			}
			break;
			
		case 4:
			printf("digite a palavra que deseja buscar\n");
			scanf("%s",palavra1);
			fflush(stdin);
		
			aux=busca_rem(hash,palavra1);
			
			
			if(aux!=NULL)
			{
			
				if(strcmp(aux->nome,palavra1)==0)
				{
	
					printf("sua palavra esta na lista %d na posicao %p\n",chave(palavra1),aux);
				}
				else
				{	
					aux=aux->prox;
					if(strcmp(aux->nome,palavra1)==0)
					{
						printf("sua palavra esta na lista %d na posicao %p\n",chave(palavra1),aux);
					}
				}
			}
			else
			{
				printf("o elemento nao existe");
			}
	
			break;	
			
		case 5:
			printf("digite um numero entre 0 e 9 para esolher a lista que deseja exibir\n");
			scanf("%d",&lis);
			mostra2(hash,lis);
			break;
			
		case 6:
			mostra(hash);		
	}
	
	
}while(opc!=7);


}


