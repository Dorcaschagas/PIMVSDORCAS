#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct standard
{
    int nquarto, aaaa, mm, dd;
};
struct confort
{
    int cnquarto, caaaa, cmm, cdd;
};
struct master
{
    int mnquarto, maaaa, mmm, mdd;
};
struct presid
{
    int pnquarto, paaaa, pmm, pdd;
};
struct Reserva
{
    int numeroQuarto;
    int anoEntrada, mesEntrada, diaEntrada;
    int anoSaida, mesSaida, diaSaida;
};

int main()
{
    setlocale(LC_ALL, "PORTUGUESE");
    struct Reserva reservas[366];
    int numReservas = 0;
    char usuario[20]="Murilo", usuarioA[20], senha[20]="123", senhaA[20];
    int f;
    printf("|-------|Bem-vindo ao sistema de reserva de hotel|-------|");
    do
    {
        printf("\n\nUsuario:\n");
        scanf("%s", &usuarioA);
        printf("\nDigite sua senha:\n");
        scanf("%s", &senhaA);
        if(strcmp(usuarioA, usuario)==0 && strcmp(senhaA, senha)==0)
            printf("\n\nVoce foi logado no sistema de hotel\n\n");
        else
        {
            printf("Login Invalido");
        }
    }
    while(strcmp(usuarioA, usuario)==1 || strcmp(senhaA, senha)==1);
    system("pause");
    system("cls");
    struct standard Standard;
    struct confort Confort;
    struct master Master;
    struct presid Presid;
    char horain, horaout;
    char tpresid, tmaster, tconfort, tstandard, vv;
    float prp, prm, prc, prs;
    int ca, tq, band=0, i, j;
    int quartoDisponivel = 1;
//meses com 31 dias:1,3,5,7,8,10,12
//meses com 30 dias: 4,,6,9,11
//mes bisexto: 2
    do
    {
        printf("\n|---------Bem vindo ao Hotel---------|\n");
        printf("\n|Escolha 1 para a filial 1...........|");
        printf("\n|Escolha 2 para a filial 2...........|");
        printf("\n|Escolha 3 para encerrar o programa..|\n");
        scanf("%d", &f);
        switch(f)
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
                switch(ca)
                {
                case 1:
                    printf("Escolha o tipo de suite:");
                    printf("\n1-----------Standart-----------1");
                    printf("\n2-----------Confort------------2");
                    printf("\n3------------Master------------3");
                    printf("\n4---------Presdiencial---------4\n");
                    scanf("%d", &tq);
                    system("cls");
                    switch(tq)
                    {
                    case 1:
                        system("cls");
                        printf("\n|--------------Suite Standard---------------|\n");
                        do
                        {
                            printf("\n|Registre o numero do quarto (1 a 3)|...|\n");
                            scanf("%d", &Standard.nquarto);
                        }
                        while(Standard.nquarto<=0||Standard.nquarto>3);
                        do
                        {
                            printf("\n|O ano da Reserva Standart (2023 a 2025)|\n");
                            scanf("%d", &Standard.aaaa);
                        }
                        while(Standard.aaaa!=2023 && Standard.aaaa!=2025 && Standard.aaaa!=2024);
                        do
                        {
                            printf("\n|O mês da Reserva Standart (1 a 12).....|\n");
                            scanf("%d", &Standard.mm);
                        }
                        while(Standard.mm<=0 || Standard.mm>12);
                        if(Standard.mm==1||Standard.mm==3||Standard.mm==5||Standard.mm==7||Standard.mm==8||Standard.mm==10||Standard.mm==12)
                            band=31;
                        else if(Standard.mm==4||Standard.mm==6||Standard.mm==9||Standard.mm==11)
                            band=30;
                        else if(Standard.aaaa!=2024&&Standard.mm==2)
                            band=28;
                        else if(Standard.aaaa==2024&&Standard.mm==2)
                            band=29;

                        do
                        {
                            printf("\n|O dia da Reserva Standart (1 a %d)......|\n", band);
                            scanf("%d", &Standard.dd);


                            for (i = 0; i < numReservas; i++)
                            {
                                if (reservas[i].numeroQuarto == Standard.nquarto)
                                {
                                    if (Standard.aaaa == reservas[i].anoEntrada && Standard.mm == reservas[i].mesEntrada && Standard.dd == reservas[i].diaEntrada)
                                    {
                                        quartoDisponivel = 0;
                                    }
                                }
                            }
                            if (quartoDisponivel)
                            {
                                reservas[numReservas].numeroQuarto = Standard.nquarto;
                                reservas[numReservas].anoEntrada = Standard.aaaa;
                                reservas[numReservas].mesEntrada = Standard.mm;
                                reservas[numReservas].diaEntrada = Standard.dd;
                                numReservas++;
                                printf("\nReserva confirmada com sucesso.\n");
                            }
                            else
                            {
                                printf("\nO quarto não está disponível para a data selecionada.\n");
                            }
                        }
                        while(Standard.dd<=0 || Standard.dd>band);
                        system("pause");
                        system("cls");
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
            while(ca!=13);
            break;
        case 2:
            printf("\nEscolheu filial 2\n");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("\nO programa foi encerrado");
            break;
        default:
            printf("\nopcao invalida\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(f!=3);
    return 0;
}
