#ifndef LISTA_INGRESANTE_H_INCLUDED
#define LISTA_INGRESANTE_H_INCLUDED
#include "ingresante.h"

typedef struct nodo{
    Ingresante vipd;
    struct nodo *next;
}nodo;

typedef struct
{
    nodo* acc;
    nodo* cur;
    nodo* caux;
}Lista_ingresante;

void init(Lista_ingresante* l)
{
    (*l).acc = NULL;
    (*l).cur = NULL;
    (*l).caux = NULL;
}

int isEmpty(Lista_ingresante l)
{
    if(l.acc == NULL)
        return 1;
    return 0;
}

int isOos(Lista_ingresante l)
{
    if(l.cur == NULL)
        return 1;
    return 0;
}

int isFull(Lista_ingresante l)
{
    nodo* p;
    p = (nodo*)malloc(sizeof(nodo*));
    if(p == NULL)
        return 1;
    free((nodo*)p);
    return 0;
}

void reset(Lista_ingresante* l)
{
    (*l).cur = (*l).acc;
    (*l).caux = (*l).acc;
}

void adelante(Lista_ingresante* l)
{
    (*l).caux = (*l).cur;
    (*l).cur = (*l).cur->next;
}

Ingresante copiar(Lista_ingresante l)
{
    return l.cur->vipd;
}

void insertar(Lista_ingresante* l, Ingresante ingresante)
{
    nodo* p;
    p = (nodo*)malloc(sizeof(nodo));
    p->vipd = ingresante;
    if(l->cur == l->acc)
    {
        p->next = l->acc;
        l->acc = p;
        l->cur = p;
        l->caux = p;
    }
    else
    {
        (*l).caux->next = p;
         p->next = (*l).cur;
        (*l).cur = p;
    }
}

void borrar(Lista_ingresante* l)
{
    if((*l).cur == (*l).acc)
    {
        l->cur = l->acc->next;
        l->caux = l->acc->next;
        free((void*)l->acc);
        l->acc = l->cur;
    }
    else
    {
        l->caux->next = l->cur->next;
        free((void*)l->cur);
        l->cur = l->caux->next;
    }
}

#endif // LISTA_INGRESANTE_H_INCLUDED
