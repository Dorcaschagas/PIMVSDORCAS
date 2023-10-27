#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
//arrumar calculo de preco de reserva
int i, filial, CARGO, diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida, diaDoAnoSaida, diaDoAnoEntrada, numeroQuarto,TipodeUsuario, multa, acessoglobal=0, ReservasConcluidas=0, opc1;
char NOME[50], CPF[12], SENHA[15];
float precoS1=650.00, precoC1=850.00, precoM1=1150.00, precoP1=1750.00;
float precoS2=450.00, precoC2=550.00, precoM2=750.00;
typedef struct
{
    char nome[50], cpf[12], senha[15];
    int codcad, cargo;
} cadastroCliente;

typedef struct
{
    int numeroQuarto, diaDoAnoEntrada,diaDoAnoSaida, AnoEntrada, AnoSaida, CodRes, pg, fillial; //pg quando 0 significa nao pg, quando 1 siginifica pg
    char nomeR[50], cpfR[12],  USUARIO[50];
    float precoreserva;
} ReservaA;
typedef struct
{
    int numeroQuarto, diaDoAnoEntrada,diaDoAnoSaida, AnoEntrada, AnoSaida, fillial; //pg quando 0 significa nao pg, quando 1 siginifica pg
    float precoreserva;
} Pago;

typedef struct
{
    int cargo;
    char nome[50], senha[15];
} funcionarios;

void LoginFuncionario(funcionarios Funcionario[], int *nFuncionarios);
void definidorfuncionarios(funcionarios Funcionarios[], int *nFuncionarios);
void ConcluirReserva(ReservaA reserva[], Pago reservac[], int *nReservas, int *nReserC);
void ExibirReservasCliente(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas);
void Logincliente(cadastroCliente cadastroCli[], funcionarios Funcionario[],int *numClientes, int *nFuncionarios);
int recebedordecheckin(ReservaA reserva[], int*nReservas);
void exibirClientes(cadastroCliente clientes[], int *numClientes);
void cadastrarCliente(cadastroCliente clientes[], int *numClientes);
void FazerReservasFuncionario(ReservaA reserva[], cadastroCliente cadastroCli[],  int *nReservas, int *numClientes);
void FazerReservasCliente(ReservaA reserva[], cadastroCliente cadastroCli[],  int *nReservas, int *numClientes);
void ExibirReservas(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas);
void VerificarDisponibilidade(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas);
void CancelarReserva(ReservaA reserva[], int *nReservas);
void LeitorFaturamento(ReservaA reserva[],Pago reserc[], int *nReservas, int *nReserc);
void definirCorConsole();
int CompararDataAtual (int Dia, int Mes, int Ano);
int ValidarDatas(int dia, int mes, int ano);
int dataParaDiaDoAno(int dia, int mes, int ano);
int VerificarSobreposicao(ReservaA reserva[], int nReservas, int numeroQuarto, int diaDoAnoEntrada, int diaDoAnoSaida);
void mensagemMenuFun();
void descricaoQrt();

int main()
{
    system("color B0");
    setlocale(LC_ALL, "Portuguese");
    funcionarios Funcionarios[5];
    cadastroCliente client[1000];
    ReservaA reservas[1000];
    Pago reservasC[1000];
    int numReservas = 0, nClientes =0, numFuncionarios =0, numReservasC=0;
    int  opc1 = 0, opc = 0, num;


    definidorfuncionarios(Funcionarios, &numFuncionarios);
    //=====================================================
    //=======================login=========================
    //definidorfuncionarios(Funcionarios, &numFuncionarios);

    do
    {
        system("cls");
        printf("\n=============================================\n");
        printf("---Bem vindo a rede Hotel Algoritmo Suites---");
        printf("\n=============================================\n");
        printf("Escolha uma opção\n");
        printf("[1] Login de Cliente.\n");
        printf("[2] Login de Colaborador.\n");
        printf("[3] Cadastre-se.\n");
        printf("[4] Conheça nossos Quartos.\n");
        printf("[5] Fechar programa.\n");
        scanf("%d", &TipodeUsuario);
        fflush(stdin);
        if(TipodeUsuario==2)
            opc1=1;
        else if(TipodeUsuario==1)
            opc1=1;
        else if(TipodeUsuario==3)
            opc1=3;
        else if(TipodeUsuario==4)
            opc1=4;
        else if(TipodeUsuario==5)
            opc1=5;

        switch(opc1)
        {
        case 1:

            if(TipodeUsuario==1)
                Logincliente(client, Funcionarios, &nClientes, &numFuncionarios);
            if(TipodeUsuario==2)
            {
                LoginFuncionario(Funcionarios, &numFuncionarios);

            }
            do
            {
                system("cls");
                printf("\n|------------------Bem vindo a rede Hotel Algoritmo Suites-------------------|\n");
                printf("\n|1.Escolha 1 para a filial (1) - Master......................................|");
                printf("\n|2.Escolha 2 para a filial (2) - Confort.....................................|\n");
                printf("\n|3.Escolha 3 para Voltar.....................................................|\n");
                scanf("%d", &filial);
                system("cls");

                switch (filial)
                {
                case 1:
                    do
                    {
                        system("cls");
                        if(CARGO==1)
                            mensagemMenuFun();
                        if(CARGO==0)
                            mensagemMenuCli();

                        scanf("%d", &opc);
                        system("cls");

                        switch (opc)
                        {
                        case 1:
                            if(CARGO==1)
                            {
                                VerificarDisponibilidade(reservas, client, &numReservas);
                                FazerReservasFuncionario(reservas, client, &numReservas, &nClientes);

                            }
                            if(CARGO==0)
                            {
                                VerificarDisponibilidade(reservas, client, &numReservas);
                                FazerReservasCliente(reservas, client, &numReservas, &nClientes);
                            }
                            break;
                        case 2:
                            //=====================================================
                            //=====================clientes========================
                            if(CARGO==1)
                                cadastrarCliente(client, &nClientes);
                            if(CARGO==0)
                            {
                                ExibirReservasCliente(reservas, client, &numReservas);
                                system("pause");
                            }
                            break;
                        case 3:
                            //=====================================================
                            //====================relatorio========================
                            if(CARGO==1)
                            {
                                ExibirReservas(reservas, client, &numReservas);
                                system("pause");
                            }
                            if(CARGO==0)
                                VerificarDisponibilidade(reservas, client, &numReservas);
                            system("pause");
                            break;
                        case 4:
                            if(CARGO==1)
                                ConcluirReserva(reservas,reservasC, &numReservas, &numReservasC);
                            if(CARGO==0)
                                printf("opcao invalida");

                            break;
                        case 5:
                            if(CARGO==1)
                            {
                                ExibirReservas(reservas, client, &numReservas);
                                CancelarReserva(reservas, &numReservas);
                            }
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 6:
                            if(CARGO==1)
                            {
                                exibirClientes(client, &nClientes);
                                system("pause");
                            }
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 7:
                            if(CARGO==1)
                                LeitorFaturamento(reservas,reservasC, &numReservas, &numReservasC);
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 8:
                            formaPagamento(nClientes, client, reservas);
                            confirmarPagamento(reservas, &numReservas );
                            break;
                        case 9:
                            if(CARGO==1)
                                Alteradordepreco();
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 10:
                            definirCorConsole();
                            break;
                        default:
                            printf("opcao invalida");
                            break;
                        case 13:
                            break;
                        }
                    }
                    while (opc != 13);
                    break;
                case 2:
                    do
                    {
                        system("cls");
                        if(CARGO==1)
                            mensagemMenuFun();
                        if(CARGO==0)
                            mensagemMenuCli();

                        scanf("%d", &opc);
                        system("cls");

                        switch (opc)
                        {
                        case 1:
                            if(CARGO==1)
                            {
                                VerificarDisponibilidade(reservas, client, &numReservas);
                                FazerReservasFuncionario(reservas, client, &numReservas, &nClientes);

                            }
                            if(CARGO==0)
                            {
                                VerificarDisponibilidade(reservas, client, &numReservas);
                                FazerReservasCliente(reservas, client, &numReservas, &nClientes);
                            }
                            break;
                        case 2:
                            //=====================================================
                            //=====================clientes========================
                            if(CARGO==1)
                                cadastrarCliente(client, &nClientes);
                            if(CARGO==0)
                            {
                                ExibirReservasCliente(reservas, client, &numReservas);
                                system("pause");
                            }
                            break;
                        case 3:
                            //=====================================================
                            //====================relatorio========================
                            if(CARGO==1)
                            {
                                ExibirReservas(reservas, client, &numReservas);
                                system("pause");
                            }
                            if(CARGO==0)
                                VerificarDisponibilidade(reservas, client, &numReservas);
                            system("pause");
                            break;
                        case 4:
                            if(CARGO==1)
                                ConcluirReserva(reservas,reservasC, &numReservas, &numReservasC);
                            if(CARGO==0)
                                printf("opcao invalida");

                            break;
                        case 5:
                            if(CARGO==1)
                            {
                                ExibirReservas(reservas, client, &numReservas);
                                CancelarReserva(reservas, &numReservas);
                            }
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 6:
                            if(CARGO==1)
                            {
                                exibirClientes(client, &nClientes);
                                system("pause");
                            }
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 7:
                            if(CARGO==1)
                                LeitorFaturamento(reservas,reservasC, &numReservas, &numReservasC);
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 8:
                            formaPagamento(nClientes, client, reservas);
                            confirmarPagamento(reservas, &numReservas);
                            break;
                        case 9:
                            if(CARGO==1)
                                Alteradordepreco();
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 10:
                            definirCorConsole();
                            break;
                        default:
                            printf("opcao invalida");
                            break;
                        case 13:
                            break;
                        }
                    }
                    while (opc != 13);
                    break;

                case 3:
                    break;
                default:
                    printf("\nopcao invalida\n");
                    system("pause");
                    system("cls");
                    break;
                }
            }
            while(filial != 3);
            break;
        case 2:
            LoginFuncionario(Funcionarios, &numFuncionarios);
            break;
        case 3:
            cadastrarCliente(client, &nClientes);
            break;
        case 4:
            system("cls");
            printf("[1]FILIAL – MASTER\n");
            printf("[2]FILIAL – COMFORT\n");
            scanf("%d", &num);

            if(num == 1)
            {
                descricaoQrtF1();
            }
            else if(num == 2)
            {
                descricaoQrtF2();
            }
            else
            {
                printf("Escolha invalida!\n\n");
                system("pause");
            }

            break;
        case 5:
            break;
        default:
            system("cls");
            printf("\nOpção Invalida!\n");
            break;
        }
    }
    while(opc1!=5);
    //=====================================================
    //=====================Quartos=========================

    return 0;
}

void Logincliente(cadastroCliente cadastroCli[], funcionarios Funcionario[],int *numClientes, int *nFuncionarios)
{
    system("cls");
    int procurarcliente, acesso;
    char nome1[50];
    char senhaA[15];
    printf("\nLogin de Cliente!\n");
    do
    {
        if(*numClientes!=0)
        {
            printf("\nUsuario: ");
            scanf("%s", &nome1);
            printf("Senha: ");
            scanf("%s", &senhaA);

            for(i=0; i<*numClientes; i++)
            {
                if(strcmp(nome1,cadastroCli[i].nome)==0)
                {
                    procurarcliente=i;
                    acesso=1;

                }
            }
            for(i=0; i<*numClientes; i++)
            {
                if(strcmp(senhaA,cadastroCli[i].senha)==0)
                {
                    procurarcliente=i;
                    acesso=1;

                }
            }
            CARGO=cadastroCli[procurarcliente].cargo;
        }
        else if(*numClientes==0)
        {
            printf("\nAinda não há Clientes!\n");
            cadastrarCliente(cadastroCli, numClientes);

        }
    }
    while(acesso!=1);
    strcpy(NOME,cadastroCli[procurarcliente].nome);
    strcpy(SENHA,cadastroCli[procurarcliente].senha);
    strcpy(CPF,cadastroCli[procurarcliente].cpf);
}

void LoginFuncionario(funcionarios Funcionario[], int *nFuncionarios)
{

    int procurarfun = 0, procurarcliente = -1;
    char nome1[50], senhaA[15];
    printf("\nLogin de Colaborador!\n");
    int i;

    do
    {
        printf("\nUsuario: ");
        scanf("%s", nome1);
        printf("Senha: ");
        scanf("%s", senhaA);

        for (i = 0; i < *nFuncionarios; i++)
        {
            if (strcmp(nome1, Funcionario[i].nome) == 0 && strcmp(senhaA, Funcionario[i].senha) == 0)
            {
                procurarfun = 1;
                procurarcliente = i;
                acessoglobal = 1;
                break;
            }
        }

        if (procurarcliente == -1)
        {
            printf("Nome de usuario ou senha inválido. Por Favor tente novamente.\n");
        }
    }
    while (procurarfun != 1);

    CARGO = Funcionario[procurarcliente].cargo;
    strcpy(NOME, Funcionario[procurarcliente].nome);
    strcpy(SENHA, Funcionario[procurarcliente].senha);
}

//============================================================================================
//========================================Clientes===========================================
void cadastrarCliente(cadastroCliente client[], int *nClientes)
{
    system("cls");

    cadastroCliente novoCliente;
    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", novoCliente.nome);

    printf("\nDigite o CPF do cliente: ");
    scanf(" %s", novoCliente.cpf);

    printf("\nDigite a Senha do Cliente: ");
    scanf(" %s", novoCliente.senha);

    novoCliente.cargo=0;

    novoCliente.codcad=*nClientes+1;

    client[*nClientes] = novoCliente;
    (*nClientes)++;
    printf("\n\nCliente %s, cadastrado com sucesso!!!\n\n", novoCliente.nome);
    system("pause");

    return;
}
//============================================================================================
//=======================================relatorio============================================
void exibirClientes(cadastroCliente client[], int *numClientes)
{
    if(*numClientes!=0)
        printf("=======Clientes cadastrados:===========\n");
    i=0;
    while(i < *numClientes)
    {
        printf("Nome: %s\n", client[i].nome);
        printf("CPF: %s\n", client[i].cpf);
        printf("Codigo do Cliente: %d\n", client[i].codcad);
        printf("===================================\n");
        i++;
    }
    if(*numClientes==0)
        printf("\nNao há Cadastros!\n");
}
//============================================================================================
//==================================mensagem menu=============================================
void mensagemMenuFun()
{
    printf(" \n______________________________________________________ ");
    if(filial==1)
        printf("\n|-------Bem-vindo ao Algoritmo Suites Master-----------|");
    if(filial==2)
        printf("\n|-------Bem-vindo ao Algoritmo Suites Confort----------|");
    printf("\n ______________________________________________________ ");
    printf("\n|--------------------Menu Colaborador------------------|");
    printf("\n Olá, %s", NOME);
    printf("\n|______________________________________________________|\n");
    printf("\n1|Escolha 1 para fazer uma reserva.....................|");
    printf("\n2|Escolha 2 para Cadastro de clientes..................|");
    printf("\n3|Escolha 3 para visualizar as reservas................|");
    printf("\n4|Escolha 4 para fazer Check-in e Check-out............|");
    printf("\n5|Escolha 5 para cancelar reserva......................|");
    printf("\n6|Escolha 6 para ver clientes..........................|");
    printf("\n7|Escolha 7 para ver relatorio de faturamento..........|");
    printf("\n8|Escolha 8 para realizar pagamento....................|");
    printf("\n9|Escolha 9 para alterar preço de estadia.............|\n");
    printf("\n10|Escolha 10 para alterar tema do sistema.............|");
    printf("\n\n13|Escolha 13 voltar.................................|\n\n");
}

void mensagemMenuCli()
{
    printf(" \n______________________________________________________ ");
    if(filial==1)
        printf("\n|-------Bem-vindo ao Algoritmo Suites Master-----------|");
    if(filial==2)
        printf("\n|-------Bem-vindo ao Algoritmo Suites Confort----------|");
    printf("\n ______________________________________________________ ");
    printf("\n|-------------------------Menu-------------------------|");
    printf("\n Olá, %s\tPortador do cpf %s", NOME, CPF);
    printf("\n|______________________________________________________|\n");
    printf("\n1|Escolha 1 para fazer uma reserva.....................|");
    printf("\n2|Escolha 2 para visualizar as minhas reservas.........|");
    printf("\n2|Escolha 3 para visualizar estadias ja reservadas.....|\n");
    printf("\n10|Escolha 10 para alterar tema do sistema.............|");
    printf("\n\n13|Escolha 13 para voltar............................|\n\n");
}

void descricaoQrtF1()
{
    system("cls");
    printf("\n_________________________________________________________________________________________\n");
    printf("=============================REDE DE HOTEL ALGORITMO SUÍTES==============================\n");

    printf("\n\t\t\t\tFILIAL 1 – MASTER\n\n");


    printf("\n======================================STANDARD===========================================\n");
    printf("Esta categoria possui apartamentos de 30m², todos com sacada e decoração moderna. \
           \nEstão em andares mais baixos, com vista para o jardim. Piso vinílico, frigobar, tv \
           \npor assinatura, banheiro completo com amenities de banho e secador de cabelo. \
           \nOpção: cama Queen Size ou duas camas de solteiro. Café da manhã e wifi são cortesia.");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n,", precoS1);
    printf("=========================================================================================\n\n");

    printf("======================================COMFORT=============================================\n");
    printf("Esta categoria possui apartamentos de 40m², todos com decoração moderna. \
           \nEstão em andares intermediários, com vista para a cidade. Piso vinílico, frigobar, \
           \ntábua de passar e ferro, tv por assinatura, banheiro completo com amenities de banho, \
           \nsecador de cabelo e roupão. Cama Queen Size. Café da manhã e wifi são cortesia. ");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n", precoC1);
    printf("=========================================================================================\n\n");

    printf("\n======================================MASTER==============================================\n");
    printf("Esta categoria possui apartamentos de 50m², todos com decoração moderna. Estão em andares \
           \nintermediários, com vista para a cidade. Piso vinílico, frigobar, tábua de passar e ferro, \
           \ntv por assinatura e plataforma de streaming. Banheiro completo com amenities L’Occitane \
           \nde banho, secador de cabelo, roupão e chinelo de quarto. Cama Queen Size. \
           \nCafé da manhã e wifi são cortesia.");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n", precoM1);
    printf("=========================================================================================\n\n");

    printf("\n===================================PRESIDENCIAL===========================================\n");
    printf("Esta categoria possui apartamentos suntuosos, elegantes e confortáveis de 90m². \
           \nEstão em andares altos com vista panorâmica da cidade. Piso vinílico, frigobar, \
           \ntv por assinatura e plataforma de streaming, máquina de café Nespresso. \
           \nBanheiro completo com hidromassagem, amenities de banho L’Occitane, secador de cabelo, \
           \nroupão e chinelo de quarto. Cama King Size. Café da manhã e wifi são cortesia.");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n", precoP1);
    printf("=========================================================================================\n\n");

    system("pause");
    return;
}

void descricaoQrtF2()
{
    system("cls");
    printf("\n_________________________________________________________________________________________\n");
    printf("=============================REDE DE HOTEL ALGORITMO SUÍTES==============================\n");

    printf("\n\t\t\t\tFILIAL 1 – MASTER\n\n");


    printf("\n======================================STANDARD===========================================\n");
    printf("Esta categoria possui apartamentos de 20m² com decoração moderna. Estão em andares \
           \nmais baixos, com vista para o jardim. Piso vinílico, frigobar, tv por assinatura, \
           \nbanheiro completo com amenities de banho e secador de cabelo. Opção: cama de casal ou \
           \nduas camas de solteiro. Café da manhã e wifi são cortesia.");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n",precoS2);
    printf("=========================================================================================\n\n");

    printf("======================================COMFORT=============================================\n");
    printf("Esta categoria possui apartamentos de 25m², todos com decoração moderna. \
           \nEstão em andares intermediários, com vista para a cidade. Piso vinílico, frigobar, \
           \ntv por assinatura, banheiro completo com amenities de banho. Cama Queen Size. \
           \nCafé da manhã e wifi são cortesia. ");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n",precoC2);
    printf("=========================================================================================\n\n");

    printf("\n======================================MASTER=============================================\n");
    printf("Esta categoria possui apartamentos de 30m², todos com decoração moderna e sacada. \
           \nEstão em andares altos, com vista para a cidade. Piso vinílico, frigobar, \
           \ntv por assinatura e máquina de café Nespresso. Banheiro completo com amenities, \
           \nsecador de cabelo e roupão. Cama King Size. Café da manhã e wifi são cortesia. ");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n", precoM2);
    printf("=========================================================================================\n\n");

    system("pause");
    return;

}
void diaDoAnoParaData(int diaDoAno, int ano, int *dia, int *mes)
{
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    {
        diasNoMes[2] = 29; // Fevereiro em anos bissextos
    }

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (diaDoAno <= diasNoMes[i])
        {
            break;
        }
        diaDoAno -= diasNoMes[i];
    }

    *dia = diaDoAno;
    *mes = i;
}
int ValidarDatas(int dia, int mes, int ano)
{
    if (mes >= 1 && mes <= 12)
    {
        if ((mes <= 7 && mes % 2 != 0) || (mes > 7 && mes % 2 == 0))
        {
            if (dia >= 1 && dia <= 31)
            {
                return 1;  // Data válida
            }
        }
        else if (mes == 2)
        {
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
            {
                if (dia >= 1 && dia <= 29)
                {
                    return 1;  // Data válida para ano bissexto
                }
            }
            else
            {
                if (dia >= 1 && dia <= 28)
                {
                    return 1;  // Data válida para ano não bissexto
                }
            }
        }
        else
        {
            if (dia >= 1 && dia <= 30)
            {
                return 1;  // Data válida para outros meses
            }
        }
    }
    return 0;  // Fora do intervalo de mês (1-12)
}
int CompararDataAtual(int Dia, int Mes, int Ano)
{
    time_t current_time;
    struct tm* timeinfo;
    time(&current_time);
    timeinfo = localtime(&current_time);

    if (Ano < timeinfo->tm_year + 1900)
    {
        return -1; // A data fornecida está no passado
    }
    else if (Ano > timeinfo->tm_year + 1900)
    {
        return 0; // A data fornecida está no futuro
    }
    else
    {
        if (Mes < timeinfo->tm_mon + 1)
        {
            return -1; // A data fornecida está no passado
        }
        else if (Mes > timeinfo->tm_mon + 1)
        {
            return 0; // A data fornecida está no futuro
        }
        else
        {
            if (Dia < timeinfo->tm_mday)
            {
                return -1; // A data fornecida está no passado
            }
            else if (Dia > timeinfo->tm_mday)
            {
                return 0; // A data fornecida está no futuro
            }
            else
            {
                return 0; // A data fornecida é igual à data atual
            }
        }
    }
}
int dataParaDiaDoAno(int dia, int mes, int ano)
{
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    {
        diasNoMes[2] = 29; // Fevereiro em anos bissextos
    }

    int diaDoAno = dia;
    for (int i = 1; i < mes; i++)
    {
        diaDoAno += diasNoMes[i];
    }

    return diaDoAno;
}
int VerificarSobreposicao(ReservaA reserva[], int nReservas, int numeroQuarto, int diaDoAnoEntrada, int diaDoAnoSaida)
{
    for (int i = 0; i < nReservas; i++)
    {
        if (reserva[i].numeroQuarto == numeroQuarto && reserva[i].fillial == filial)
        {
            // Verificar se a nova reserva começa antes da reserva existente terminar
            if (diaDoAnoSaida >= reserva[i].diaDoAnoEntrada)
            {
                // Verificar se a nova reserva termina depois da reserva existente começar
                if (diaDoAnoEntrada <= reserva[i].diaDoAnoSaida)
                {
                    return 1; // Sobreposição encontrada
                }
            }
        }
    }
    return 0; // Sem sobreposição de datas
}
int PrecificarQuartoF1(int nnQuarto, float preco)
{
    if(nnQuarto>=1 && nnQuarto<=3)
    {
        preco=precoS1;
    }
    if(nnQuarto>=4 && nnQuarto<=6)
    {
        preco=precoC1;
    }
    if(nnQuarto>=7 && nnQuarto<=9)
    {
        preco=precoM1;
    }
    if(nnQuarto>=10 && nnQuarto<=12)
    {
        preco=precoP1;
    }
    return preco;
}
void Alteradordepreco()
{
    int Estadia;
    float novopreco;
    do
    {
        printf("\nQual Estadia, voce deseja alterar o preço?\n");
        printf("[1]Standard\n");
        printf("[2]Comfort\n");
        printf("[3]Master\n");
        if(filial==1)
            printf("[4]Presidencial\n");
        printf("[5] Voltar\n");
        scanf("%d", &Estadia);
        switch(Estadia)
        {
        case 1:
            if(filial==1)
            {
                printf("\nPor favor insira o novo preço da Estadia Standard");
                scanf("%f", &novopreco);
                precoS1=novopreco;
            }
            if(filial==2)
            {
                printf("\nPor favor insira o novo preço da Estadia Standard");
                scanf("%f", &novopreco);
                precoS2=novopreco;

            }
            break;
        case 2:
            if(filial==1)
            {
                printf("\nPor favor insira o novo preço da Estadia Comfort");
                scanf("%f", &novopreco);
                precoC1=novopreco;

            }
            if(filial==2)
            {
                printf("\nPor favor insira o novo preço da Estadia Comfort");
                scanf("%f", &novopreco);
                precoC2=novopreco;

            }
            break;
        case 3:
            if(filial==1)
            {
                printf("\nPor favor insira o novo preço da Estadia Master");
                scanf("%f", &novopreco);
                precoM1=novopreco;

            }
            if(filial==2)
            {
                printf("\nPor favor insira o novo preço da Estadia Master");
                scanf("%f", &novopreco);
                precoM2=novopreco;

            }
            break;
        case 4:
            if(filial==1)
            {
                printf("\nPor favor insira o novo preço da Estadia Presidencial");
                scanf("%f", &novopreco);
                precoP1=novopreco;

            }
            if(filial==2)
                printf("\nOpção Invalida!\n");
            break;
        case 5:
            break;
        default:
            printf("\nOpção Invalida!\n");
        }
    }
    while(Estadia!=5);
    return;
}

int PrecificarQuartoF2(int nnQuarto, float preco)
{
    if(nnQuarto>=1 && nnQuarto<=3)
    {
        preco=precoS2;
    }
    if(nnQuarto>=4 && nnQuarto<=6)
    {
        preco=precoC2;
    }
    if(nnQuarto>=7 && nnQuarto<=9)
    {
        preco=precoM2;
    }

    return preco;
}
// Função de comparação para ordenar as reservas com base na data de check-in


void FazerReservasFuncionario(ReservaA reserva[], cadastroCliente cadastroCli[],  int *nReservas, int *numClientes)
{
    int p=1, opcreserva, quebraL=1, codcli, codirese, gapDia;
    float precoR;
    do
    {
        recebedordecheckin(reserva, nReservas);
        if(filial==1)
            precoR=PrecificarQuartoF1(numeroQuarto, precoR);
        if(filial==2)
            precoR=PrecificarQuartoF2(numeroQuarto, precoR);
        gapDia=(float)(diaDoAnoSaida-diaDoAnoEntrada);
        precoR*= gapDia;
        reserva[*nReservas].precoreserva = precoR;
        printf("\nData de entrada no dia %d/%d/%d registrada com sucesso!\n", diaEntrada, mesEntrada,anoEntrada);
        printf("\nData de saida no dia %d/%d/%d registrada com sucesso!\n", diaSaida, mesSaida,anoSaida);
        printf("\nCom o preço de R$%2.f\n", precoR);
        reserva[*nReservas].fillial=filial;
        do
        {
            printf("\nVoce deseja:\n");
            printf("\n 1 - Escolher um cliente?");
            printf("\n 2 - Cadastrar novo cliente?\n");
            scanf("%d", &opcreserva);

            codirese=*nReservas+1501;
            reserva[*nReservas].CodRes = codirese;
            switch(opcreserva)
            {
            case 1:
                system("cls");
                exibirClientes(cadastroCli, numClientes);
                if(*numClientes==0)
                    cadastrarCliente(cadastroCli, numClientes);
                printf("\nPor favor insira o codigo do cliente:\n");
                scanf("%d", &codcli);
                int clienteachado= -1;
                for(i=0; i<*numClientes; i++)
                {
                    if(cadastroCli[i].codcad==codcli)
                    {
                        clienteachado=i;
                    }
                }
                strcpy(reserva[*nReservas].cpfR, cadastroCli[clienteachado].cpf);
                strcpy(reserva[*nReservas].nomeR, cadastroCli[clienteachado].nome);
                if(clienteachado == -1)
                {
                    printf("\ncliente nao encontrado\n");
                }
                reserva[*nReservas].fillial=filial;
                strcpy(reserva[*nReservas].USUARIO, NOME);
                reserva[*nReservas].diaDoAnoEntrada = diaDoAnoEntrada;
                reserva[*nReservas].diaDoAnoSaida = diaDoAnoSaida;
                reserva[*nReservas].numeroQuarto = numeroQuarto;
                reserva[*nReservas].AnoSaida = anoSaida;
                reserva[*nReservas].AnoEntrada = anoEntrada;
                reserva[*nReservas].pg=0;
                printf("\nO codigo da reserva é: %d\n",  reserva[*nReservas].CodRes);
                quebraL = 3;
                (*nReservas)++;

                break;
            case 2:
                system("cls");
                cadastrarCliente(cadastroCli, numClientes);
                break;
            default:
                break;
            }
        }
        while(quebraL!=3);

        p = 2;
    }
    while (p != 2);
    system("pause");
    system("cls");
}
void FazerReservasCliente(ReservaA reserva[], cadastroCliente cadastroCli[],  int *nReservas, int *numClientes)
{
    int p=1, opcreserva, quebraL=1, codcli, codirese, gapDia;
    float precoR;
    do
    {
        recebedordecheckin(reserva, nReservas);
        if(filial==1);
        precoR=PrecificarQuartoF1(numeroQuarto, precoR);
        if(filial==2);
        precoR=PrecificarQuartoF2(numeroQuarto, precoR);
        gapDia=(float)(diaDoAnoSaida-diaDoAnoEntrada);
        precoR*= gapDia;
        reserva[*nReservas].precoreserva = precoR;
        printf("\nData de entrada no dia %d/%d/%d registrada com sucesso!\n", diaEntrada, mesEntrada,anoEntrada);
        printf("\nData de saida no dia %d/%d/%d registrada com sucesso!\n", diaSaida, mesSaida,anoSaida);
        printf("\nCom o preço de R$%2.f\n", precoR);
        reserva[*nReservas].fillial=filial;
        strcpy(reserva[*nReservas].USUARIO, NOME);
        strcpy(reserva[*nReservas].cpfR, CPF);
        strcpy(reserva[*nReservas].nomeR, NOME);
        reserva[*nReservas].diaDoAnoEntrada = diaDoAnoEntrada;
        reserva[*nReservas].diaDoAnoSaida = diaDoAnoSaida;
        reserva[*nReservas].numeroQuarto = numeroQuarto;
        reserva[*nReservas].AnoSaida = anoSaida;
        reserva[*nReservas].AnoEntrada = anoEntrada;
        reserva[*nReservas].pg=0;
        codirese=*nReservas+1501;
        reserva[*nReservas].CodRes = codirese;
        printf("\nO codigo da reserva é: %d\n",  reserva[*nReservas].CodRes);
        (*nReservas)++;
        p=2;
    }
    while (p != 2);
    system("pause");
    system("cls");
}
void ExibirReservas(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas)
{
    int MesE, DiaE, anoE, MesS, DiaS, anoS;
    if(*nReservas!=0)
    {
        printf("\n=================== Lista de Reservas ==================\n");
        printf("\n========================================================\n");
    }
    i=0;
    while(i<*nReservas)
    {
        if(reserva[i].CodRes>1)
        {
            diaDoAnoParaData(reserva[i].diaDoAnoEntrada, &anoE, &DiaE, &MesE);
            diaDoAnoParaData(reserva[i].diaDoAnoSaida, &anoS, &DiaS, &MesS);
            printf("Código da Reserva: %d\n", reserva[i].CodRes);
            printf("Número do Quarto: %d\n", reserva[i].numeroQuarto);
            printf("Data de Entrada: %02d/%02d/%d - Data de Saída: %02d/%02d/%d\n",DiaE, MesE, reserva[i].AnoEntrada,DiaS,MesS, reserva[i].AnoSaida);
            printf("Nome do Cliente: %s\n", reserva[i].nomeR);
            printf("CPF do Cliente: %s\n", reserva[i].cpfR);
            printf("Preço da Reserva: R$%.2f\n", reserva[i].precoreserva);
            printf("feito por: %s\n", reserva[i].USUARIO);
            if(reserva[i].fillial==1)
                printf("Essa Reserva foi feita na filial Master\n");
            if(reserva[i].fillial==2)
                printf("Essa Reserva foi feita na filial Confort\n");
            if(reserva[i].pg==1)
                printf("Essa Reserva já foi paga\n");
            if(reserva[i].pg==0)
                printf("Essa Reserva nao paga\n");
            printf("\n========================================================\n");
            if(reserva[i].CodRes<1)
                printf("\nNão há reservas!\n");
        }
        i++;
    }


    if(*nReservas==0)
        printf("\nNão há reservas!\n");
}
void VerificarDisponibilidade(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas)
{
    int MesE, DiaE, anoE, MesS, DiaS, anoS;
    if(*nReservas!=0)
    {
        printf("\n=================== Lista de Reservas ==================\n");
        printf("\n========================================================\n");
    }
    i=0;
    while(i<*nReservas)
    {
        if(reserva[i].CodRes>1)
        {
            diaDoAnoParaData(reserva[i].diaDoAnoEntrada, &anoE, &DiaE, &MesE);
            diaDoAnoParaData(reserva[i].diaDoAnoSaida, &anoS, &DiaS, &MesS);
            printf("Número do Quarto: %2.d\n", reserva[i].numeroQuarto);
            printf("Data de Entrada: %02.d/%02.d/%d - Data de Saída: %02.d/%02.d/%d\n",DiaE, MesE, reserva[i].AnoEntrada,DiaS,MesS, reserva[i].AnoSaida);
            printf("\n========================================================\n");
            if(reserva[i].CodRes<1)
                printf("\nNão há reservas!\n");
        }
        if(strcmp(reserva[i].nomeR,NOME)==0)
        {
            diaDoAnoParaData(reserva[i].diaDoAnoEntrada, &anoE, &DiaE, &MesE);
            diaDoAnoParaData(reserva[i].diaDoAnoSaida, &anoS, &DiaS, &MesS);
            printf("Código da Reserva: %d\n", reserva[i].CodRes);
            printf("Número do Quarto: %d\n", reserva[i].numeroQuarto);
            printf("Data de Entrada: %02d/%02d/%d - Data de Saída: %02d/%02d/%d\n",DiaE, MesE, reserva[i].AnoEntrada,DiaS,MesS, reserva[i].AnoSaida);
            printf("Nome do Cliente: %s\n", reserva[i].nomeR);
            printf("CPF do Cliente: %s\n", reserva[i].cpfR);
            printf("Preço da Reserva: R$%.2f\n", reserva[i].precoreserva);
            printf("feito por: %s\n", reserva[i].USUARIO);
            if(reserva[i].fillial==1)
                printf("Essa Reserva foi feita na filial Master\n");
            if(reserva[i].fillial==2)
                printf("Essa Reserva foi feita na filial Confort\n");
            if(reserva[i].pg==1)
                printf("Essa Reserva já foi paga\n");
            if(reserva[i].pg==0)
                printf("Essa Reserva nao foi paga\n");
            printf("\n========================================================\n");
            if(reserva[i].CodRes<1)
                printf("\nNão há reservas!\n");
            printf("As outras Datas estão Disponiveis!\n");
        }
        i++;
    }


    if(*nReservas==0)
        printf("\nNão há reservas!\n");

}
void ExibirReservasCliente(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas)
{
    int MesE, DiaE, anoE, MesS, DiaS, anoS;
    if(*nReservas!=0)
    {
        printf("\n=================== Lista de Reservas ==================\n");
        printf("\n========================================================\n");
    }
    i=0;
    while(i<*nReservas)
    {
        if(reserva[i].CodRes>1)
            if(strcmp(reserva[i].nomeR,NOME)==0)
            {
                {
                    diaDoAnoParaData(reserva[i].diaDoAnoEntrada, &anoE, &DiaE, &MesE);
                    diaDoAnoParaData(reserva[i].diaDoAnoSaida, &anoS, &DiaS, &MesS);
                    printf("Código da Reserva: %d\n", reserva[i].CodRes);
                    printf("Número do Quarto: %d\n", reserva[i].numeroQuarto);
                    printf("Data de Entrada: %02d/%02d/%d - Data de Saída: %02d/%02d/%d\n",DiaE, MesE, reserva[i].AnoEntrada,DiaS,MesS, reserva[i].AnoSaida);
                    printf("Nome do Cliente: %s\n", reserva[i].nomeR);
                    printf("CPF do Cliente: %s\n", reserva[i].cpfR);
                    printf("Preço da Reserva: R$%.2f\n", reserva[i].precoreserva);
                    printf("feito por: %s\n", reserva[i].USUARIO);
                    if(reserva[i].fillial==1)
                        printf("Essa Reserva foi feita na filial Master\n");
                    if(reserva[i].fillial==2)
                        printf("Essa Reserva foi feita na filial Confort\n");
                    if(reserva[i].pg==1)
                        printf("Essa Reserva já foi paga\n");
                    if(reserva[i].pg==0)
                        printf("Essa Reserva nao foi paga\n");
                    printf("\n========================================================\n");
                    if(reserva[i].CodRes<1)
                        printf("\nNão há reservas!\n");
                }
                i++;
            }
    }


    if(*nReservas==0)
        printf("\nNão há reservas!\n");

}
void MoverReservas(ReservaA reserva[], int *nReservas)
{
    int procura0 = 0;

    for (int i = 0; i < *nReservas; i++)
    {
        if (reserva[i].CodRes != 0)
        {
            reserva[procura0] = reserva[i];
            procura0++;
        }
    }

    // Preenche o restante do vetor com códigos de reserva 0
    for (int i = procura0; i < *nReservas; i++)
    {
        memset(&reserva[i], 0, sizeof(ReservaA));
    }

    // Atualiza o contador de reservas
    *nReservas = procura0;
}
void CancelarReserva(ReservaA reserva[], int *nReservas)
{
    int acho = 0, caso;
    if (*nReservas == 0)
    {
        printf("\nNao há reservas para cancelar.\n");
        return;
    }


    int codigoreserv;
    printf("Digite o número da reserva que deseja cancelar (0 para cancelar nenhuma): ");
    scanf("%d", &codigoreserv);

    if (codigoreserv == 0)
    {
        printf("Cancelamento de reserva cancelado.\n");
        return;
    }

    for (i = 0; i < *nReservas; i++)
    {
        if (reserva[i].CodRes == codigoreserv)
        {

            memset(&reserva[i], 0, sizeof(ReservaA));
            acho = 1;
            break;
        }
    }

    if (acho==1)
    {
        MoverReservas(reserva, nReservas);
        printf("\n[1]Por favor insira 1 caso seja necessario aplicar multa!\n[1](cancelamento de reserva sendo feito depois de 20 dias de antecedencia)[1]\n");
        printf("[0]Insira 0 caso nao seja necessario aplica multa[0]\n");
        scanf("%d",&caso);
    }
    if(caso==1)
    {
        for (i = 0; i < *nReservas; i++)
        {
            if (reserva[i].CodRes == codigoreserv)
            {

                multa+=reserva[i].CodRes*0.20;
                acho = 1;
                break;
            }
        }

        printf("Reserva cancelada com sucesso.\n");
        system("pause");
    }
    if(acho==0)
    {
        printf("Reserva nao encontrada.\n");
        system("pause");
    }
}
void ConcluirReserva(ReservaA reserva[], Pago reservc[], int *nReservas, int *nReserC)
{
    int acho = 0, caso;
    if (*nReservas == 0)
    {
        printf("\nNão há reservas para concluir.\n");
        return;
    }

    int codigoreserv;
    printf("Digite o número da reserva que deseja concluir (digite 0 para cancelar): ");
    scanf("%d", &codigoreserv);

    if (codigoreserv == 0)
    {
        printf("Conclusão da reserva cancelada.\n");
        return;
    }

    for (int i = 0; i < *nReservas; i++)
    {
        if (reserva[i].CodRes == codigoreserv)
        {
            if(reserva[i].pg==1)
            {
                reservc[*nReserC].AnoEntrada = reserva[i].AnoEntrada;
                reservc[*nReserC].AnoSaida = reserva[i].AnoSaida;
                reservc[*nReserC].diaDoAnoEntrada = reserva[i].diaDoAnoEntrada;
                reservc[*nReserC].diaDoAnoSaida = reserva[i].diaDoAnoSaida;
                reservc[*nReserC].numeroQuarto = reserva[i].numeroQuarto;
                reservc[*nReserC].precoreserva = reserva[i].precoreserva;
                reservc[*nReserC].fillial = reserva[i].fillial;
                (*nReserC)++;
                memset(&reserva[i], 0, sizeof(ReservaA));
                acho = 1;
                break;
            }
            else
            {
                printf("\nOperação Cancelada : Reserva ainda não paga!\n");
            }
        }
    }

    if (acho == 1)
    {
        MoverReservas(reserva, nReservas);
        printf("Reserva concluída com sucesso.\n");
    }
    else
    {
        printf("Reserva não encontrada.\n");
    }
}
void LeitorFaturamento(ReservaA reserva[],Pago reserc[], int *nReservas, int *nReserc)
{
    float soma = 0, somanaopg = 0, somapg = 0, somaS = 0, somanS = 0, somaC = 0, somanC = 0, somaM = 0, somanM = 0, somaP = 0, somanP = 0, somaf=0, somafnpg=0, somafpg=0, somafS=0, somaCf=0, somaMf=0, somaPf=0, soma2=0, soma2npg=0, soma2pg=0, soma2S=0, soma2C=0, somaM2=0, somaP2=0;
    int contreservapg = 0, contreservanaopg = 0, contS = 0,contnS = 0, contC = 0,contnC = 0, contM = 0,contnM = 0, contP = 0,contnP = 0, contreserva=0;
    i = 0;

    while (i < *nReservas)
    {
        if (reserva[i].CodRes > 1500)
        {
            soma += reserva[i].precoreserva;
            contreserva++;
            if (reserva[i].pg == 1)
            {
                somapg += reserva[i].precoreserva;
                contreservapg++;

                if (reserva[i].numeroQuarto >= 1 && reserva[i].numeroQuarto <= 3)
                {
                    somaS += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        somafS+=reserva[i].precoreserva;
                    if(reserva[i].fillial == 2)
                        soma2S += reserva[i].precoreserva;
                    contS++;
                }
                else if (reserva[i].numeroQuarto >= 4 && reserva[i].numeroQuarto <= 6)
                {
                    somaC += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        somaCf+=reserva[i].precoreserva;
                    if(reserva[i].fillial == 2)
                        soma2C += reserva[i].precoreserva;
                    contC++;
                }
                else if (reserva[i].numeroQuarto >= 7 && reserva[i].numeroQuarto <= 9)
                {
                    somaM += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        somaMf+=reserva[i].precoreserva;
                    if(reserva[i].fillial == 2)
                        somaM2 += reserva[i].precoreserva;
                    contM++;
                }
                else if (reserva[i].numeroQuarto >= 10 && reserva[i].numeroQuarto <= 12)
                {
                    somaP += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        somaPf+=reserva[i].precoreserva;
                    if(reserva[i].fillial == 2)
                        somaP2 += reserva[i].precoreserva;
                    contP++;
                }
            }
            else if (reserva[i].pg == 0)
            {
                somanaopg += reserva[i].precoreserva;
                contreservanaopg++;

                if (reserva[i].numeroQuarto >= 1 && reserva[i].numeroQuarto <= 3)
                {
                    somanS += reserva[i].precoreserva;
                    contnS++;
                }
                else if (reserva[i].numeroQuarto >= 4 && reserva[i].numeroQuarto <= 6)
                {
                    somanC += reserva[i].precoreserva;
                    contnC++;
                }
                else if (reserva[i].numeroQuarto >= 7 && reserva[i].numeroQuarto <= 9)
                {
                    somanM += reserva[i].precoreserva;
                    contnM++;
                }
                else if (reserva[i].numeroQuarto >= 10 && reserva[i].numeroQuarto <= 12)
                {
                    somanP += reserva[i].precoreserva;
                    contP++;
                }
            }
        }

        i++;
    }
    i = 0;

    while (i < *nReserc)
    {

        somapg += reserc[i].precoreserva;
        contreservapg++;

        if (reserc[i].numeroQuarto >= 1 && reserc[i].numeroQuarto <= 3)
        {
            somaS += reserc[i].precoreserva;
            if(reserc[i].fillial==1)
                somafS+=reserc[i].precoreserva;
            if(reserc[i].fillial == 2)
                soma2S += reserc[i].precoreserva;
            contS++;
        }
        else if (reserc[i].numeroQuarto >= 4 && reserc[i].numeroQuarto <= 6)
        {
            somaC += reserc[i].precoreserva;
            if(reserc[i].fillial==1)
                somaCf+=reserc[i].precoreserva;
            if(reserc[i].fillial == 2)
                soma2C += reserc[i].precoreserva;
            contC++;
        }
        else if (reserc[i].numeroQuarto >= 7 && reserc[i].numeroQuarto <= 9)
        {
            somaM += reserc[i].precoreserva;
            if(reserc[i].fillial==1)
                somaMf+=reserc[i].precoreserva;
            if(reserc[i].fillial == 2)
                somaM2 += reserc[i].precoreserva;
            contM++;
        }
        else if (reserc[i].numeroQuarto >= 10 && reserc[i].numeroQuarto <= 12)
        {
            somaP += reserc[i].precoreserva;
            if(reserc[i].fillial==1)
                somaPf+=reserc[i].precoreserva;
            if(reserc[i].fillial == 2)
                somaP2 += reserc[i].precoreserva;
            contP++;
        }
        i++;
    }

    printf("\n===========================\n");
    printf("\nFaturamento Geral");
    printf("\nR$%.2f", soma);
    printf("\nForam %d reservas\n", contreserva);
    printf("\n===========================\n");
    printf("\nFaturamento á Receber");
    printf("\nR$%.2f", somanaopg);
    printf("\nForam %d reservas\n", contreservanaopg);
    printf("\n===========================\n");
    printf("\nFaturamento Recebido");
    printf("\nR$%.2f", somapg);
    printf("\nForam %d reservas\n", contreservapg);
    printf("\n===========================\n");
    printf("\nFaturamento Standard");
    printf("\nRecebido");
    printf("\nR$%.2f\tFilial 1:R$%.2f\tFilial 2:R$%.2f", somaS, somafS,soma2S);
    printf("\nA Receber");
    printf("\nR$%.2f", somanS);
    printf("\nForam %d reservas\n", contS);
    printf("\n===========================\n");
    printf("\nFaturamento Confort");
    printf("\nRecebido");
    printf("\nR$%.2f\tFilial 1:R$%.2f\tFilial 2:R$%.2f", somaC, somaCf,soma2C);
    printf("\nA Receber");
    printf("\nR$%.2f", somanC);
    printf("\nForam %d reservas\n", contC);
    printf("\n===========================\n");
    printf("\nFaturamento Master");
    printf("\nRecebido");
    printf("\nR$%.2f\tFilial 1:R$%.2f\tFilial 2:R$%.2f", somaM, somaMf,somaM2);
    printf("\nA Receber");
    printf("\nR$%.2f", somanM);
    printf("\nForam %d reservas\n", contM);
    printf("\n===========================\n");
    printf("\nFaturamento Presidencial");
    printf("\nRecebido");
    printf("\nR$%.2f\tFilial 1:R$.2f\tFilial 2:R$.2f", somaP, somaPf,somaP2);
    printf("\nA Receber");
    printf("\nR$%.2f", somanP);
    printf("\nForam %d reservas\n", contP);
    printf("\n===========================\n");
    system("pause");
}

void definirCorConsole()
{
    int planoDeFundo, texto;

    char cores[16][20] =
    {
        "Preto", "Azul Escuro", "Verde Escuro", "Ciano Escuro", "Vermelho Escuro", "Magenta Escuro", "Amarelo Escuro", "Cinza Claro",
        "Cinza Escuro", "Azul Claro", "Verde Claro", "Ciano Claro", "Vermelho Claro", "Magenta Claro", "Amarelo Claro", "Branco"
    };

    // Exibir tradução de cores
    printf("Tradução de Cores:\n");
    for (int i = 0; i < 16; i++)
    {
        printf("%d - %s\n", i, cores[i]);
    }

    printf("\nEscolha a cor do plano de fundo (0-15): ");
    scanf("%d", &planoDeFundo);

    printf("Escolha a cor do texto (0-15): ");
    scanf("%d", &texto);

    // Verifique se as cores escolhidas estão no intervalo válido (0-15)
    if (planoDeFundo >= 0 && planoDeFundo <= 15 && texto >= 0 && texto <= 15)
    {
        // Use o comando "color" para definir as cores do plano de fundo e do texto
        char comando[20];
        snprintf(comando, sizeof(comando), "color %X%X", planoDeFundo, texto);
        system(comando);
        printf("Cores definidas: Plano de Fundo - %s, Texto - %s\n", cores[planoDeFundo], cores[texto]);
    }
    else
    {
        printf("Cores fora do intervalo válido (0-15).\n");
    }
}

void definidorfuncionarios(funcionarios Funcionarios[], int *nFuncionarios)
{
    strcpy(Funcionarios[0].nome,"Dorcas");
    strcpy(Funcionarios[0].senha,"0000");
    Funcionarios[0].cargo=1;
    (*nFuncionarios)++;
    strcpy(Funcionarios[1].nome,"Murilo");
    strcpy(Funcionarios[1].senha,"123");
    Funcionarios[1].cargo=1;
    (*nFuncionarios)++;

    strcpy(Funcionarios[2].nome,"Adrian");
    strcpy(Funcionarios[2].senha,"123");
    Funcionarios[2].cargo=1;
    (*nFuncionarios)++;

    strcpy(Funcionarios[3].nome,"Joao");
    strcpy(Funcionarios[3].senha,"123");
    Funcionarios[3].cargo=1;
    (*nFuncionarios)++;

    strcpy(Funcionarios[4].nome,"Giovana");
    strcpy(Funcionarios[4].senha,"123");
    Funcionarios[4].cargo=1;
    (*nFuncionarios)++;
}


int recebedordecheckin(ReservaA reserva[], int*nReservas)
{
    int VerOut=0, VerSob, valin, compin, valout, compout;
    do
    {
        printf("\n---------------Fazer uma Reserva---------------\n");
        printf("\n===============STANDARD==============\n");
        printf("[1]Quarto\t");
        printf("[2]Quarto\t");
        printf("[3]Quarto");
        printf("\n===============COMFORT===============\n");
        printf("[4]Quarto\t");
        printf("[5]Quarto\t");
        printf("[6]Quarto");
        printf("\n===============MASTER================\n");
        printf("[7]Quarto\t");
        printf("[8]Quarto\t");
        printf("[9]Quarto");
        printf("\n=============PRESIDENCIAL============\n");
        printf("[10]Quarto\t");
        printf("[11]Quarto\t");
        printf("[12]Quarto");
        printf("\nDigite o numero do quarto:\n");

        scanf("%d", &numeroQuarto);
        fflush(stdin);


    }
    while(numeroQuarto < 1 || numeroQuarto > 12);
    do
    {
        do
        {
            printf("\nDigite a data de Check-in desta forma DD/MM/AAAA:");
            scanf("%d/%d/%d", &diaEntrada, &mesEntrada, &anoEntrada);
            fflush(stdin);
            valin = ValidarDatas( diaEntrada,  mesEntrada,  anoEntrada) ;
            compin = CompararDataAtual ( diaEntrada,  mesEntrada, anoEntrada);  //compara data com a atual
            if (valin == 0) //valida datas (invalida)
            {
                printf("\n\t|xxxxx|-Data de Check-in Inválida-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }
            if (compin == -1) //compara data com a atual(invalida)
            {
                printf("\n\t|xxxxx|-Data de Check-in já passou-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }
        }
        while (valin  != 1 || compin != 0);
        do
        {
            printf("Digite a data de Check-out desta forma DD/MM/AAAA:");
            scanf("%d/%d/%d", &diaSaida, &mesSaida, &anoSaida);
            fflush(stdin);
            valout = ValidarDatas(diaSaida, mesSaida, anoSaida);
            compout =  CompararDataAtual ( diaSaida,  mesSaida, anoSaida);
            if (valout == 0) //valida datas (invalida)
            {
                printf("\n\t|xxxxx|-Data de Check-out Inválida-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }
            if (compout == 1) //compara data com a atual
            {
                printf("\n\t|xxxxx|-Data de Check-out já passou-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }

            diaDoAnoEntrada = dataParaDiaDoAno(diaEntrada, mesEntrada, anoEntrada);
            diaDoAnoSaida = dataParaDiaDoAno(diaSaida, mesSaida, anoSaida);

            if (diaDoAnoEntrada < diaDoAnoSaida)
            {
                VerOut = 1;
            }
            else if (anoEntrada<=anoSaida)
            {
                VerOut = 1;
            }
            if (anoEntrada>anoSaida)
            {
                VerOut=0;
            }
            if (VerOut != 1)
            {
                printf("\n\t|xxxxx|-Data de Check-out Inválida (data de check-out menor que à data de check-in)-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }

        }
        while (valout != 1 || compout !=0 || VerOut != 1); //valida datas e quebra looping (ir para proxima etapa)
        VerSob = VerificarSobreposicao(reserva, *nReservas, numeroQuarto, diaDoAnoEntrada, diaDoAnoSaida);

        if (VerSob == 1)
        {
            printf("\n\t|xxxxx|-Conflito de datas com outra reserva-|xxxxx|\n");
            printf("\nPor Favor Insira Novamente:\n");
        }
    }
    while (VerSob != 0);
}

int boleto(nClientes, client, reservas);
int formaPagamento(int nClientes, cadastroCliente client[], ReservaA reserva[])
{

    int opcao;

    printf("\n|================================\n");
    printf("|======Formas de Pagamentos======\n");
    printf("|[1]Cartao\n"); //credito // debito
    printf("|[2]Dinheiro\n");
    printf("|[3]Boleto\n");
    printf("|[4]pix\n");
    printf("|[0]Cancelar\n");
    printf("|================================\n");
    printf("Digite a forma de pagamento: ");
    scanf("%d", &opcao);
    //system("cls");
    switch (opcao)
    {
    case 1:
        printf("\n________________________________________________________________________________________________________\n");
        printf("\t\t\t\t\tPagamento em Cartão.");
        printf("\n________________________________________________________________________________________________________\n");
        cartao();
        printf("\n________________________________________________________________________________________________________\n");

        break;
    case 2:
        printf("\n________________________________________________________________________________________________________\n");
        printf("\t\tPagamento em Dinheiro.");
        printf("Seu pagamento será cobrado no Check-out!\n");
        printf("\n________________________________________________________________________________________________________\n");
        system("pause");
        break;
    case 3:
        printf("\n________________________________________________________________________________________________________\n");
        printf("\t\t\t\t\tPagamento em Boleto.");
        printf("\n========================================================================================================\n");
        boleto(nClientes, client, reserva);//pagamento contabila automanticamente
        break;
    case 4:
        printf("\n________________________________________________________________________________________________________\n");
        printf("\t\t\t\t\tPagamento em Pix.");
        printf("\n________________________________________________________________________________________________________\n");
        printf("Chave pix: \n\t12 345 678 0001 00");
        printf("\n________________________________________________________________________________________________________\n");

        break;
    case 0:
        printf("Pagamento cancelado.\n");
        break;
    default:
        printf("Opção inválida.\n");
        break;
    }
    return 0;
}
void cliente(nClientes, client);
void valorReserva(nClientes,reservas);
int boleto(int nClientes, cadastroCliente client[], ReservaA reserva[])
{

    int numDoc;
    numDoc++;
    time_t agora = time(NULL);
    char hoje[20];
    strftime(hoje, sizeof(hoje), "%d/%m/%Y", localtime(&agora));

    printf("\n________________________________________________________________________________________________________\n");
    printf("Nome do Beneficiario: \t\t\t\t\t\t\t| CNPJ:");
    printf("\n\tHotel suite confort \t\t\t\t\t\t| 12.345.678/0001-00");
    printf("\n________________________________________________________________________|_______________________________\n");
    printf("Data do Documento\t\t|N Do Documento: \t\t|Valor:");
    printf("\n\tData: %s \t|", hoje);
    numeroDoc(numDoc);
    printf("\t|");
    valorReserva(nClientes,reserva);
    printf("\n________________________________|_______________________________|_______________________________________\n");
    cod();
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("Local de Pagamento:\t\t\t\t\t| Vencimento:\n");
    printf("\tEm qualquer banco ate o vencimento\t\t|");
    printf("\tvencimento");
    printf("\n________________________________________________________|_______________________________________________\n");
    printf("Instrucoes:\n\n");
    printf("1) NAO ACEITAR PAGAMENTO EM CHEQUE\n\n");
    printf("2) NAO ACEITAR MAIS DE UM PAGAMENTO COM O MESMO BOLETO\n\n");
    printf("3) EM CASO DE VENCIMENTO NO FIM DE SEMANA OU FERIADO, ACEITAR O PAGAMENTO ATE O PRIMEIRO DIAS UTIL APOS \nO VENCIMENTOS\n");
    printf("\n\n________________________________________________________________________________________________________\n");
    printf("Beneficiario:\n\n");
    enderecoMatriz();
    printf("\n________________________________________________________________________________________________________\n");
    printf("Pagador:\n");
    cliente(nClientes, client);
    printf("\n________________________________________________________________________________________________________\n\n");
    codBarra();
    return 0;
}

void numeroDoc(int *numDoc)
{
    printf("\t001230045600789.%d", numDoc);
    return;
}

void cod()
{
    int cont = 0;
    int numeros[48];

    printf("\n--------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 47; i++)
    {
        numeros[i] = rand() % 10;
    }
    printf("\n\n");
    for (int i = 0; i < 47; i++)
    {
        if (cont <= 0)
        {
            printf("\t\t\t\t\t| 123-4 | ");
        }
        printf("%d", numeros[i]);
        if(cont == 5)
        {
            printf(".");
        }
        if(cont == 10)
        {
            printf(" ");
        }
        if(cont == 15)
        {
            printf(".");
        }
        if(cont == 21)
        {
            printf(" ");
        }
        if(cont == 26)
        {
            printf(".");
        }
        if(cont == 32)
        {
            printf(" ");
        }
        if(cont == 33)
        {
            printf(" ");
        }
        cont++;
    }
    printf("\n");

    return;
}

void codBarra()
{
    int cont = 0;
    for (int j = 0; j < 2; j++)
    {
        if(cont <= 0)
        {
            printf("\t\t\t\t\t\t|");
        }
        if(cont == 1)
        {
            printf("\t\t\t\t\t\t|");
        }
        cont++;
        for (int i = 0; i < 8; i++)
        {
            printf("|||||| ");
        }
        printf("\n");
    }
    printf("\n--------------------------------------------------------------------------------------------------------\n");
}

void valorReserva(int nclientes, ReservaA reserva[])
{

    printf("\tR$ %.2f", reserva[nclientes - 1].precoreserva);
}

void enderecoMatriz()
{
    printf("\tSuites Algaritmos:\n");
    printf("\tEndereco: Araraquara-SP");
    return;
}

void cliente(int nClientes, cadastroCliente client[])
{

    printf("\t%s\n", client[nClientes - 1].nome);
    int opcao;
    printf("\t\t\t\t\tCodigo de Barra");
    return;
}

void cartao()
{
    int opcao, dia, mes, ano;
    printf("Dorcas Chagas\n");
    printf("CPF: 123456789-10\n");

    char numero_cartao[50] = "1234-5678-9012-3456";
    int codigo_seguranca;

    printf("\n\nNº cartao: 0000-0000-0000-0000\n");
    scanf("d%d%d%d-d%d%d%d-d%d%d%d-d%d%d%d-",&numero_cartao);

    printf("Data de validade: dd/mm/yyyy");
    scanf("%d/%d/%d/",&dia, &mes, &ano);
    fflush(stdin);

    printf("\nCód de segurança: 000");
    scanf("%d",&codigo_seguranca);
    return;
}


void confirmarPagamento(ReservaA reserva[], int *nReservas)
{
    int opcao,codigorese,reservaachada;
    printf("\nDigite o codigo de rserva:\n");
    scanf("%d", &codigorese);
    if(*nReservas>0)
    {

        for(i=0; i<*nReservas; i++)
        {
            if(codigorese==reserva[i].CodRes)
                reservaachada=i;
        }

    }
    if(*nReservas==0)
        printf("\nNão há reservas!");
    do
    {
        printf("\n\nConfirmar pagamento [1][sim]  [2][cancelar]\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Pagamento confirmado!\n");
            break;
        case 2:
            printf("Pagamento cancelado!\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    while(opcao < 0 || opcao > 2);



    if(opcao == 1)
    {
        reserva[reservaachada].pg = 1;
    }
    printf("\n%d", reserva[reservaachada].pg);
    system("pause");
    return;
}

