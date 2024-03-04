//
//  queue-lg.h
//  Queue
//
//  Created by Angela Engelbrecht on 01/05/19.
//  Copyright © 2019 Angela Engelbrecht. All rights reserved.
//

#ifndef queue_lg_h
#define queue_lg_h

using namespace std;

struct  no  {
    queue_element  info ;
    no  * link;
};

struct Queue {
    no *first, *last;
};

// Prototipos

void initQueue          (Queue&);
void insert             (Queue& ,queue_element);
int isEmptyQ            (Queue);
queue_element eliminate (Queue&);
queue_element consult   (Queue);
void error (int);
no* novo_no();

///função auxiliar para as mensagens de erros
void error(int i){
    switch(i){
	case 0:cout<< "Empty"; exit(1);
        case 1:cout<< " OVERFLOW "; exit(1);
        case 2:cout<< " UNDERFLOW ";exit(1);
    }
}
///função que aloca memória para um nó
no* novo_no(){
    no* novo = (no*) malloc (sizeof(no));
    if (!novo) error(1);
    return novo;
}

///função para iniciar a fila vazia
void initQueue (Queue& Q) {
    Q.first = Q.last = NULL;
}
///função que verificar se fila vazia(1) ou não(0)
int isEmptyQ (Queue Q)  {
    if(Q.first == NULL)   return 1;
    else     return 0;
}
///função que consultar informação do INICIO da fila
queue_element consult (Queue Q)
{
    if( isEmptyQ (Q) ) error(0);
    return (Q.first-> info);
}
///função que inserir informação no FIM da fila
void insert (Queue& Q, queue_element V)
{
    no *x;
    x = novo_no();
    x-> info  = V;
    x-> link = NULL;
    if(Q.first == NULL) Q.first = x;
    else  Q.last -> link = x;
    Q.last = x;
}
///função que eliminar informação do INICIO da fila
queue_element eliminate (Queue& Q)
{
    queue_element V;
    no *x;
    if(isEmptyQ(Q))error(0);
    V = Q.first->info;
    x = Q.first;
    if ( Q.first == Q.last )  Q.first = Q.last = NULL;
    else      Q.first = Q.first->link;
    free(x);
    return V;
}



#endif /* queue_lg_h */
