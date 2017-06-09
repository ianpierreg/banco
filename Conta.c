#include <stdio.h>
#include <stdlib.h>
#include "Conta.h"

void InicializaListaContas (ListaConta *Lista){
    Lista->Inicio = NULL;
    Lista->Fim = NULL;
}

int VaziaListaContas (ListaConta Lista){
    return (Lista.Inicio == NULL && Lista.Fim == NULL);
}

void InsereVaziaListaContas (ListaConta *Lista, TipoApontadorConta novaConta){
    novaConta->prox = NULL;
    novaConta->ant = NULL;
    Lista->Fim = novaConta;
    Lista->Inicio = Lista->Fim;
}

void InsereFimListaContas (ListaConta *Lista, Conta c, ListaTipo listaTipo){ // nao deixar inserir duplicado?
    TipoChaveConta inicio, fim;
    TipoApontadorConta novaConta = (TipoApontadorConta) malloc(sizeof(CelulaConta));
    novaConta->conta = c;
    novaConta->listaTipos = listaTipo;
    if(VaziaListaContas(*Lista)){
      InsereVaziaListaContas(Lista, novaConta);
    }
    else {
        novaConta->ant = Lista->Fim;
        Lista->Fim->prox = novaConta;
        Lista->Fim = novaConta;
        Lista->Fim->prox = NULL;
    }
}

TipoApontadorConta BuscarListaContas(ListaConta *Lista, TipoChaveConta chave){
 int booleano = 0;
 TipoApontadorConta aux = Lista->Inicio;
    if(VaziaListaContas(*Lista))
    {
        printf("Lista Vazia! \n");
        return aux;
    }
    while (aux != NULL){
        if(aux->conta.numeroDaConta == chave){
            booleano++;
            break;
        }
        aux = aux->prox;
    }
    if(!booleano) {
             printf("Nenhuma conta encontrada! \n");
        return NULL;
    }
    return aux;
}


int RemoveUmaConta (ListaConta *Lista, TipoChaveConta chave){
        int booleano = 0;
        TipoApontadorConta aux = BuscarListaContas(Lista, chave);
        if (aux == NULL){
            return booleano;
        }
        RemoveListaTipos(&aux->listaTipos);

        if (aux->ant != NULL && aux->prox != NULL){
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        free(aux);
        }

        else if (aux->ant != NULL && aux->prox == NULL){
            aux->ant->prox = NULL;
            Lista->Fim = aux->ant;
            free(aux);
        }

        else if (aux->ant == NULL && aux->prox != NULL){
            aux->prox->ant = NULL;
            Lista->Inicio = aux->prox;
            free(aux);
        }

        else if (aux->ant == NULL && aux->prox == NULL){
            Lista->Fim = NULL;
            Lista->Inicio = NULL;
            free(aux);
        }
        booleano = 1;
        return booleano;

    }

void TransferirEntreContas (ListaConta *ListaFrom, ListaConta *ListaTo, float valor, TipoChaveConta from, int tipoFrom, TipoChaveConta to, int tipoTo){
    TipoApontadorConta auxFrom = BuscarListaContas(ListaFrom, from);
    TipoApontadorConta auxTo = BuscarListaContas(ListaTo, to);
    TipoApontadorTipo auxTipoFrom = buscaTipo(&auxFrom->listaTipos, tipoFrom);
    TipoApontadorTipo auxTipoTo =buscaTipo(&auxTo->listaTipos, tipoTo);


    if (valor > auxTipoFrom->tipoDeConta.saldo){
        printf("Impossível fazer saque! Saldo indisponível \n");
    }
    else {
        auxTipoFrom->tipoDeConta.saldo -= valor;
    }
    auxTipoTo->tipoDeConta.saldo += valor;

}


/**void AlterarListaContas (ListaConta *Lista, TipoChaveConta){
AQUI VAI ALTERAR O QUE DA CONTA? NUMERO? NOME? O USUARIO ESCOLHE?
}**/

void ImprimeListaContas(ListaConta Lista){
    TipoApontadorConta Aux = Lista.Inicio;
    while(Aux != NULL){
        printf ("   Numero da conta: %d \n", Aux->conta.numeroDaConta);
        ImprimeTipoListaTipos(Aux->listaTipos);
        Aux = Aux->prox;
    }
     printf ("\n\n");
}

int ImprimeUmaConta(ListaConta *Lista, TipoChaveConta chave){
    int booleano  = 0;
    TipoApontadorConta Aux = BuscarListaContas(Lista, chave);
    if (Aux == NULL){
        return Aux;
    }
    printf ("   Numero da conta: %d \n", Aux->conta.numeroDaConta);
    ImprimeTipoListaTipos(Aux->listaTipos);
     printf ("\n\n");
     return Aux;
}
