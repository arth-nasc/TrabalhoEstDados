
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int dado;
	struct node *prox;
};

struct descritor{
	struct node *i, *f;
	int n;
};

int main(int argc, char *argv[]) {
	int i,nos,med;
	struct node *p, *q,*lista;
	printf("Quantos nos deseja inserir? ");
	scanf("%i", &nos);
	
	
	struct descritor *d;
	d = malloc(sizeof(struct descritor));
	d->i = NULL;
	d->f = NULL;
	d->n = 0;
	
	srand(time(NULL));
	
	

	do{
		p = malloc(sizeof(struct node));
		p->dado=rand()%99;
		p->prox = lista;
		lista=p;
		//Inserir numa lista com descritor em ordem:
	    
		//Transferir para ordem crescente 
		//Jogar para lista com descritor.
		//Fazer media como int
		
	    for (i=0;i++;){
	        p=p->dado;
        //Buscar lista toda e deletar numero imediatamente superior a media.

	        if (p->dado>med){
	            free(p->dado);
	            free(p->prox);
	            break;
	        }
	        
        //Organizar lista novamente, usando-se as funções da lista com descritor
	    }
	   //Organizar lista novamente, usando-se as funções da lista com descritor

		/*if(d->n==0){
			d->i = p;
			d->f = p;
			d->n = 1;
		}
		else{
			q = d->f;
			q->prox = p;
			d->f = p;
			d->n++;			
		*/
		i++;
        printf("%i ",p->dado);

	}while(i<nos);
	
	return 0;
}
