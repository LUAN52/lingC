# include<stdio.h>
# include<stdlib.h>

typedef struct no
{
	int numero;
	struct no *prox;
}Tno;

typedef Tno	*Tlista;
// prototipos

int quantidade(Tlista L,int valor);
int rem(Tlista *L,int valor,int tam);
int remover(Tlista*L,int valor);
int remo_pos(Tlista *L,int pos);
int insere(Tlista *L,int numero);
int escolha();
Tlista busca(Tlista L,int dado);
void exibir(Tlista L);
int alterar(Tlista *L,int antigo,int novo);


int quantidade(Tlista L,int valor)
{
	Tlista aux=L;
	int cont=0;
	
	while(aux)
	{
		if(aux->numero==valor)
		{
			cont++;
		}
		aux=aux->prox;
	}
	return cont;
}

int rem_pos(Tlista *L,int pos)
{	
	int i=2;
	int numero;
	Tlista aux;
	Tlista aux2;
	Tlista aux3;
	
	int cont;
		if(pos==1)
		{
			aux=*L;
			numero=aux->numero;
			*L=aux->prox;
			free(aux);	
				
		}
		else
		{
		aux=*L;
		aux2=aux->prox;
		
		while(i<pos)
		{	
			aux=aux->prox;
			aux2=aux2->prox;
			i++;
		}
			aux3=aux->prox;
			numero=aux3->numero;
			aux->prox=aux2->prox;
			free(aux3);		
		}
	return numero;
				 
}


int alterar(Tlista *L,int antigo,int novo)
{
	int cont;
	int i=0;
	int resul;
	Tlista aux;
	
	if((*L)==NULL)
	{
		return -1;
	}
	
	cont=quantidade(*L,antigo);
	if(cont>novo)
	{
		resul=rem(&(*L),antigo,novo);
		printf("%d\n\n",resul);
	}
		while(aux)
		{	
			if(aux->numero==antigo)
			{
				aux->numero=novo;
			}
			aux=aux->prox;
			i++;
		}
		
	return i;	
}

int insere(Tlista *L,int numero)
{
	Tlista novo=(Tlista)malloc(sizeof(Tno));
	int cont;
	
	if(numero<=0)
	{
		return -1;
	}
	
	cont=quantidade(*L,numero);
	if(cont<numero)
	{
		novo->numero=numero;
		novo->prox=*L;
		*L=novo;
		
		return 1;
	}
	else
	{
		return 0;
    }
}


int escolha()
{
	int op;

	printf("digite (1)para inserir\n");
	printf("digite (2) para remover\n");
	printf("digite (3)para remover em uma posicao\n");
	printf("digite (4)para alterar\n");
	printf("digite (5)para buscar\n");
	printf("digite (6) para exibir\n");
	printf("digite (7) para sair\n");
	
	scanf("%d",&op);
	
	system("cls");
	
	return op;
	
}

Tlista busca(Tlista L,int dado)
{
	
	Tlista aux=L;
	Tlista aux2;
	
		if(!aux)
		{
			return NULL;
		}
	
		if(aux->numero==dado)
		{
			return aux;
		}
		else
		{
		
			aux2=aux->prox;
			while(aux2)
			{
				if(aux2->numero==dado)	
				{	
					return aux;
				}
				else
				{	
					aux2=aux2->prox;
					aux=aux->prox;
				}
			}
		}
	
  	return NULL;
}
void exibir(Tlista L)
{
	Tlista aux=L;
	
	if(!aux)
	{
		printf("lista vazia");
	}
	else
	{
		
		while(aux)
		{
		printf("%d ",aux->numero);
		aux=aux->prox;
		}
		printf("\n\n");
		
	}
	
;
}

int remover(Tlista *L,int valor)
{
	int resul=rem(&*L,valor,0);
	
	return resul;
}

int rem(Tlista *L,int valor,int tam)
{
	Tlista aux=*L;
	Tlista aux3;
	Tlista aux2;
	int i=0;
	int cont;
	
	
	
	if(!L)
	{
		return -1;
	}
	
	cont=quantidade(*L,valor);	
	if(cont==0)
	{
		return i;
	}
		
		while(cont>tam)
		{
			
		if((*L)->numero==valor)
		{
			aux=*L;
			*L=aux->prox;
			free(aux);
		}
		else
		{
			if(*L)
			{
			
					aux=busca(*L,valor);
					if((*L)->numero==valor)
					{
						aux=*L;
						*L=(*L)->prox;
						free(aux);
					}
					else
					{
						aux2=aux->prox;
						aux->prox=aux->prox->prox;
						free(aux2);
					
					}
				}
			}
		i++;	
		cont--;	
		}
	
	return i;
}


int main()
{	
	Tlista gancho=NULL;
	int valor;
	int numero;
	int recebe;
	int quant=0;
	int op;
	Tlista aux;
	
	do
	{
		op=escolha();
		
		switch(op)
		{
			case 1:
				printf("digite o numero a ser inserido\n");
				scanf("%d",&valor);
			
				recebe=insere(&gancho,valor);
				
				if(recebe==1)
				{
					printf("o numero foi inserido com sucesso\n\n");
					quant++;
				}
				else
				{
					if(recebe==-1)
					{
						printf("este numero nao pode ser inserido\n\n");
					}
					else
					{
						printf("este numero já foi inserido o maximo de vezes\n\n");
					}
				}
					
			break;
				
			case 2:
				printf("qual numero deseja remover? \n");
				scanf("%d",&numero);
					
				recebe=remover(&gancho,numero);
				
				if(recebe==0)
				{
					printf("nao foi possivel remover este numero\n");
				}
				else
				{
					printf(" o numero %d  foi removido com %d vez(es)\n\n",numero,recebe);
				}
				
			break;
			
			case 6:exibir(gancho);	
			break;		
			
			case 3:
				printf("digite a posicao que vc deseja remover\n");
				scanf("%d",&valor);
				
				if(valor>quant)
				{
					printf("nao e possivel remover o numero nesta posicao,pois ela nao existe na lista\n");
				}
				else
				{
					recebe=rem_pos(&gancho,valor);
					printf("o numero %d na posicao %d foi removido\n\n",recebe,valor);
				}
				break;
			
			case 5:
				printf ("digite o numero que deseja buscar\n");
				scanf("%d",&valor);
				
				aux=busca(gancho,valor);
				if(aux==NULL)
				{
					printf("este numero nao existe\n\n");
					
				}
				else
				{
					if(aux->numero!=valor);
					{
						aux=aux->prox;
					}
					printf("o numero %d esta na posicao (%p)\n\n",valor,aux);
				}
						
			break;	
			
			case 4:
				
				printf("digite o numero que vc quer trocar: ");
				scanf("%d",&numero);
				
				printf("por qual numero vc deseja trocar?  ");
				scanf("%d",&valor);
				
				recebe=alterar(&gancho,numero,valor);
				
				if (recebe>0)
				{
					printf("o numero %d foi alterado pelo %i %d vez(es)\n\n",numero,valor,recebe);
				}
				else
				{
					printf("nao foi possivel alterar o numero\n\n");
				}
				
			break;		
		}
		
		
	}while(op!=7);
	
	
	

	
	
}


