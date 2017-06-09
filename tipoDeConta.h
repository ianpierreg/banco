#include <stdio.h>
#include <stdlib.h>
#ifndef _TIPODEDECONTA_H
#define _TIPODECONTA_H

typedef char NomeTipo;
typedef struct TipoDeConta {
     NomeTipo *nomeTipo;
     float saldo;
}TipoDeConta;

typedef struct CelulaTipo *TipoApontadorTipo;
typedef struct CelulaTipo{
    TipoApontadorTipo prox;
    TipoDeConta tipoDeConta;
}CelulaTipo;

typedef struct ListaTipo {
    TipoApontadorTipo Inicio, Fim;
}ListaTipo;

void InicializaListaTipos(ListaTipo *Lista);

int VaziaListaTipos (ListaTipo Lista);

void InsereVaziaListaTipos (ListaTipo *Lista, TipoApontadorTipo novoTipo);

void InsereFimListaTipos (ListaTipo *Lista, TipoDeConta tipo);

TipoApontadorTipo buscaTipo (ListaTipo *Lista, int pos);

void RemoveUmTipo (ListaTipo *Lista, int pos);

void RemoveListaTipos (ListaTipo *Lista);

void deposita (ListaTipo *Lista, float valor, int pos);

int saca (ListaTipo *Lista, float valor, int pos);

int transfere (ListaTipo *Lista, float valor, int from, int to);

int ComparaTipos (ListaTipo Lista, char *tipo);

int ImprimeTipoListaTipos(ListaTipo Lista);

void ImprimeUmTipo (ListaTipo Lista, int pos);

 #endif

