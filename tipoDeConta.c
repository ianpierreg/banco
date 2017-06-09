#include <stdio.h>
#include <stdlib.h>
#include "tipoDeConta.h"

void InicializaListaTipos (ListaTipo *Lista){
    Lista->Inicio = NULL;
    Lista->Fim = NULL;
}

int VaziaListaTipos (ListaTipo Lista){
    return (Lista.Inicio == NULL && Lista.Fim == NULL);
}

void InsereVaziaListaTipos (ListaTipo *Lista, TipoApontadorTipo novoTipo){
    novoTipo->prox = NULL;
    Lista->Fim = novoTipo;
    Lista->Inicio = Lista->Fim;
}

void InsereFimListaTipos(ListaTipo *Lista, TipoDeConta tipo){
    TipoApontadorTipo novoTipo = (TipoApontadorTipo) malloc(sizeof(CelulaTipo));
    novoTipo->tipoDeConta = tipo;
    if(VaziaListaTipos(*Lista)){
      InsereVaziaListaTipos(Lista, novoTipo);
    }
    else {
        Lista->Fim->prox = novoTipo;
        Lista->Fim = novoTipo;
        Lista->Fim->prox = NULL;
    }
}

TipoApontadorTipo buscaTipo (ListaTipo *Lista, int pos){
    int i;
    TipoApontadorTipo aux = Lista->Inicio;
    for (i = 2; i <= pos; i++){
        aux = aux->prox;
    }
    return aux;
}

void modificarTipo (ListaTipo *Lista, int pos, TipoDeConta tipoDeConta){
   TipoApontadorTipo aux = buscaTipo(Lista, pos);
   aux->tipoDeConta = tipoDeConta;
}

void RemoveUmTipo (ListaTipo *Lista, int pos){
    TipoApontadorTipo aux = buscaTipo(Lista, pos);
    TipoApontadorTipo aux2;

    if(VaziaListaTipos(*Lista)) {
        printf("\n Nenhum tipo de conta cadastrado!\n\n");
        return;
    }

    if (aux == Lista->Inicio && aux != Lista->Fim){
        Lista->Inicio = aux->prox;
        Lista->Inicio = aux->prox;
        free(aux);
    }

    else if (aux == Lista->Inicio && aux == Lista->Fim){
        Lista->Fim = NULL;
        Lista->Inicio = NULL;
        free(aux);
    }

    else if (aux == Lista->Fim && aux != Lista->Inicio ){
        aux2 = buscaTipo(Lista, pos-1);
        Lista->Fim = aux2;
        Lista->Fim->prox = NULL;
        free(aux);
    }

    else if (aux != Lista->Fim && aux != Lista->Inicio){
        aux2 = buscaTipo(Lista, pos-1);
        aux2->prox = aux->prox;
        free(aux);
    }
}

    void RemoveListaTipos (ListaTipo *Lista){
        TipoApontadorTipo aux = Lista->Inicio;

        if(VaziaListaTipos(*Lista)) {
            printf("\n Nenhum tipo de conta cadastrado!\n\n");
            return;
        }

        if (Lista->Inicio != Lista->Fim){
            Lista->Inicio = aux->prox;
            free(aux);
            RemoveListaTipos(Lista);
        }
        else{
            Lista->Fim = NULL;
            Lista->Inicio = NULL;
            free(aux);
        }
    }

void AlterarListaTipos (ListaTipo *Lista, int pos, NomeTipo *NovoTipo){
    TipoApontadorTipo aux = buscaTipo(Lista, pos);
    aux->tipoDeConta.nomeTipo = NovoTipo;

}

void deposita (ListaTipo *Lista, float valor, int pos){
    TipoApontadorTipo aux = buscaTipo(Lista, pos);
    aux->tipoDeConta.saldo += valor;
}

int saca (ListaTipo *Lista, float valor, int pos){
    int boolean = 0;
    TipoApontadorTipo aux = buscaTipo(Lista, pos);
    if (valor > aux->tipoDeConta.saldo){
        printf("Saldo indisponivel \n");
        return boolean;
    }
    else {
        aux->tipoDeConta.saldo -= valor;
        return boolean = 1;
    }
}

int transfere (ListaTipo *Lista, float valor, int from, int to){
    int booleano = 0;
    TipoApontadorTipo aux = buscaTipo(Lista, from);
    if (valor > aux->tipoDeConta.saldo){
        printf("Saldo indisponivel \n");
        return booleano;
    }
    else {
        aux->tipoDeConta.saldo -= valor;
    }
    aux = buscaTipo(Lista, to);
    aux->tipoDeConta.saldo += valor;
    return booleano = 1;
}

int ComparaTipos (ListaTipo Lista, char *tipo){
    TipoApontadorTipo aux = Lista.Inicio;
    while (aux!=NULL){
        if (!strcmp(tipo, aux->tipoDeConta.nomeTipo)){
            return 0;
        }
    aux = aux->prox;
    }
    return 1;
}

int ImprimeTipoListaTipos(ListaTipo Lista){
    TipoApontadorTipo Aux = Lista.Inicio;
    int indice = 0;
    while(Aux != NULL){
        indice++;
        printf("      Tipo De Conta %d = %s\n            Saldo = %.2f \n", indice, Aux->tipoDeConta.nomeTipo, Aux->tipoDeConta.saldo); //resolver
        Aux = Aux->prox;
    }
    return indice;
}

void ImprimeUmTipo (ListaTipo Lista, int pos){
    TipoApontadorTipo Aux = buscaTipo(&Lista, pos);
    printf("      Tipo De Conta = %s         Saldo = %.2f \n", Aux->tipoDeConta.nomeTipo, Aux->tipoDeConta.saldo); //resolver

}
