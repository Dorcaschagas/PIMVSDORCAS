#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
//criar estrutura de preco de quarto de 1 ao  3 de 4 ao 6  de 7 ao 9 de 10 ao 12
//definir valores de suite e tipos de suite
//fazer uma logica de dias da reserva para o preco da suite, utilizando funcoes para relatorio de faturamento
typedef struct
{
    int numeroQuarto, diaDoAnoEntrada,diaDoAnoSaida, AnoEntrada, AnoSaida;
} ReservaA;


int VerificarSobreposicao(ReservaA reserva[], int nReservas, int numeroQuarto, int diaDoAnoEntrada, int diaDoAnoSaida);

int dataParaDiaDoAno(int dia, int mes, int ano);

int ValidarDatas(int dia, int mes, int ano) ;

void FazerReservas(ReservaA reserva[], int *nReservas);

int CompararDataAtual (int Dia, int Mes, int Ano);


int main()
{
    setlocale(LC_ALL, "PORTUGUESE");
    ReservaA reservas[366];
    int numReservas = 0;
    char usuario[20] = "Murilo", usuarioA[20], senha[20] = "123", senhaA[20];
    int filial;
    ReservaA reservaa;
    printf("|------------|Bem-vindo ao sistema de reserva de hotel|------------|");
    do
    {
        printf("\n\nUsuario:\n");
        scanf("%s", &usuarioA);
        printf("\nDigite sua senha:\n");
        scanf("%s", &senhaA);
        if (strcmp(usuarioA, usuario) == 0 && strcmp(senhaA, senha) == 0)
            printf("\n\nVoce foi logado no sistema de hotel\n\n");
        else
        {
            printf("Login Invalido");
        }
    }
    while (strcmp(usuarioA, usuario) == 1 || strcmp(senhaA, senha) == 1);
    system("pause");
    system("cls");
    int opc, i;
    // meses com 31 dias:1,3,5,7,8,10,12
    // meses com 30 dias: 4,,6,9,11
    // mes bissexto: 2
    // menu de filiais
    do
    {
        printf("\n|------------------Bem vindo a rede Hotel Algoritmo Suites-------------------|\n");
        printf("\n|1.Escolha 1 para a filial 1 - Master.............................|");
        printf("\n|2.Escolha 2 para a filial 2 - Confort............................|");
        printf("\n|3.Escolha 3 para encerrar o programa.............................|\n");
        scanf("%d", &filial);
        switch (filial)
        {
        case 1:
            printf("\nEscolheu filial 1 - Master\n");
            system("pause");
            system("cls");
            do
            {
                printf(" ______________________________________________________ ");
                printf("\n|-------Bem-vindo ao Algoritmo Suites Master-----------|");
                printf("\n ______________________________________________________ ");
                printf("\n|-------------------------Menu-------------------------|");
                printf("\n|______________________________________________________|\n");
                printf("\n1|Escolha 1 para fazer uma reserva.....................|");
                printf("\n2|Escolha 2 para Cadastro de clientes..................|");
                printf("\n3|Escolha 3 para vizualizar as reservas................|");
                printf("\n4|Escolha 4 para fazer Check-in e Check-out............|");
                printf("\n5|Escolha 5 para cancelar reserva......................|");
                printf("\n6|Escolha 6 para ver clientes..........................|");
                printf("\n7|Escolha 7 para ver relatorio de faturamento..........|");
                printf("\n\n10|Escolha 10 para sair do sistema...................|\n\n");
                scanf("%d", &opc);
                system("cls");
                switch (opc)
                {
                case 1:
                    printf("\nGlossario de reserva\n");
                    system("pause");
                    system("cls");
                    FazerReservas(reservas, &numReservas);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
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
    while (filial != 3);
    return 0;
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


// Função para converter data de calendário para número do dia do ano
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

// Função para converter número do dia do ano para data de calendário
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

int ValidarDatas(int dia, int mes, int ano) {

    if ((mes <= 7 && mes % 2 != 0 ) || mes > 7 && mes % 2 == 0) {
        if (dia >= 1 && dia <= 31) {
            return 1; // Data válida
        }
    } else if (!mes == 2 && (mes <= 7 && mes % 2 == 0) || mes > 7 && mes % 2 != 0) {
        if (dia >= 1 && dia <= 30) {
            return 1;
        }
    } else if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            if (dia >= 1 && dia <= 29) {
                return 1;
            }
        } else {
            if (dia >= 1 && dia <= 28) {
               return 1;
            }
        }
    }
else {
                    return 0;
}

}


int CompararDataAtual (int Dia, int Mes, int Ano){
int hora, horat;
time_t current_time;
struct tm* timeinfo;
time(&current_time);
timeinfo = localtime(&current_time);
struct tm desired_date;
desired_date.tm_year = Ano - 1900;
desired_date.tm_mon = Mes - 1;
desired_date.tm_mday = Dia;
hora=mktime(&desired_date);
horat=mktime(&current_time);
if(difftime(hora, horat)<0){
    return 1;
    }
    else{
        return 0;
    }
}
void FazerReservas(ReservaA reserva[], int *nReservas)
{
    int anoEntrada, mesEntrada, diaEntrada, anoSaida, mesSaida, diaSaida, diaDoAnoEntrada, diaDoAnoSaida, VerOut, VerSob, numeroQuarto, valin, valout,compin , compout, p=1;

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
                compin = CompararDataAtual ( diaEntrada ,  mesEntrada , anoEntrada);//compara data com a atual
                if (valin == 0) //valida datas (invalida)
                {
                    printf("\n\t|xxxxx|-Data de Check-in Inválida-|xxxxx|\n");
                    printf("\nPor Favor Insira Novamente:\n");
                }
                    if (compin == 1) //compara data com a atual(invalida)
                {
                    printf("\n\t|xxxxx|-Data de Check-in já passou-|xxxxx|\n");
                    printf("\nPor Favor Insira Novamente:\n");
                }
            }
            while (valin  != 1 || compin != 0); //valida datas valida e quebra looping (ir para proxima etapa)
            printf("%d", compin);
            do
            {
                printf("Digite a data de Check-out desta forma DD/MM/AAAA:");
                scanf("%d/%d/%d", &diaSaida, &mesSaida, &anoSaida);
                fflush(stdin);
                valout = ValidarDatas(diaSaida, mesSaida, anoSaida);
                compout =  CompararDataAtual ( diaSaida ,  mesSaida , anoSaida);
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
            while (valout != 1 && VerOut != 1 && compout !=0); //valida datas e quebra looping (ir para proxima etapa)
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

