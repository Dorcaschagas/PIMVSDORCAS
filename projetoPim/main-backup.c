#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>


typedef struct
{
    int nquarto, aaaa, mm, dd, preco;
} reserva;

typedef struct
{
    int numeroQuarto, diaDoAnoEntrada,diaDoAnoSaida,gapReservado;
} ReservaA;

int VerificarSobreposicao(ReservaA reserva[], int nReservas, int numeroQuarto, int diaDoAnoEntrada, int diaDoAnoSaida) {
    for (int i = 0; i < nReservas; i++) {
        if (reserva[i].numeroQuarto == numeroQuarto) {
            // Verificar se a nova reserva começa antes da reserva existente terminar
            if (diaDoAnoSaida >= reserva[i].diaDoAnoEntrada) {
                // Verificar se a nova reserva termina depois da reserva existente começar
                if (diaDoAnoEntrada <= reserva[i].diaDoAnoSaida) {
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

int ValidarDatas(ReservaA reserva[], int *nReservas)
{
    int anoEntrada, mesEntrada, diaEntrada,anoSaida, mesSaida, diaSaida;
    setlocale(LC_ALL, "PORTUGUESE");
    int bandin = 0,bandout = 0, band=0;

    //se mes > 0 e <= 7 // mes % 2 != 0 impar == dias = 31
//validando check-in
    if (mesEntrada == 1 || mesEntrada == 3 || mesEntrada == 5 || mesEntrada == 7 || mesEntrada == 8 || mesEntrada == 10 || mesEntrada == 12)
    {
        if (diaEntrada <= 31|| diaEntrada>0 )
        {
            bandin = 1;// Data válida
        }
    }
    else if (mesEntrada == 4 || mesEntrada == 6 || mesEntrada == 9 || mesEntrada == 11)
    {
        if (diaEntrada <= 30||diaEntrada >0)
        {
            bandin = 1;
        }
    }
    else if (anoEntrada % 4 == 0 && (anoEntrada % 100 != 0 || anoEntrada % 400 == 0))
    {
        // Calculo prara ano bissexto
        if (diaEntrada <= 29||diaEntrada >0)
        {
            bandin = 1;
        }
    }
    else
    {
        bandin=0;
    }
//validando o chek-out
    if (mesSaida == 1 || mesSaida == 3 || mesSaida == 5 || mesSaida == 7 || mesSaida == 8 || mesSaida == 10 || mesSaida == 12)
    {
        if (diaSaida <= 31||diaSaida>0 )
        {
            bandout = 1;
        }
    }
    else if (mesSaida == 4 || mesSaida == 6 || mesSaida == 9 || mesSaida == 11)
    {
        if (diaSaida <= 30||diaSaida >0)
        {
            bandout = 1;
        }
    }
    else if (anoSaida % 4 == 0 && (anoSaida % 100 != 0 || anoSaida % 400 == 0))
    {

        if (diaSaida <= 29||diaSaida >0)
        {
            bandout = 1;
        }

    }
    else
    {
        bandout=0;
    }
    if(bandin==1||bandout==1)
        band=1;
    return bandin;
    return bandout;
    return band;
}

// ... Definição das funções dataParaDiaDoAno e diaDoAnoParaData aqui ...

void FazerReservas(ReservaA reserva[], int *nReservas) {
    int anoEntrada, mesEntrada, diaEntrada, anoSaida, mesSaida, diaSaida, diaDoAnoEntrada, diaDoAnoSaida, gapDia, mm, VerSob, numeroQuarto;
    int resultadoValidacao, p = 1;

    do {
        printf("\n---------------Fazer uma Reserva---------------\n");
        printf("\nDigite o numero do quarto:\n");
        scanf("%d", &numeroQuarto);
        system("cls");

        // Receba o número do quarto e outras informações relevantes

        // Valide as datas de entrada e saída
        do {
            printf("\nDigite a data de Check-in desta forma DD/MM/AAAA:");
            scanf("%d/%d/%d", &diaEntrada, &mesEntrada, &anoEntrada);
            fflush(stdin);
            resultadoValidacao = ValidarDatas(reserva, nReservas);
            if (resultadoValidacao == 0) {
                printf("\n\t|xxxxx|-Data de Check-in Inválida-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }
        } while (resultadoValidacao != 1);

        do {
            printf("Digite a data de Check-out desta forma DD/MM/AAAA:");
            scanf("%d/%d/%d", &diaSaida, &mesSaida, &anoSaida);
            fflush(stdin);
            resultadoValidacao = ValidarDatas(reserva, nReservas);
            if (resultadoValidacao == 0) {
                printf("\n\t|xxxxx|-Data de Check-out Inválida-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }

            diaDoAnoEntrada = dataParaDiaDoAno(diaEntrada, mesEntrada, anoEntrada);
            diaDoAnoSaida = dataParaDiaDoAno(diaSaida, mesSaida, anoSaida);

            if (diaDoAnoEntrada < diaDoAnoSaida) {
                mm = 1;
            } else if (mm != 1) {
                printf("\n\t|xxxxx|-Data de Check-out Inválida (data de check-out menor ou igual à de check-in)-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }

            VerSob = VerificarSobreposicao(reserva, *nReservas, numeroQuarto, diaDoAnoEntrada, diaDoAnoSaida);

            if (VerSob == 1) {
                printf("\n\t|xxxxx|-Conflito de datas com outra reserva-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }
        } while (resultadoValidacao != 1 || mm != 1 || VerSob == 1);

        // Registre o número do dia do ano nas reservas
        reserva[*nReservas].diaDoAnoEntrada = diaDoAnoEntrada;
        reserva[*nReservas].diaDoAnoSaida = diaDoAnoSaida;
        reserva[*nReservas].numeroQuarto = numeroQuarto;
        gapDia = diaDoAnoSaida - diaDoAnoEntrada;

        // Use os valores de diaDoAnoEntrada e diaDoAnoSaida conforme necessário
        p = 2;
        printf("\nReserva registrada com sucesso!\n");
        printf("%d", VerSob);
        system("pause");
        system("cls");
        (*nReservas)++;
    } while (p != 2);
}





int main()
{
    setlocale(LC_ALL, "PORTUGUESE");
    ReservaA reservas[366];
    int numReservas = 0;
    char usuario[20] = "Murilo", usuarioA[20], senha[20] = "123", senhaA[20];
    int f;
    reserva Reserva;
    ReservaA reservaa;
    printf("|-------|Bem-vindo ao sistema de reserva de hotel|-------|");
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
    char horain, horaout;
    char tpresid, tmaster, tconfort, tstandard, vv;
    float prp, prm, prc, prs;
    int ca, tq;
    int quartoDisponivel = 1;
    int indiceReserva = 0;
    // meses com 31 dias:1,3,5,7,8,10,12
    // meses com 30 dias: 4,,6,9,11
    // mes bissexto: 2
    // menu de filiais
    do
    {
        printf("\n|---------Bem vindo ao Hotel---------|\n");
        printf("\n|Escolha 1 para a filial 1...........|");
        printf("\n|Escolha 2 para a filial 2...........|");
        printf("\n|Escolha 3 para encerrar o programa..|\n");
        scanf("%d", &f);
        switch (f)
        {
        case 1:
            printf("\nEscolheu filial 1\n");
            system("pause");
            system("cls");
            do
            {
                printf("\n|-----Bem-vindo ao reservas de hotel -filial 1-----|\n");
                printf("\n1|Escolha 1 para fazer uma reserva...........|");
                printf("\n2|Escolha 2 para vizualizar as reservas......|");
                printf("\n3|Escolha 3 para fazer Check-in e Check-out..|");
                printf("\n4|Escolha 4 para ver datas disponiveis.......|\n");
                scanf("%d", &ca);
                system("cls");
                switch (ca)
                {
                case 1:
                    printf("Escolha o tipo de suite:");
                    printf("\n1-----------Standart-----------1");
                    printf("\n2-----------Confort------------2");
                    printf("\n3------------Master------------3");
                    printf("\n4---------Presdiencial---------4\n");
                    scanf("%d", &tq);
                    system("cls");
                    switch (tq)
                    {
                    case 1:
                        FazerReservas(reservas, &numReservas);


                        break;
                    case 2:
                        printf("\nVoce escolheu a Confort\n");
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        printf("\nVoce escolheu a Master\n");
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        printf("\nVoce escolheu a Presidencial\n");
                        system("pause");
                        system("cls");
                        break;
                    default:
                        break;
                    }
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    printf("opcao invalida");
                    break;
                case 7:
                    return 0;
                    break;
                }
            }
            while (ca != 13);
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
    while (f != 3);
    return 0;
}
