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
	int i,nos;
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
		//(newnode=p)(sorted=q)(head=lista)
		//struct node* current = sorted;
        /* Locate the node before the point of insertion
         */
        //while (current->next != NULL
        //      && current->next->data < newnode->data) {
        //    current = current->next;
        //}
        //newnode->next = current->next;
        //current->next = newnode;
		//Transferir para ordem crescente 
		//Jogar para lista com descritor.
		//Fazer media como int
		//Buscar lista toda e deletar numero imediatamente superior a media.
		//Reordena a lista novamente.
		
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
