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
    printf("|-------|Bem-vindo ao sistema de reservas da rede de Hotel Algoritmo Comfort Suites|-------|");
    //-----------------------------------
    //verificação de cadastro de usuario
    //-----------------------------------
    printf("\n\nUsuario:\n");
    scanf("%s", &usuarioA);
    //conferindo usuario
    while(strcmp(usuarioA, usuario))
    {
        printf("Usuario não cadastrado, digite novamente!\n");
        scanf("%s", &usuarioA);
    }

    printf("\nDigite sua senha:\n");
    scanf("%s", &senhaA);
    //conferindo senha
    while(strcmp(senhaA, senha))
    {
        printf("Senha inválida:\n");
        scanf("%s", &senhaA);
    }
    //mensagem de logado com sucesso
    if(strcmp(usuarioA, usuario)==0 && strcmp(senhaA, senha)==0)
    {
        printf("\n\nVoce foi logado no sistema de hotel\n\n");
    }
    //limpando a tela.
    system("pause");
    system("cls");
    //-----------------------------------
    //estrutura dos quartos
    //-----------------------------------
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
        printf("\n|---------Bem vindo a rede de Hotel Algoritmo Suites---------|\n");
        printf("\n|Escolha 1 para a filial 1 Master ...........|");
        printf("\n|Escolha 2 para a filial 2 Comfort...........|");
        printf("\n|Escolha 3 para encerrar o programa..........|\n");
        scanf("%d", &f);//recebe filial
        switch(f)
        {
        //---------------------------------------------------------------------------
        //                              Primera filial.
        //---------------------------------------------------------------------------
        case 1:
            printf("\nEscolheu filial 1 Master\n");
            system("pause");
            system("cls");

            do{
                printf("\n|-----Bem-vindo as reservas do hotel - filial 1 Master-----|\n");
                printf("\n1|Escolha 1 para fazer uma reserva...........|");
                printf("\n2|Escolha 2 para visualizar as reservas......|");
                printf("\n3|Escolha 3 para fazer Check-in e Check-out..|");
                printf("\n4|Escolha 4 para ver datas disponiveis.......|\n");
                scanf("%d", &ca);//fazer melhor definição de variavel(nome mais decritivo)
                system("cls");
                switch(ca)
                {
                case 1:
                    //--------------------------------------
                    //          fazer reserva
                    //--------------------------------------
                    printf("Escolha o tipo de quarto: ");
                    printf("\n\n1-----------Standard-----------1");
                    printf("\n2-----------Comfort------------2");
                    printf("\n3------------Master------------3");
                    printf("\n4---------Presidencial---------4\n");
                    scanf("%d", &tq);//tipo de quarto
                    system("cls");
                    switch(tq)
                    {
                    case 1:
                        //--------------------------------------
                        //                  Standard
                        //--------------------------------------
                        system("cls");
                        printf("\n|--------------Suite Standard---------------|\n");
                        do
                        {
                            printf("\n|Registre o numero do quarto (1 a 3)|...|\n");
                            scanf("%d", &Standard.nquarto);
                        }
                        //Standard.nquarto <= a 1  || Standard.nquarto >= 3(mudar)
                        while(Standard.nquarto<=0||Standard.nquarto>3);

                        //-------------------------------------------------------------------
                        //              verificação de data e diponibilidade.
                        //-------------------------------------------------------------------
                        do//ano
                        {
                            printf("\n|O ano da Reserva Standart (2023 a 2025)|\n");
                            scanf("%d", &Standard.aaaa);
                        }
                        while(Standard.aaaa < 2023 || Standard.aaaa > 2025);

                        do//mes
                        {
                            printf("\n|O mês da Reserva Standart (1 a 12).....|\n");
                            scanf("%d", &Standard.mm);
                        }
                        while(Standard.mm < 1 || Standard.mm >12);

                        //meses com 31, 30, 29 ou 30 dias.
                        if(Standard.mm <= 7 && Standard.mm % 2 != 0 || Standard.mm > 7 && Standard.mm % 2 == 0)
                        {
                            band=31; //trocar por nome (DIAS)
                        }
                        else
                        {
                            band=30;
                        }
                        //mes de fevereiro
                        if(Standard.mm == 2){
                            if(Standard.aaaa == 2024){
                                band=29;
                            }else{
                                band=28;
                            }
                        }

                        do{//dia
                            printf("\n|O dia da Reserva Standard (1 a %d)......|\n", band);
                            scanf("%d", &Standard.dd);

                            //--------------------------
                            //conferindo disponibilidade
                            //--------------------------
                            for (i = 0; i < numReservas; i++){
                                if (reservas[i].numeroQuarto == Standard.nquarto){
                                        if (Standard.aaaa == reservas[i].anoEntrada && Standard.mm == reservas[i].mesEntrada && Standard.dd == reservas[i].diaEntrada)
                                    {
                                        quartoDisponivel = 0;
                                    }
                                }
                            }
                            if (quartoDisponivel){
                                reservas[numReservas].numeroQuarto = Standard.nquarto;
                                reservas[numReservas].anoEntrada = Standard.aaaa;
                                reservas[numReservas].mesEntrada = Standard.mm;
                                reservas[numReservas].diaEntrada = Standard.dd;
                                numReservas++;
                                //so recebe se coloca a data correta
                                if(band == 28 && Standard.dd <= 28){
                                    printf("\nReserva confirmada com sucesso.\n");
                                }
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
                        //--------------------------------------
                        //                Comfort
                        //--------------------------------------
                        system("cls");
                        printf("\n|------------Suite Comfort------------|\n");
                        do
                        {
                            printf("\n|Registre o numero do quarto (1 a 3)|...|\n");
                            scanf("%d", &Confort.cnquarto);
                        }
                        while(Confort.cnquarto<=0||Confort.cnquarto>3);
                        do
                        {
                            printf("\n|O ano da Reserva Comfort (2023 a 2025)|\n");
                            scanf("%d", &Confort.caaaa);
                        }
                        while(Confort.caaaa!=2023 && Confort.caaaa!=2025 && Confort.caaaa!=2024);
                        do
                        {
                            printf("\n|O mês da Reserva Comfort (1 a 12).....|\n");
                            scanf("%d", &Confort.cmm);
                        }
                        while(Confort.cmm<=0 || Confort.cmm>12);
                        if(Confort.cmm==1||Confort.cmm==3||Confort.cmm==5||Confort.cmm==7||Confort.cmm==8||Confort.cmm==10||Confort.cmm==12)
                            band=31;
                        else if(Confort.cmm==4||Confort.cmm==6||Confort.cmm==9||Confort.cmm==11)
                            band=30;
                        else if(Confort.caaaa!=2024&&Confort.cmm==2)
                            band=28;
                        else if(Confort.caaaa==2024&&Confort.cmm==2)
                            band=29;

                        do
                        {
                            printf("\n|O dia da Reserva Comfort (1 a %d)......|\n", band);
                            scanf("%d", &Confort.cdd);


                            for (i = 0; i < numReservas; i++)
                            {
                                if (reservas[i].numeroQuarto == Confort.cnquarto)
                                {
                                    if (Confort.caaaa == reservas[i].anoEntrada && Confort.cmm == reservas[i].mesEntrada && Confort.cdd == reservas[i].diaEntrada)
                                    {
                                        quartoDisponivel = 0;
                                    }
                                }
                            }
                            if (quartoDisponivel)
                            {
                                reservas[numReservas].numeroQuarto = Confort.cnquarto;
                                reservas[numReservas].anoEntrada = Confort.caaaa;
                                reservas[numReservas].mesEntrada = Confort.cmm;
                                reservas[numReservas].diaEntrada = Confort.cdd;
                                numReservas++;
                                printf("\nReserva confirmada com sucesso.\n");
                            }
                            else
                            {
                                printf("\nO quarto não está disponível para a data selecionada.\n");
                            }
                        }
                        while(Confort.cdd<=0 || Confort.cdd>band);
                        system("pause");
                        system("cls");
                        break;

                        break;
                    case 3:
                        //--------------------------------------
                        //                  Master
                        //--------------------------------------
                        system("cls");
                        printf("\n|------------Suite Master------------|\n");
                        do
                        {
                            printf("\n|Registre o numero do quarto (1 a 3)|...|\n");
                            scanf("%d", &Master.mnquarto);
                        }
                        while(Master.mnquarto<=0||Master.mnquarto>3);
                        do
                        {
                            printf("\n|O ano da Reserva Master (2023 a 2025)|\n");
                            scanf("%d", &Master.maaaa);
                        }
                        while(Master.maaaa!=2023 && Master.maaaa!=2025 && Master.maaaa!=2024);
                        do
                        {
                            printf("\n|O mês da Reserva Master (1 a 12).....|\n");
                            scanf("%d", &Master.mmm);
                        }
                        while(Master.mmm<=0 || Master.mmm>12);
                        if(Master.mmm==1||Master.mmm==3||Master.mmm==5||Master.mmm==7||Master.mmm==8||Master.mmm==10||Master.mmm==12)
                            band=31;
                        else if(Master.mmm==4||Master.mmm==6||Master.mmm==9||Master.mmm==11)
                            band=30;
                        else if(Master.maaaa!=2024&&Master.mmm==2)
                            band=28;
                        else if(Master.maaaa==2024&&Master.mmm==2)
                            band=29;

                        do
                        {
                            printf("\n|O dia da Reserva Master (1 a %d)......|\n", band);
                            scanf("%d", &Master.mdd);


                            for (i = 0; i < numReservas; i++)
                            {
                                if (reservas[i].numeroQuarto == Master.mnquarto)
                                {
                                    if (Master.maaaa == reservas[i].anoEntrada && Master.mmm == reservas[i].mesEntrada && Master.mdd == reservas[i].diaEntrada)
                                    {
                                        quartoDisponivel = 0;
                                    }
                                }
                            }
                            if (quartoDisponivel)
                            {
                                reservas[numReservas].numeroQuarto = Master.mnquarto;
                                reservas[numReservas].anoEntrada = Master.maaaa;
                                reservas[numReservas].mesEntrada = Master.mmm;
                                reservas[numReservas].diaEntrada = Master.mdd;
                                numReservas++;
                                printf("\nReserva confirmada com sucesso.\n");
                            }
                            else
                            {
                                printf("\nO quarto não está disponível para a data selecionada.\n");
                            }
                        }
                        while(Master.mdd<=0 || Master.mdd>band);
                        system("pause");
                        system("cls");
                        break;

                    case 4:
                        //--------------------------------------
                        //              Presidencial
                        //--------------------------------------
                        system("cls");
                        printf("\n|------------Suite Presidencial------------|\n");
                        do
                        {
                            printf("\n|Registre o numero do quarto (1 a 3)|...|\n");
                            scanf("%d", &Presid.pnquarto);
                        }
                        while(Presid.pnquarto<=0||Presid.pnquarto>3);
                        do
                        {
                            printf("\n|O ano da Reserva Presidencial (2023 a 2025)|\n");
                            scanf("%d", &Presid.paaaa);
                        }
                        while(Presid.paaaa!=2023 && Presid.paaaa!=2025 && Presid.paaaa!=2024);
                        do
                        {
                            printf("\n|O mês da Reserva Presidencial (1 a 12).....|\n");
                            scanf("%d", &Presid.pmm);
                        }
                        while(Presid.pmm<=0 || Presid.pmm>12);
                        if(Presid.pmm==1||Presid.pmm==3||Presid.pmm==5||Presid.pmm==7||Presid.pmm==8||Presid.pmm==10||Presid.pmm==12)
                            band=31;
                        else if(Presid.pmm==4||Presid.pmm==6||Presid.pmm==9||Presid.pmm==11)
                            band=30;
                        else if(Presid.paaaa!=2024&&Presid.pmm==2)
                            band=28;
                        else if(Presid.paaaa==2024&&Presid.pmm==2)
                            band=29;

                        do
                        {
                            printf("\n|O dia da Reserva Presidencial (1 a %d)......|\n", band);
                            scanf("%d", &Presid.pdd);


                            for (i = 0; i < numReservas; i++)
                            {
                                if (reservas[i].numeroQuarto == Presid.pnquarto)
                                {
                                    if (Presid.paaaa == reservas[i].anoEntrada && Presid.pmm == reservas[i].mesEntrada && Presid.pdd == reservas[i].diaEntrada)
                                    {
                                        quartoDisponivel = 0;
                                    }
                                }
                            }
                            if (quartoDisponivel)
                            {
                                reservas[numReservas].numeroQuarto = Presid.pnquarto;
                                reservas[numReservas].anoEntrada = Presid.paaaa;
                                reservas[numReservas].mesEntrada = Presid.pmm;
                                reservas[numReservas].diaEntrada = Presid.pdd;
                                numReservas++;
                                printf("\nReserva confirmada com sucesso.\n");
                            }
                            else
                            {
                                printf("\nO quarto não está disponível para a data selecionada.\n");
                            }
                        }
                        while(Presid.pdd<=0 || Presid.pdd>band);
                        system("pause");
                        system("cls");
                        break;
                    default:
                        break;
                    }
                    break;
                case 2:
                    //--------------------------------------
                    //         Visualizar as reservas
                    //--------------------------------------
                    break;
                case 3:
                    //--------------------------------------
                    //      fazer check-in / check-out
                    //--------------------------------------
                    break;
                case 4:
                    //--------------------------------------
                    //        ver datas disponiveis
                    //--------------------------------------
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
        //---------------------------------------------------------------------------
        //Segunda filial.
        //---------------------------------------------------------------------------
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
