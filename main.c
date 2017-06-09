#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Cliente.h"

TipoChaveCliente validaCPF (TipoChaveCliente cpf){
    while (cpf != 0 && (cpf < 1000 || cpf > 9999)){ // aumentar no final pra 10000000 e 99999999
        printf ("\n\n CPF invalido!\n");
        printf ("\n\n Informe o CPF do cliente ou 0 para voltar para o menu\n");
        scanf("%d", &cpf);
        fflush(stdin);
    }
    return cpf;
}

int geraNConta(){
    srand(time(NULL));
    TipoChaveConta numeroConta;
    numeroConta = 1000 + (rand() % 9999);
    return numeroConta;
}

int main()
{
    int verificador=30;
    float valor;
    int cpf,pos, pos1;
    int numeroDeConta, numeroDeConta1;
    Cliente cliente, cliente1;
    char string[100];
    NoArvore *clienteAtual, *clienteAtual1;
    Conta conta, conta0;
    TipoApontadorConta conta1, conta2;
    TipoApontadorTipo tipo;
    TipoDeConta tipoDeConta;
    ListaConta ListaConta;
    ListaTipo ListaTipo;
    int broken = 0;
    char simnao = 'n';
    int indice = 0;

    NoArvore *raiz;
    CriarArvore(&raiz);

   while (verificador != 0){
      printf ("\n################# BANCO IAJ - SEJA BEM VINDO ###################\n");
      printf("\n--------------------------------------------------------\n");
      printf ("1- Cadastrar um cliente \n");
      printf ("2- Inserir uma conta para um cliente ja cadastrado \n");
      printf ("3- Inserir um tipo de conta para uma conta existente \n");
      printf ("4- Realizar um deposito \n");
      printf ("5- Realizar um saque \n");
      printf ("6- Realizar uma transferencia entre tipos de contas da sua propria conta \n");
      printf ("7- Realizar transferencia entre contas diferentes \n");
      printf ("8- Realizar transferencia de uma conta inteira \n");
      printf ("9- Remover uma conta completa \n");
      printf ("10- Remover um cliente completo \n");
      printf ("11- Remover um tipo de conta\n");
      printf ("12- Alterar nome de cliente\n");
      printf ("13- Alterar tipo de conta\n");
      printf ("14- Alterar cpf\n");
      printf ("15- Mostrar todos os clientes do banco\n");
      printf ("16- Mostrar todas as contas de um cliente\n");
      printf ("17- Mostrar todos tipos de conta de uma conta\n");
      printf("\n");
      printf ("0- Finalizar o programa e imprimir a arvore \n");
      printf("--------------------------------------------------------\n");
      printf("DIGITE A OPCAO DESEJADA! \n");
      scanf("%d", &verificador);
      fflush(stdin);

        switch(verificador){
            case 1:
                printf ("\nInforme o CPF do cliente: \n");
                scanf("%d", &cliente.cpf);
                fflush(stdin);
                cliente.cpf = validaCPF (cliente.cpf);
                if (cliente.cpf == 0){
                    break;
                }
                 printf ("\nInforme o nome do cliente: \n");
                 gets(cliente.nomeCliente);
                 InicializaListaContas(&ListaConta);
                 InserirCliente(&raiz, cliente, ListaConta);
                 printf("Cliente cadastrado com SUCESSO! \n");
                 printf("\n----Dados do cliente cadastrado----");
                 ImprimeNoArvore(&raiz, cliente.cpf);
            break;

            case 2:
                printf ("\nInforme o CPF do cliente que recebera a conta: \n");
                scanf("%d", &cliente.cpf);
                fflush(stdin);
                cliente.cpf = validaCPF (cliente.cpf);
                if (cliente.cpf == 0){
                    break;
                }
                clienteAtual = BuscaArvore(raiz, cliente.cpf);
                if (clienteAtual == NULL){
                    break;
                }
                conta.numeroDaConta = geraNConta();
                InicializaListaTipos(&ListaTipo);
                InsereFimListaContas(&clienteAtual->listaContas, conta, ListaTipo);
                printf("\n----Dados do cliente e das contas ja cadastradas----");
                ImprimeNoArvore(&raiz, cliente.cpf);
                printf("Conta cadastrada com SUCESSO! \n");
            break;

            case 3:
                printf ("\n\nInforme o CPF do cliente que recebera tipo de conta: \n");
                scanf("%d", &cliente.cpf);
                fflush(stdin);
                cliente.cpf = validaCPF (cliente.cpf);
                if (cliente.cpf == 0){
                    break;
                }
                clienteAtual  = BuscaArvore(raiz, cliente.cpf);
                if (clienteAtual == NULL){
                    break;
                }
                printf ("\n\nInforme o numero da conta que recebera o tipo de conta: \n");
                scanf("%d", &conta.numeroDaConta);
                fflush(stdin);
                conta1 = BuscarListaContas(&clienteAtual->listaContas, conta.numeroDaConta);
                if(conta1 == NULL){
                    break;
                }
                printf("\n\nInforme o numero que corresponde ao tipo de conta: \n");
                printf("1- CONTA POUPANCA\n");
                printf("2- CONTA CORRENTE\n");
                printf("3- CDB\n");
                printf("4- CONTA ESPECIAL\n");
                printf("5- CONTA DE INVESTIMENTO\n");
                scanf("%d", &verificador);
                switch(verificador){
                    case 1: tipoDeConta.nomeTipo = "Conta Poupanca"; break;
                    case 2: tipoDeConta.nomeTipo = "Conta Corrente"; break;
                    case 3: tipoDeConta.nomeTipo = "CDB"; break;
                    case 4: tipoDeConta.nomeTipo = "Conta Especial"; break;
                    case 5: tipoDeConta.nomeTipo = "Conta De Investimento"; break;
                    default: printf("\nTipo de Conta Inexistente!\n\n");break;
                }
                fflush(stdin);
                tipoDeConta.saldo = 0;
                if (verificador >= 1 && verificador <= 5){
                    if (ComparaTipos(conta1->listaTipos, tipoDeConta.nomeTipo)){
                    InsereFimListaTipos(&conta1->listaTipos, tipoDeConta);
                    printf("\n----Dados do cliente, suas respectivas contas e tipos de contas cadastradas----");
                    ImprimeNoArvore(&raiz, cliente.cpf);
                    printf("Tipo de conta cadastrada com SUCESSO! \n");
                    }
                    else {
                        printf("\n Tipo de conta ja cadastrada nessa conta\n");
                    }
                }
            break;

            case 4:
                indice = 0;
                printf ("\n\nInforme o CPF do cliente que recebera o deposito: \n");
                scanf("%d", &cliente.cpf);
                fflush(stdin);
                cliente.cpf = validaCPF (cliente.cpf);
                if (cliente.cpf == 0){
                    break;
                }
                clienteAtual  = BuscaArvore(raiz, cliente.cpf);
                if (clienteAtual == NULL){
                    break;
                }

                printf ("\n\nInforme o numero da conta que recebera o deposito: \n");
                scanf("%d", &conta.numeroDaConta);
                fflush(stdin);
                conta1 = BuscarListaContas(&clienteAtual->listaContas, conta.numeroDaConta);
                   if(conta1 == NULL){
                    break;
                }
                indice = ImprimeTipoListaTipos(conta1->listaTipos);
                printf("\n\nInforme o indice do tipo de conta que fara o deposito: \n");
                scanf("%d", &pos);
                if(pos <= indice){
                    printf("\n\nInforme o valor do deposito: \n");
                    scanf("%f", &valor);
                    fflush(stdin);
                    deposita(&conta1->listaTipos, valor, pos);
                    printf ("\n\nDados da conta apos o deposito: \n");
                    ImprimeNoArvore(&raiz, cliente.cpf);
                    printf("Deposito realizado com SUCESSO!\n");
                }
                else if (indice  == 0) {
                    printf("Nenhum tipo de conta cadastrado!\n");
                    }
                else {
                    printf("Tipo de conta inexistente!\n");
                }
            break;

            case 5:
                indice = 0;
                printf ("\n\nInforme o CPF do cliente que fara o saque: \n");
                scanf("%d", &cliente.cpf);
                fflush(stdin);
                cliente.cpf = validaCPF (cliente.cpf);
                if (cliente.cpf == 0){
                    break;
                }
                clienteAtual  = BuscaArvore(raiz, cliente.cpf);
                if (clienteAtual == NULL){
                    break;
                }

                printf ("\n\nInforme o numero da conta que sera retirado o dinheiro: \n");
                scanf("%d", &conta.numeroDaConta);
                fflush(stdin);
                conta1 = BuscarListaContas(&clienteAtual->listaContas, conta.numeroDaConta);
                   if(conta1 == NULL){
                    break;
                }
                indice = ImprimeTipoListaTipos(conta1->listaTipos);
                printf("\n\nInforme o indice do tipo de conta onde o saque sera feito: \n");
                scanf("%d", &pos);
                if (pos <= indice){
                    printf("\n\nInforme o valor do saque: \n");
                    scanf("%f", &valor);
                    fflush(stdin);
                    if (saca(&conta1->listaTipos, valor, pos) != NULL){
                        printf ("\n\nDados da conta apos saque: \n");
                        ImprimeNoArvore(&raiz, cliente.cpf);
                        printf("Saque realizado com SUCESSO!\n");
                    }
                }
                else if (indice  == 0) {
                    printf("Nenhum tipo de conta cadastrado!\n");
                    }
                else {
                    printf("Tipo de conta inexistente!\n");
                }
            break;

            case 6:
                printf ("\n\nInforme o CPF do cliente para a transferencia: \n");
                scanf("%d", &cliente.cpf);
                fflush(stdin);
                cliente.cpf = validaCPF (cliente.cpf);
                if (cliente.cpf == 0){
                    break;
                }
                clienteAtual  = BuscaArvore(raiz, cliente.cpf);
                if (clienteAtual == NULL){
                    break;
                }
                printf ("\n\nInforme o numero da conta para a transferencia: \n");
                scanf("%d", &conta.numeroDaConta);
                fflush(stdin);
                conta1 = BuscarListaContas(&clienteAtual->listaContas, conta.numeroDaConta);
                if(conta1 == NULL){
                    break;
                }
                indice = ImprimeTipoListaTipos(conta1->listaTipos);
                printf("\n\nDigite o indice do tipo de conta que sera retirado o dinheiro: \n");
                scanf("%d", &pos);
                if (indice == 0){
                    printf("Nenhum tipo de conta cadastrado!\n");
                    break;
                }
                else if(pos <= indice){
                    indice = ImprimeTipoListaTipos(conta1->listaTipos);
                    printf("\n\nDigite o indice do tipo de conta que recebera o dinheiro transferido (EXCETO O INDICE %d): \n", pos);
                    scanf("%d", &pos1);
                    if (pos1 <= indice){
                        printf("\n\nInforme o valor da transferencia\n");
                        scanf("%f", &valor);
                        fflush(stdin);
                        if (transfere(&conta1->listaTipos, valor, pos, pos1) != NULL){
                        printf("Transferencia realizada com SUCESSO!\n"); //ver se da erro caso o cliente nao tenha grana, é preciso quebrar
                        printf ("\n\nDetalhes da conta  %d, do cliente com CPF %d apos a transferencia: \n", conta.numeroDaConta, cliente.cpf);
                        printf("\n\nConta que foi retirado o dinheiro: \n");
                        ImprimeUmTipo(conta1->listaTipos, pos);
                        printf("\n\nConta que recebeu o dinheiro: \n");
                        ImprimeUmTipo(conta1->listaTipos, pos1);
                        }
                    }
                    else {
                        printf("Tipo de conta inexistente!\n");
                    }
                }
                else {
                    printf("Tipo de conta inexistente!\n");
                }
            break;

            case 7:
                simnao = NULL;
                printf ("\n\nInforme o CPF do cliente que irá transferir o dinheiro: \n");
                scanf("%d", &cliente.cpf);
                fflush(stdin);
                cliente.cpf = validaCPF (cliente.cpf);
                if (cliente.cpf == 0){
                    break;
                }
                clienteAtual  = BuscaArvore(raiz, cliente.cpf);
                if (clienteAtual == NULL){
                    break;
                }
                printf ("\n\nInforme o numero da conta para retirada: \n");
                scanf("%d", &conta.numeroDaConta);
                fflush(stdin);
                conta1 = BuscarListaContas(&clienteAtual->listaContas, conta.numeroDaConta);
                if(conta1 == NULL){
                    break;
                }
                indice = ImprimeTipoListaTipos(conta1->listaTipos);
                printf("\n\nDigite o indice do tipo de conta que sera retirado o dinheiro: \n");
                scanf("%d", &pos);
                fflush(stdin);
                if (pos <= indice){
                    printf("\n\nInforme o valor da transferencia \n");
                    scanf("%f", &valor);
                    fflush(stdin);
                    printf("A transferencia será entre as contas desse mesmo cliente? 'S' para sim e 'N' para nao \n");
                    simnao = getchar();
                    if(simnao == 's' || simnao == 'S'){
                        printf ("\n\nInforme o numero da conta onde o dinheiro sera transferido \n");
                        scanf("%d", &conta0.numeroDaConta);
                        fflush(stdin);
                        conta1 = BuscarListaContas(&clienteAtual->listaContas, conta0.numeroDaConta);
                        if(conta1 == NULL){
                            break;
                        }
                        indice = ImprimeTipoListaTipos(conta1->listaTipos);
                        printf("\n\nDigite o indice do tipo de conta que recebera o dinheiro: \n");
                        scanf("%d", &pos1);
                        if (pos <= indice){
                            TransferirEntreContas(&clienteAtual->listaContas, &clienteAtual->listaContas, valor, conta.numeroDaConta, pos, conta0.numeroDaConta, pos1);
                            printf("\n\nConta que foi retirado o dinheiro: \n");
                            ImprimeUmaConta(&clienteAtual->listaContas, conta.numeroDaConta);
                            printf("\n\nConta que recebeu o dinheiro: \n");
                            ImprimeUmaConta(&clienteAtual->listaContas, conta0.numeroDaConta);
                            simnao = NULL;
                            break;
                        }
                        else if (indice  == 0) {
                            printf("Nenhum tipo de conta cadastrado!\n");
                        }
                        else {
                            printf("Tipo de conta inexistente!\n");
                        }
                    }
                    else if(simnao == 'n' || simnao == 'N'){
                         printf ("\n\nInforme o CPF do cliente que irá receber o dinheiro: \n");//talvez evoluir para transferencia entre clientes
                        scanf("%d", &cliente.cpf);
                        fflush(stdin);
                        cliente.cpf = validaCPF (cliente.cpf);
                        if (cliente.cpf == 0){
                            break;
                        }
                        clienteAtual1  = BuscaArvore(raiz, cliente.cpf);
                        printf ("\n\nInforme o numero da conta onde o dinheiro sera transferido: \n");
                        scanf("%d", &conta0.numeroDaConta);
                        fflush(stdin);
                        conta1 = BuscarListaContas(&clienteAtual1->listaContas, conta0.numeroDaConta);
                        if(conta1 == NULL){
                            break;
                        }
                        indice = ImprimeTipoListaTipos(conta1->listaTipos);
                        printf("\n\nDigite o indice do tipo de conta que sera retirado o dinheiro: \n");
                        scanf("%d", &pos1);
                        if (pos1 <= indice){
                            TransferirEntreContas(&clienteAtual->listaContas, &clienteAtual1->listaContas, valor, conta.numeroDaConta, pos, conta0.numeroDaConta, pos1);
                            printf("\n\nConta que foi retirado o dinheiro: \n"); //tratar o caso de n ter grana
                            ImprimeUmaConta(&clienteAtual->listaContas, conta.numeroDaConta);
                            printf("\n\nConta que recebeu o dinheiro: \n");
                            ImprimeUmaConta(&clienteAtual1->listaContas, conta0.numeroDaConta);
                            printf("Transferencia entre contas diferentes realizada com SUCESSO!\n");
                        }
                        else if (indice  == 0) {
                            printf("Nenhum tipo de conta cadastrado!\n");
                        }
                        else {
                            printf("Tipo de conta inexistente!\n");
                        }
                    }
                    else{
                        printf("\nOpcao invalida! E necessario dizer se a transferencia sera entre duas\n contas do mesmo cliente ou de clientes diferentes: \n\n");
                    }
                }
                else if (indice  == 0) {
                    printf("Nenhum tipo de conta cadastrado!\n");
                }
                else {
                    printf("Tipo de conta inexistente!\n");
                }
                break;

                case 8:
                    printf ("\n\nInforme o CPF do cliente que ira transferir a conta: \n");
                    scanf("%d", &cliente.cpf);
                    fflush(stdin);
                    cliente.cpf = validaCPF (cliente.cpf);
                    if (cliente.cpf == 0){
                        break;
                    }
                    printf ("\n\nInforme o numero da conta que sera transferida: \n");
                    scanf("%d", &conta.numeroDaConta);
                    fflush(stdin);
                    printf ("\n\nInforme o CPF do cliente que ira receber a conta: \n");
                    scanf("%d", &cliente1.cpf);
                    fflush(stdin);
                    cliente1.cpf = validaCPF (cliente1.cpf);
                    if (cliente1.cpf == 0){
                        break;
                    }
                    TransferenciaDeConta(raiz, cliente.cpf, conta.numeroDaConta, cliente1.cpf);
                    printf("Dados da transferencia \n");
                    printf("Tranferencia realizada com sucesso!");
                    ImprimeArvore(raiz);
                break;

                case 9:
                    printf ("\n\nInforme o CPF do cliente que ira ter a conta removida: \n");
                    scanf("%d", &cliente.cpf);
                    fflush(stdin);
                    cliente.cpf = validaCPF (cliente.cpf);
                    if (cliente.cpf == 0){
                        break;
                    }
                    clienteAtual  = BuscaArvore(raiz, cliente.cpf);
                    printf ("\n\nInforme o numero da conta que sera removida: \n");
                    scanf("%d", &conta.numeroDaConta);
                    fflush(stdin);
                   if (RemoveUmaConta(&clienteAtual->listaContas, conta.numeroDaConta) != NULL){
                    printf("\nCliente que teve conta apagada:\n");
                    ImprimeNoArvore(&raiz, cliente.cpf);
                    printf("Conta removida com sucesso");
                   }
                break;

                case 10:
                    printf ("\n\nInforme o CPF do cliente que sera removido: \n");//talvez evoluir para transferencia entre clientes
                    scanf("%d", &cliente.cpf);
                    fflush(stdin);
                    cliente.cpf = validaCPF (cliente.cpf);
                    if (cliente.cpf == 0){
                        break;
                    }
                    RemoveCliente(cliente.cpf, &raiz);
                    ImprimeArvore(raiz);
                    printf("Cliente removido com sucesso!");
                    break;

                case 11:
                    printf ("\n\nInforme o CPF do cliente que tera o tipo removido: \n");
                    scanf("%d", &cliente.cpf);
                    fflush(stdin);
                    cliente.cpf = validaCPF (cliente.cpf);
                    if (cliente.cpf == 0){
                        break;
                    }
                    clienteAtual  = BuscaArvore(raiz, cliente.cpf);
                    if (clienteAtual == NULL){
                        break;
                    }
                    printf ("\n\nInforme o numero da conta que tera o tipo removido: \n");
                    scanf("%d", &conta.numeroDaConta);
                    fflush(stdin);
                    conta1 = BuscarListaContas(&clienteAtual->listaContas, conta.numeroDaConta);
                       if(conta1 == NULL){
                        break;
                    }
                    ImprimeTipoListaTipos(conta1->listaTipos);
                    printf("\n\nInforme o indice do tipo de conta que sera removido: \n");
                    scanf("%d", &pos);
                    RemoveUmTipo(&conta1->listaTipos, pos);
                    printf("\nCliente que teve tipo de conta apagado:\n");
                    ImprimeNoArvore(&raiz, cliente.cpf);
                    printf("Tipo de conta removido com SUCESSO!");
                break;

                case 12:
                     printf ("\nInforme o CPF do cliente que tera o nome alterado: \n");
                    scanf("%d", &cliente.cpf);
                    fflush(stdin);
                    cliente.cpf = validaCPF (cliente.cpf);
                    if (cliente.cpf == 0){
                        break;
                    }
                    clienteAtual  = BuscaArvore(raiz, cliente.cpf);
                    if (clienteAtual == NULL){
                        break;
                    }
                     printf ("\nInforme o novo nome para substituir '%s': \n", clienteAtual->cliente.nomeCliente);
                     gets(cliente.nomeCliente);
                     ModificarNome(&raiz, cliente);
                     printf ("\nConta do cliente depois da modificacao de nome: \n");
                     ImprimeNoArvore(&raiz, clienteAtual->cliente.cpf);
                     break;

                case 13:
                    printf ("\n\nInforme o CPF do cliente que tera o tipo de conta modificado: \n");
                    scanf("%d", &cliente.cpf);
                    fflush(stdin);
                    cliente.cpf = validaCPF (cliente.cpf);
                    if (cliente.cpf == 0){
                        break;
                    }
                    clienteAtual  = BuscaArvore(raiz, cliente.cpf);
                    if (clienteAtual == NULL){
                        break;
                    }
                    printf ("\n\nInforme o numero da conta que tera o tipo de conta modificado: \n");
                    scanf("%d", &conta.numeroDaConta);
                    fflush(stdin);
                    conta1 = BuscarListaContas(&clienteAtual->listaContas, conta.numeroDaConta);
                    if(conta1 == NULL){
                        break;
                    }
                    indice = ImprimeTipoListaTipos(conta1->listaTipos);
                    printf("\n\nInforme o indice do tipo de conta que tera um tipo alterado: \n");
                    scanf("%d", &pos);
                    if (pos <= indice){
                        tipo = buscaTipo(&conta1->listaTipos, pos);
                        printf("\n\nInforme o numero que corresponde ao novo tipo de conta que substituira %s: \n", tipo->tipoDeConta.nomeTipo);
                        printf("1- CONTA POUPANCA\n");
                        printf("2- CONTA CORRENTE\n");
                        printf("3- CDB\n");
                        printf("4- CONTA ESPECIAL\n");
                        printf("5- CONTA DE INVESTIMENTO\n");
                        scanf("%d", &verificador);
                        switch(verificador){
                            case 1: tipoDeConta.nomeTipo = "Conta Poupanca"; break;
                            case 2: tipoDeConta.nomeTipo = "Conta Corrente"; break;
                            case 3: tipoDeConta.nomeTipo = "CDB"; break;
                            case 4: tipoDeConta.nomeTipo = "Conta Especial"; break;
                            case 5: tipoDeConta.nomeTipo = "Conta De Investimento"; break;
                            default: printf("\nTipo de Conta Inexistente!\n\n");break;
                        }
                        fflush(stdin);
                        tipoDeConta.saldo = 0;
                        if (verificador >= 1 && verificador <= 5){
                            if (ComparaTipos(conta1->listaTipos, tipoDeConta.nomeTipo)){
                            modificarTipo(&conta1->listaTipos, pos, tipoDeConta);
                            printf("\n----Dados do cliente, suas respectivas contas e tipos de contas cadastradas----");
                            ImprimeNoArvore(&raiz, cliente.cpf);
                            printf("Tipo de conta modificada com SUCESSO! \n");
                            }
                            else {
                                printf("\n Tipo de conta ja cadastrado nessa conta\n");
                            }
                        }
                  }
                  else if (indice  == 0) {
                    printf("Nenhum tipo de conta cadastrado!\n");
                }
                else {
                    printf("Tipo de conta inexistente!\n");
                }
            break;

            case 14:
                    printf ("\n\nInforme o CPF atual do cliente: \n");
                    scanf("%d", &cliente.cpf);
                    fflush(stdin);
                    cliente.cpf = validaCPF (cliente.cpf);
                    if (cliente.cpf == 0){
                        break;
                    }
                    NoArvore *clienteAtual = BuscaArvore(raiz, cliente.cpf);
                    printf ("\n\nInforme o novo CPF do cliente: \n");
                    scanf("%d", &cliente.cpf);
                    fflush(stdin);
                    cliente.cpf = validaCPF (cliente.cpf);
                    if (cliente.cpf == 0){
                        break;
                    }
                    ImprimeArvore(raiz);
                    AlterarCpf(&raiz, clienteAtual->cliente.cpf, cliente.cpf);
                    ImprimeArvore(raiz);
                    printf("CPF alterado com SUCESSO!");
                    break;

                    case 15:
                        ImprimeArvore(raiz);
                        break;
                    case 16:
                        printf ("\n\nInforme o CPF atual do cliente: \n");
                        scanf("%d", &cliente.cpf);
                        fflush(stdin);
                        cliente.cpf = validaCPF (cliente.cpf);
                        if (cliente.cpf == 0){
                            break;
                        }
                        ImprimeNoArvore(&raiz, cliente.cpf);
                        break;
                    case 17:
                        printf ("\n\nInforme o CPF do cliente: \n");
                        scanf("%d", &cliente.cpf);
                        fflush(stdin);
                        cliente.cpf = validaCPF (cliente.cpf);
                        if (cliente.cpf == 0){
                            break;
                        }
                        clienteAtual  = BuscaArvore(raiz, cliente.cpf);
                        if (clienteAtual == NULL){
                            break;
                        }
                        printf ("\n\nInforme o numero da conta: \n");
                        scanf("%d", &conta.numeroDaConta);
                        fflush(stdin);
                        if(ImprimeUmaConta(&clienteAtual->listaContas, conta.numeroDaConta) == NULL){
                            break;
                        }
                        break;
                default:
                    printf ("Opcao invalida");
                    break;
        }
    }
}






