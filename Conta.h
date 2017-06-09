#include <stdio.h>
#include <stdlib.h>
#ifndef _CONTA_H
#define _CONTA_H
#include "tipoDeConta.h"

typedef long TipoChaveConta;
typedef struct Conta {
    TipoChaveConta numeroDaConta;
}Conta;

typedef struct CelulaConta *TipoApontadorConta;
typedef struct CelulaConta{
    ListaTipo listaTipos;
    TipoApontadorConta prox, ant;
    Conta conta;
}CelulaConta;

typedef struct ListaConta {
    TipoApontadorConta Inicio, Fim;
}ListaConta;


void InicializaListaContas (ListaConta *Lista);

int VaziaListaContas (ListaConta Lista);

void InsereVaziaListaContas(ListaConta *Lista, TipoApontadorConta novaConta);

void InsereFimListaContas (ListaConta *Lista, Conta c, ListaTipo listaTipo);

int RemoveUmaConta (ListaConta *Lista, TipoChaveConta chave);

void TransferirEntreContas (ListaConta *ListaFrom, ListaConta *ListaTo, float valor, TipoChaveConta from, int tipoFrom, TipoChaveConta to, int tipoTo);

void ImprimeListaContas(ListaConta Lista);

TipoApontadorConta BuscarListaContas(ListaConta *Lista, TipoChaveConta chave);

Conta* BuscarListaContas2(ListaConta *Lista, TipoChaveConta chave);

int ImprimeUmaConta(ListaConta *Lista, TipoChaveConta chave);


#endif

