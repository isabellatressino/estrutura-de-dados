#ifndef QUEUE_CF_H_INCLUDED
#define QUEUE_CF_H_INCLUDED
//
//  queue_cf.h
//  Queue
//
//  Created by Angela Engelbrecht on 01/05/19.
//  Copyright © 2019 Angela Engelbrecht. All rights reserved.
//


#include  <stdlib.h>
#include <iostream>

using namespace std;

#define MAXELEMENTS 100

struct Queue{
    int first,last;
    queue_element local[MAXELEMENTS];
};

// Prototipos

void initQueue          (Queue&);
void insert             (Queue& ,queue_element);
int isEmptyQ            (Queue);
queue_element eliminate (Queue&);
queue_element consult   (Queue);

///função auxiliar para as mensagens de erros
void error(int i){
    switch(i){
	case 0:cout<< "Empty"; exit(1);
        case 1:cout<< " OVERFLOW "; exit(1);
        case 2:cout<< " UNDERFLOW ";exit(1);
    }
}

void initQueue (Queue& Q)
{
    Q.first = 0;
    Q.last =-1;
}

int  isEmptyQ (Queue Q)
{
    if(Q.first  > Q.last) return 1;
    else return 0;
}

void insert ( Queue& Q, queue_element V)
{
    if( Q.last == MAXELEMENTS ) error(1);
    Q.last++;
    Q.local[Q.last] = V;
}

queue_element eliminate (Queue& Q)
{
    if( isEmptyQ(Q)) error(2);
    return (Q.local [Q.first++ ]);
}
queue_element consult (Queue Q)
{
    if( isEmptyQ(Q))  error(0);
    return (Q.local[Q.first]);
}


#endif // QUEUE_CF_H_INCLUDED