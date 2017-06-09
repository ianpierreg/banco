#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

void CriarArvore(NoArvore **raiz){
    *raiz = NULL;
}

void InserirCliente(NoArvore **p, Cliente c, ListaConta listaConta){
    if (*p == NULL){
       *p = (NoArvore *)malloc(sizeof(NoArvore));
        (*p)->cliente = c;
        (*p)->listaContas = listaConta;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
    }else{
        if (c.cpf < (*p)->cliente.cpf){
            InserirCliente(&(*p)->esq, c, listaConta);
        }
        else if (c.cpf > (*p)->cliente.cpf){
            InserirCliente(&(*p)->dir, c, listaConta);
        }
        else printf("Erro : Registro ja existe na arvore\n");
    }
}

void RemoveCliente(TipoChaveCliente cpf, NoArvore **raiz)
{  NoArvore *aux;
  if (*raiz == NULL)
  { printf("Erro : Registro nao esta na arvore\n");
    return;
  }
  if (cpf < (*raiz)->cliente.cpf) {
        RemoveCliente(cpf, &(*raiz)->esq);
        return;
  }
  if (cpf > (*raiz)->cliente.cpf) {
        RemoveCliente(cpf, &(*raiz)->dir);
        return;
  }
  if ((*raiz)->dir == NULL)
  { aux = *raiz;  *raiz = (*raiz)->esq;
    free(aux);
    return;
  }
  if ((*raiz)->esq != NULL)
  { AuxiliaRemocao(*raiz, &(*raiz)->esq);
    return;
  }
  aux = *raiz;  *raiz = (*raiz)->dir;
  free(aux);
}

void AuxiliaRemocao(NoArvore *raiz, NoArvore **dirOrEsq){
     if ((*dirOrEsq)->dir != NULL)
  { AuxiliaRemocao(raiz, &(*dirOrEsq)->dir);
    return;
  }
  raiz->cliente = (*dirOrEsq)->cliente;
  raiz = *dirOrEsq;
  *dirOrEsq = (*dirOrEsq)->esq;
  free(raiz);
}

NoArvore* BuscaArvore(NoArvore *p, TipoChaveCliente cpf){
    if (p == NULL){
        printf("CPF nao cadastrado no sistema\n");
        return p;
    }
    else if (cpf < (*p).cliente.cpf){
        BuscaArvore((*p).esq, cpf);
    }
    else if (cpf > (*p).cliente.cpf){
        BuscaArvore((*p).dir, cpf);
    }
    else
     return p;
}

void TransferenciaDeConta (NoArvore *raiz, TipoChaveCliente cpfFrom, TipoChaveCliente ncontaFrom, TipoChaveCliente cpfTo){
    ListaTipo listaTipo;
    InicializaListaTipos(&listaTipo);
    NoArvore *clienteFrom = BuscaArvore(raiz, cpfFrom);
    NoArvore *clienteTo = BuscaArvore(raiz, cpfTo);
    TipoApontadorConta contaFrom = BuscarListaContas(&clienteFrom->listaContas,ncontaFrom);
    TipoApontadorTipo aux = contaFrom->listaTipos.Inicio;
    while (aux != NULL){
            InsereFimListaTipos(&listaTipo, aux->tipoDeConta);
            aux = aux->prox;
    }
    InsereFimListaContas(&clienteTo->listaContas, contaFrom->conta, listaTipo);
    RemoveUmaConta(&clienteFrom->listaContas, ncontaFrom);
}

void ModificarNome (NoArvore** raiz, Cliente cliente){
     NoArvore *clienteAtual = BuscaArvore(*raiz, cliente.cpf);
     clienteAtual->cliente = cliente;
}

void AlterarCpf (NoArvore **raiz, int cpfAntigo, int cpfAtual){
    NoArvore* clienteAtual = BuscaArvore(*raiz, cpfAntigo);

    Cliente cliente = clienteAtual->cliente;
    cliente.cpf = cpfAtual;
    InserirCliente(raiz, cliente, clienteAtual->listaContas);
    RemoveCliente(clienteAtual->cliente.cpf, raiz);

}

void ImprimeArvore(NoArvore *p){
    if(p != NULL){
        ImprimeArvore(p->esq);
        printf("\nNome: %s     CPF: %d\n", p->cliente.nomeCliente, p->cliente.cpf);
        ImprimeListaContas(p->listaContas);
        ImprimeArvore(p->dir);
    }
}

void ImprimeNoArvore (NoArvore **p, TipoChaveCliente cpf){
    NoArvore *clienteAtual = BuscaArvore(*p, cpf);
    printf("\nNome: %s     CPF: %d\n",clienteAtual->cliente.nomeCliente, clienteAtual->cliente.cpf);
    ImprimeListaContas(clienteAtual->listaContas);
}



