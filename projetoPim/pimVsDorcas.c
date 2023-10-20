#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

int i;

typedef struct
{
    char nome[50], cpf[12];
    int codcad;
} cadastroCliente;

typedef struct
{
    int numeroQuarto, diaDoAnoEntrada,diaDoAnoSaida, AnoEntrada, AnoSaida, CodRes, pg; //pg quando 0 significa nao pg, quando 1 siginifica pg

    char nomeR[50], cpfR[12];
    float precoreserva;
} ReservaA;

void exibirClientes(cadastroCliente clientes[], int *numClientes);
void cadastrarCliente(cadastroCliente clientes[], int *numClientes);
void FazerReservas(ReservaA reserva[], cadastroCliente cadcli[],  int *nReservas, int *numClientes);
void ExibirReservas(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas);
void CancelarReserva(ReservaA reserva[], int *nReservas);
void LeitorFaturamento(ReservaA reserva[], int *nReservas);
void definirCorConsole();
int CompararDataAtual (int Dia, int Mes, int Ano);
int ValidarDatas(int dia, int mes, int ano);
int dataParaDiaDoAno(int dia, int mes, int ano);
int VerificarSobreposicao(ReservaA reserva[], int nReservas, int numeroQuarto, int diaDoAnoEntrada, int diaDoAnoSaida);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    cadastroCliente client[1000];
    ReservaA reservas[366];
    int numReservas = 0, nClientes =0;
    int filial, opc;

    //=====================================================
    //=======================login=========================
    login();
    system("cls");

    do
    {
        system("cls");
        printf("\n|------------------Bem vindo a rede Hotel Algoritmo Suites-------------------|\n");
        printf("   \n|1.Escolha 1 para a filial 1 - Master.............................|");
        printf("\n|2.Escolha 2 para a filial 2 - Confort............................|");
        printf("\n|3.Escolha 3 para encerrar o programa.............................|\n");
        scanf("%d", &filial);
        //system("pause");
        system("cls");

        switch (filial)
        {
        case 1:
            do
            {
                system("cls");
                mensagemMenu();
                scanf("%d", &opc);
                system("cls");

                switch (opc)
                {
                case 1:
                    system("cls");
                    FazerReservas(reservas, client, &numReservas, &nClientes);
                    break;
                case 2:
                    //=====================================================
                    //=====================clientes========================
                    cadastrarCliente(client, &nClientes);
                    break;
                case 3:
                    //=====================================================
                    //====================relatorio========================
                    ExibirReservas(reservas, client, &numReservas);
                    system("pause");
                    break;
                case 4:
                    break;
                case 5:
                    ExibirReservas(reservas, client, &numReservas);
                    CancelarReserva(reservas, &numReservas);
                    break;
                case 6:
                    exibirClientes(client, &nClientes);
                    system("pause");
                    break;
                case 7:
                    LeitorFaturamento(reservas, &numReservas);
                    break;
                    case 9:
                        definirCorConsole();
                        break;
                default:
                    printf("opcao invalida");
                    break;
                case 10:
                    return 0;
                    break;
                }
            }
            while (opc != 13);
            break;
        case 2:
            printf("\nEscolheu filial 2\n");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("\nO programa foi encerrado\n");
            break;
        default:
            printf("\nopcao invalida\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(filial != 3);

    //=====================================================
    //=====================Quartos=========================

    return 0;
}
void login()
{

    char nome1[50];
    char senha[10];
    //nome--------------------------------------
    do
    {
        printf("\nUsuario: ");
        scanf("%s", &nome1);
    }
    while(strcmp(nome1,"Dorcas"));
    //senha-------------------------------------
    do
    {
        printf("Senha: ");
        scanf("%s", &senha);
    }
    while(strcmp(senha,"0000"));

}

//============================================================================================
//========================================Clientes===========================================
void cadastrarCliente(cadastroCliente client[], int *nClientes)
{
    cadastroCliente novoCliente;
    int numpessoas;
    printf("Quantos pessoas?");
    scanf("%d", &numpessoas);
    for(i=0; i<numpessoas; i++)
    {
        printf("Digite o nome do cliente: ");
        scanf(" %[^\n]", novoCliente.nome);

        printf("Digite o CPF do cliente: ");
        scanf(" %s", novoCliente.cpf);

        novoCliente.codcad=*nClientes+1;

        client[*nClientes] = novoCliente;
        (*nClientes)++;
    }
    printf("Cliente cadastrado com sucesso.\n");

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
void mensagemMenu()
{
    printf(" \n______________________________________________________ ");
    printf("\n|-------Bem-vindo ao Algoritmo Suites Master-----------|");
    printf("\n ______________________________________________________ ");
    printf("\n|-------------------------Menu-------------------------|");
    printf("\n|______________________________________________________|\n");
    printf("\n1|Escolha 1 para fazer uma reserva.....................|");
    printf("\n2|Escolha 2 para Cadastro de clientes..................|");
    printf("\n3|Escolha 3 para visualizar as reservas................|");
    printf("\n4|Escolha 4 para fazer Check-in e Check-out............|");
    printf("\n5|Escolha 5 para cancelar reserva......................|");
    printf("\n6|Escolha 6 para ver clientes..........................|");
    printf("\n7|Escolha 7 para ver relatorio de faturamento..........|");
    printf("\n\n10|Escolha 10 para sair do sistema...................|\n\n");
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
        if (reserva[i].numeroQuarto == numeroQuarto)
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
    float precoS1=650.00, precoC1=850.00, precoM1=1150.00, precoP1=1750.00;
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
// Função de comparação para ordenar as reservas com base na data de check-in


void FazerReservas(ReservaA reserva[], cadastroCliente cadastroCli[],  int *nReservas, int *numClientes)
{
    int anoEntrada, mesEntrada, diaEntrada, anoSaida, mesSaida, diaSaida, diaDoAnoEntrada, diaDoAnoSaida, VerOut=0, VerSob, numeroQuarto, valin, valout,compin, compout, p=1, opcreserva, quebraL=1, codcli, codirese, gapDia;
    float precoR;
    float precoS2=(450,00), precoC2=(550,00), precoM2=(750,00);
    do
    {
        do
        {
            printf("\n---------------Fazer uma Reserva---------------\n");
            printf("\nDigite o numero do quarto:\n");
            scanf("%d", &numeroQuarto);
            fflush(stdin);
            system("cls");

        }
        while(numeroQuarto<1 && numeroQuarto>12);
        // recebi o quarto de 1 ate 13


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
            while (valin  != 1 || compin != 0); //valida datas valida e quebra looping (ir para proxima etapa)
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
                else if (VerOut != 1)
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

        precoR=PrecificarQuartoF1(numeroQuarto, precoR);
        gapDia=(float)(diaDoAnoSaida-diaDoAnoEntrada);
        precoR*= gapDia;
        reserva[*nReservas].precoreserva = precoR;

        // Registre o número do dia do ano nas reservas
        // Use os valores de diaDoAnoEntrada e diaDoAnoSaida conforme necessário
        printf("\nData de entrada no dia %d/%d/%d registrada com sucesso!\n", diaEntrada, mesEntrada,anoEntrada);
        printf("\nData de saida no dia %d/%d/%d registrada com sucesso!\n", diaSaida, mesSaida,anoSaida);
        printf("\nCom o preço de R$%2.f\n", precoR);
        do
        {
            printf("\nVoce deseja:\n");
            printf("\n 1 - Escoher um cliente?");
            printf("\n 2 - Cadastrar novo cliente?\n");
            scanf("%d", &opcreserva);

            codirese=*nReservas+1501;
            reserva[*nReservas].CodRes = codirese;
            switch(opcreserva)
            {
            case 1:
                system("cls");
                exibirClientes(cadastroCli, numClientes);
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

                reserva[*nReservas].diaDoAnoEntrada = diaDoAnoEntrada;
                reserva[*nReservas].diaDoAnoSaida = diaDoAnoSaida;
                reserva[*nReservas].numeroQuarto = numeroQuarto;
                reserva[*nReservas].AnoSaida = anoSaida;
                reserva[*nReservas].AnoEntrada = anoEntrada;
                quebraL = 3;

                do
                {
                    printf("==================Pagamento==================");
                    printf("=============================================");
                    printf("\nDigite 1 caso valor tennha sido recebido \n");
                    printf("Digite 0 caso valor não tennha sido recebido\n ");
                    scanf("%d", &reserva[*nReservas].pg);
                }
                while(reserva[*nReservas].pg!=0 &&reserva[*nReservas].pg!=1);
                printf("\nO codigo da reserva é: %d\n",  reserva[*nReservas].CodRes);
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
            printf("Número do Quarto: %2.d\n", reserva[i].numeroQuarto);
            printf("Data de Entrada: %2.d/%2.d/%d - Data de Saída: %2.d/%2.d/%d\n",DiaE, MesE, reserva[i].AnoEntrada,DiaS,MesS, reserva[i].AnoSaida);
            printf("Nome do Cliente: %s\n", reserva[i].nomeR);
            printf("CPF do Cliente: %s\n", reserva[i].cpfR);
            printf("Preço da Reserva: R$%.2f\n", reserva[i].precoreserva);
            printf("\n========================================================\n");
            if(reserva[i].CodRes<1)
                printf("\nNão há reservas!\n");
        }
        i++;
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

    int acho = 0;
    for (i = 0; i < *nReservas; i++)
    {
        if (reserva[i].CodRes == codigoreserv)
        {
            memset(&reserva[i], 0, sizeof(ReservaA));
            acho = 1;
            break;
        }
    }

    if (acho)
    {
        MoverReservas(reserva, nReservas);
        printf("Reserva cancelada com sucesso.\n");
    }
    else
    {
        printf("Reserva nao encontrada.\n");
    }
}
void LeitorFaturamento(ReservaA reserva[], int *nReservas)
{
    float soma = 0, somanaopg = 0, somapg = 0, somaS = 0, somanS = 0, somaC = 0, somanC = 0, somaM = 0, somanM = 0, somaP = 0, somanP = 0;
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
                    contS++;
                }
                else if (reserva[i].numeroQuarto >= 4 && reserva[i].numeroQuarto <= 6)
                {
                    somaC += reserva[i].precoreserva;
                    contC++;
                }
                else if (reserva[i].numeroQuarto >= 7 && reserva[i].numeroQuarto <= 9)
                {
                    somaM += reserva[i].precoreserva;
                    contM++;
                }
                else if (reserva[i].numeroQuarto >= 10 && reserva[i].numeroQuarto <= 12)
                {
                    somaP += reserva[i].precoreserva;
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
    printf("\nR$%.2f", somaS);
    printf("\nA Receber");
    printf("\nR$%.2f", somanS);
    printf("\nForam %d reservas\n", contS);
    printf("\n===========================\n");
    printf("\nFaturamento Confort");
    printf("\nRecebido");    printf("\nR$%.2f", somaC);
    printf("\nA Receber");
    printf("\nR$%.2f", somanC);
    printf("\nForam %d reservas\n", contC);
    printf("\n===========================\n");
    printf("\nFaturamento Master");
    printf("\nRecebido");
    printf("\nR$%.2f", somaM);
    printf("\nA Receber");
    printf("\nR$%.2f", somanM);
    printf("\nForam %d reservas\n", contM);
    printf("\n===========================\n");
    printf("\nFaturamento Presidencial");
    printf("\nRecebido");
    printf("\nR$%.2f", somaP);
    printf("\nA Receber");
    printf("\nR$%.2f", somanP);
    printf("\nForam %d reservas\n", contP);
    printf("\n===========================\n");
    system("pause");
}

void definirCorConsole() {
    int planoDeFundo, texto;

    char cores[16][20] = {
        "Preto", "Azul Escuro", "Verde Escuro", "Ciano Escuro", "Vermelho Escuro", "Magenta Escuro", "Amarelo Escuro", "Cinza Claro",
        "Cinza Escuro", "Azul Claro", "Verde Claro", "Ciano Claro", "Vermelho Claro", "Magenta Claro", "Amarelo Claro", "Branco"
    };

    // Exibir tradução de cores
    printf("Tradução de Cores:\n");
    for (int i = 0; i < 16; i++) {
        printf("%d - %s\n", i, cores[i]);
    }

    printf("\nEscolha a cor do plano de fundo (0-15): ");
    scanf("%d", &planoDeFundo);

    printf("Escolha a cor do texto (0-15): ");
    scanf("%d", &texto);

    // Verifique se as cores escolhidas estão no intervalo válido (0-15)
    if (planoDeFundo >= 0 && planoDeFundo <= 15 && texto >= 0 && texto <= 15) {
        // Use o comando "color" para definir as cores do plano de fundo e do texto
        char comando[20];
        snprintf(comando, sizeof(comando), "color %X%X", planoDeFundo, texto);
        system(comando);
        printf("Cores definidas: Plano de Fundo - %s, Texto - %s\n", cores[planoDeFundo], cores[texto]);
    } else {
        printf("Cores fora do intervalo válido (0-15).\n");
    }
}

