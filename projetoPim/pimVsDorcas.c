#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

int qtdPessoas = 0, tq, valorQuarto = 0, entDia, aaaa = 0, mm = 0, dd = 0, totDiasMes, totalDias, i ;

typedef struct
{
    char nome[50], cpf[12];
}cadastroCliente;

typedef struct
{
    int numeroQuarto, diaDoAnoEntrada,diaDoAnoSaida, AnoEntrada, AnoSaida;
    char nomeR, cpfR;
} ReservaA;
void FazerReservas(ReservaA reserva[], int *nReservas);
int CompararDataAtual (int Dia, int Mes, int Ano);
int ValidarDatas(int dia, int mes, int ano);
int dataParaDiaDoAno(int dia, int mes, int ano);
int VerificarSobreposicao(ReservaA reserva[], int nReservas, int numeroQuarto, int diaDoAnoEntrada, int diaDoAnoSaida);


int main()
{
    setlocale(LC_ALL, "Portuguese");

    cadastroCliente cadastroCl[1000];
    ReservaA reservas[366];
    int numReservas = 0;
    int filial, opc;

    //=====================================================
    //=======================login=========================
    login();
    system("cls");

    do
    {
        system("cls");
        printf("\n|------------------Bem vindo a rede Hotel Algoritmo Suites-------------------|\n");
        printf("\n|1.Escolha 1 para a filial 1 - Master.............................|");
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
                    FazerReservas(reservas, &numReservas);
                    break;
                case 2:
                    //=====================================================
                    //=====================clientes========================
                    printf("Quantas pessoas:");
                    scanf("%d", &qtdPessoas);
                    fflush(stdin);
                    for(int i = 0; i < qtdPessoas; i++)
                    {
                        cliente(&cadastroCl[i]);
                    }
                    break;
                case 3:
                    //=====================================================
                    //====================relatorio========================
                    system("cls");
                    relatorio(cadastroCl);
                    break;
                case 4:
                    break;
                case 5:

                    break;
                case 6:
                    system("cls");
                    relatorio(cadastroCl);
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    break;
                case 8:
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
int cliente(cadastroCliente *cadastroCl)
{
    printf("Nome:");
    scanf("%s", cadastroCl->nome);
    printf("CPF:");
    scanf("%s", cadastroCl->cpf);
    printf("\n===================================\n");
    return 0;
}
//============================================================================================
//=======================================relatorio============================================
int relatorioR(ReservaA reservas[], int *nReservas){

for(i=0;i<*nReservas;i++){
    printf("%s");
    printf("%s");
    printf("%d");
    printf("%d");
}
}
int relatorio(cadastroCliente cadastroCl[])
{

    for(int i = 0; i < qtdPessoas; i++)
    {
        printf("Nome: %s\n", cadastroCl[i].nome);
        printf("CPF: %s\n", cadastroCl[i].cpf);
        printf("===================================\n");
    }
    return 0;
}
//============================================================================================
//======================================reserva Datas=========================================
/*int datasEntradas(struct dataEntrada *entrada, int ano, int mes, int dia){
    entrada->entradaAno = ano;
    entrada->entradaMes = mes;
    entrada->entradaDia = dia;
    return 0;
}*/

/*int mostraDataEnt(struct dataEntrada entrada){
    return printf("Data reserva %d/%d/%d\n", entrada.entradaAno, entrada.entradaMes, entrada.entradaDia);
}

void mostrarDataSai(struct dataEntrada entrada, int totDias){
    int diaSaida =  entrada.entradaDia + totDias;

    if(diaSaida > 30){
        entrada.entradaMes++;
        if(entrada.entradaMes <= 12 ){
            entrada.entradaDia = entrada.entradaDia + totDias - totDiasMes;// + 31 - totDias valorNovoDia
            //entrada.entradaMes = 1;
            printf("Data de Check-out: %d/%d/%d\n", entrada.entradaAno, entrada.entradaMes,entrada.entradaDia );
        }
        if(entrada.entradaMes > 12){
            entrada.entradaDia = entrada.entradaDia + totDias - totDiasMes;
            entrada.entradaMes = 1;
            entrada.entradaAno++;
            printf("Data de Check-out: %d/%d/%d\n", entrada.entradaAno, entrada.entradaMes, entrada.entradaDia);
        }
    } else {
        printf("Data de Check-out: %d/%d/%d\n", entrada.entradaAno, entrada.entradaMes, diaSaida);
    }

    printf("\n|---------------------------------------------|\n");
    system("pause");
    system("cls");
    return 0;
}*/

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
//============================================================================================
//========================================Quartos=============================================



/*int menu(){
    printf("\nGlossario de reserva\n");
    printf("\n1-----------Standard-----------1");
    printf("\nvalor da Diária: R$:50,00\n");
    printf("\n2-----------Comfort------------2");
    printf("\nvalor da Diária: R$:75,00\n");
    printf("\n3------------Master------------3");
    printf("\nvalor da Diária: R$:100,00\n");
    printf("\n4---------Presidencial---------4");
    printf("\nvalor da Diária: R$:150,00\n");
    printf("\n0------------SAIR--------------0\n");
    scanf("%d", &tq);//tipo de quarto
    fflush(stdin);
    system("cls");
    switch(tq){
    case 1:
        system("cls");
        printf("\n|------------------Suite Standard---------------|\n");
        valorQuarto = 50;
        break;
    case 2:
        system("cls");
        printf("\n|--------------Suite Comfort---------------|\n");
        valorQuarto = 75;
        break;
    case 3:
        system("cls");
        printf("\n|---------------Suite Master---------------|\n");
        valorQuarto = 100;
        break;
    case 4:
        system("cls");
        printf("\n|------------Suite Presidencial---------------|\n");
        valorQuarto = 150;
        break;
    case 0:
        printf("Saindo do sistema...\n");
        exit(0);
        break;
    default:
        printf("Opção inválida\n");
        break;
    }
}*/

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

    if ((mes <= 7 && mes % 2 != 0 ) || mes > 7 && mes % 2 == 0)
    {
        if (dia >= 1 && dia <= 31)
        {
            return 1; // Data válida
        }
    }
    else if (!mes == 2 && (mes <= 7 && mes % 2 == 0) || mes > 7 && mes % 2 != 0)
    {
        if (dia >= 1 && dia <= 30)
        {
            return 1;
        }
    }
    else if (mes == 2)
    {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        {
            if (dia >= 1 && dia <= 29)
            {
                return 1;
            }
        }
        else
        {
            if (dia >= 1 && dia <= 28)
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
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

void FazerReservas(ReservaA reserva[], int *nReservas)
{
    int anoEntrada, mesEntrada, diaEntrada, anoSaida, mesSaida, diaSaida, diaDoAnoEntrada, diaDoAnoSaida, VerOut, VerSob, numeroQuarto, valin, valout,compin, compout, p=1;

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
                printf("%d", compin);
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
                    printf("\n\t|xxxxx|-Data de Check-out Inválida (data de check-out menor ou igual à de check-in)-|xxxxx|\n");
                    printf("\nPor Favor Insira Novamente:\n");
                }

                VerSob = VerificarSobreposicao(reserva, *nReservas, numeroQuarto, diaDoAnoEntrada, diaDoAnoSaida);

                if (VerSob == 1)
                {
                    printf("\n\t|xxxxx|-Conflito de datas com outra reserva-|xxxxx|\n");
                    printf("\nPor Favor Insira Novamente:\n");
                }

            }
            while (valout != 1 && VerOut != 1 && compout !=0 && compout !=1); //valida datas e quebra looping (ir para proxima etapa)
        }
        while (valout != 1 && VerOut != 1 && VerSob == 1);

        // Registre o número do dia do ano nas reservas
        reserva[*nReservas].diaDoAnoEntrada = diaDoAnoEntrada;
        reserva[*nReservas].diaDoAnoSaida = diaDoAnoSaida;
        reserva[*nReservas].numeroQuarto = numeroQuarto;
        reserva[*nReservas].AnoSaida= anoSaida;
        reserva[*nReservas].AnoEntrada= anoEntrada;

        // Use os valores de diaDoAnoEntrada e diaDoAnoSaida conforme necessário
        p = 2;
        printf("\nReserva registrada com sucesso!\n");
        system("pause");
        system("cls");
        (*nReservas)++;
    }
    while (p != 2);
}

