#include <stdio.h>
#include <stdlib.h>
#ifndef _CLIENTE_H
#define _CLIENTE_H
#include "Conta.h"

typedef char NomeCliente;
typedef long int TipoChaveCliente;
typedef struct Cliente {
    TipoChaveCliente cpf;
    NomeCliente nomeCliente[100];
}Cliente;

typedef struct NoArvore{
    Cliente cliente;
    ListaConta listaContas;
    struct  NoArvore *esq;
    struct NoArvore *dir;
}NoArvore;


void CriarArvore(NoArvore **raiz);

void InserirCliente(NoArvore **p, Cliente c, ListaConta listaConta);

void RemoveCliente(TipoChaveCliente cpf, NoArvore **raiz);

void AuxiliaRemocao(NoArvore *raiz, NoArvore **dirOrEsq);

NoArvore* BuscaArvore(NoArvore *p, TipoChaveCliente cpf);

void ModificarNome (NoArvore** raiz, Cliente cliente);

void ImprimeArvore(NoArvore *p);

void AlterarCpf (NoArvore **raiz, int cpfAntigo, int cpfAtual);

void TransferenciaDeConta (NoArvore *raiz, TipoChaveCliente cpfFrom, TipoChaveConta contaFrom, TipoChaveConta cpfTo);

void ImprimeNoArvore (NoArvore **p, TipoChaveCliente cpf);


#endif
