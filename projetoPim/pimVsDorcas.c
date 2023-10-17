#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

int qtdPessoas = 0, tq, valorQuarto = 0, entDia, aaaa = 0, mm = 0, dd = 0, totDiasMes, totalDias ;

struct cadastroCliente{
    char nome[50], cpf[12];
    int idade;
};


struct dataEntrada{
    int entradaAno, entradaMes, entradaDia;
};
struct QuartosF1{
    int quartos[13][366];
};


int main(){
    setlocale(LC_ALL, "Portuguese");

    struct cadastroCliente cadastroCl[1000];
    struct QuartosF1 quartos;
    struct dataEntrada entrada;
    int filial, opc;

    //=====================================================
    //=======================login=========================
    login();
    system("cls");

    do{
        system("cls");
        printf("\n|------------------Bem vindo a rede Hotel Algoritmo Suites-------------------|\n");
        printf("\n|1.Escolha 1 para a filial 1 - Master.............................|");
        printf("\n|2.Escolha 2 para a filial 2 - Confort............................|");
        printf("\n|3.Escolha 3 para encerrar o programa.............................|\n");
        scanf("%d", &filial);
        //system("pause");
        system("cls");

        switch (filial){
            case 1:
            do{
            system("cls");
            mensagemMenu();
            scanf("%d", &opc);
            system("cls");

            switch (opc){
                case 1:
                    system("cls");
                    //=====================================================
                    //======================Data===========================
                    system("cls");
                    printf("Quantos dias voce gostaria de reservar?:");
                    scanf("%d", &totalDias);
                    system("cls");

                    //codigo do Murilo.
                    aaaa = ano();
                    mm = mes();
                    dd = dia(aaaa, mm);
                    datasEntradas(&entrada,aaaa,mm,dd);
                    system("cls");
                    menu();
                    break;
                case 2:
                    //=====================================================
                    //=====================clientes========================
                    printf("Quantas pessoas:");
                    scanf("%d", &qtdPessoas);
                    fflush(stdin);
                    for(int i = 0; i < qtdPessoas; i++){
                        cliente(&cadastroCl[i]);
                    }
                    break;
                case 3:
                    //=====================================================
                    //====================relatorio========================
                    system("cls");
                    relatorio(cadastroCl);
                    mostraDataEnt(entrada);
                    mostrarDataSai(entrada,totalDias);
                    break;
                case 4:
                    mostraDataEnt(entrada);
                    mostrarDataSai(entrada,totalDias);
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
                }while (opc != 13);
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
    }while(filial != 3);

    //=====================================================
    //=====================Quartos=========================

    return 0;
}
void login(){

    char nome1[50];
    char senha[10];
    //nome--------------------------------------
    do{
        printf("\nUsuario: ");
        scanf("%s", &nome1);
    }while(strcmp(nome1,"Dorcas"));
    //senha-------------------------------------
    do{
        printf("Senha: ");
        scanf("%s", &senha);
    }while(strcmp(senha,"0000"));

}

//============================================================================================
//========================================Clientes===========================================
int cliente(struct cadastroCliente *cadastroCl){
    printf("Nome:");
    scanf("%s", cadastroCl->nome);
    printf("Idade:");
    scanf("%d", &cadastroCl->idade);
    printf("CPF:");
    scanf("%s", cadastroCl->cpf);
    printf("\n===================================\n");
    return 0;
}
//============================================================================================
//=======================================relatorio============================================
int relatorio(struct cadastroCliente cadastroCl[]){

    for(int i = 0; i < qtdPessoas; i++){
        printf("Nome: %s\n", cadastroCl[i].nome);
        printf("Idade: %d\n", cadastroCl[i].idade);
        printf("CPF: %s\n", cadastroCl[i].cpf);
        printf("===================================\n");
    }
    return 0;
}
//============================================================================================
//======================================reserva Datas=========================================
int datasEntradas(struct dataEntrada *entrada, int ano, int mes, int dia){
    entrada->entradaAno = ano;
    entrada->entradaMes = mes;
    entrada->entradaDia = dia;
    return 0;
}

int mostraDataEnt(struct dataEntrada entrada){
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
}
//============================================================================================
//=========================================Datas==============================================
int ano() {
    int aaaa;
    do {
        printf("\nAno (2023 a 2025)|\n");
        scanf("%d", &aaaa);
        fflush(stdin);
    } while (aaaa < 2023 || aaaa > 2025);
    return aaaa;
}

int mes(){
    int mm;
    do{//mes
        printf("\nMês(1 a 12).....|\n");
        scanf("%d", &mm);
        fflush(stdin);
    }while(mm < 1 || mm >12);
    return mm;
}

int dia( aaaa, mm){
    int dias;

    if(mm!=2){
        if((mm<=7 && mm%2==0) || (mm<=7 && mm%2!=0)){//meses pares de janeiro a julho
            dias = 30;
            do{
                printf("\nDia (1 a %d)......|\n", dias);
                scanf("%d", &dd);
            } while(dd < 1 || dd > 30);
        }
        if((mm >=8 && mm%2==0) || (mm>=8 && mm%2!=0)){
            dias = 31;
            do{
                printf("\nDia (1 a %d)......|\n", dias);
                scanf("%d", &dd);
            } while(dd < 1 || dd > 31);
        }
    } else {
        if(aaaa % 4 == 0 && (aaaa % 100 != 0 || aaaa % 400 == 0)){
            if(mm == 2){
                dias = 29;
                do{
                    printf("\nDia (1 a %d)......|\n", dias);
                    scanf("%d", &dd);
                } while(dd < 1 || dd > 29);
            }
        } else if(mm == 2 && !aaaa % 4 == 0 && (aaaa % 100 != 0 || aaaa % 400 == 0)){
            dias = 28;
            do{
                printf("\nDia (1 a %d)......|\n", dias);
                scanf("%d", &dd);
            } while(dd < 1 || dd > 28);
        }
    }
    entDia = dd;
    totDiasMes = dias;
    return dd;
}
//============================================================================================
//==================================mensagem menu=============================================
void mensagemMenu(){
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
void tipoQuarto(){
    int numQrt, qrtdLivre=12 , valorQuarto;

    if(tq == 1){
        valorQuarto = 50;
    }
    if(tq == 2){
        valorQuarto = 75;
    }
    if(tq == 3){
        valorQuarto = 100;
    }
    if(tq == 4){
        valorQuarto =  150;
    }

    printf("Tipo escolhido foi %d\n", tq);

    printf("Quantos dias voce gostaria de reservar?:");
    scanf("%d", &totalDias);
    system("cls");

    printf("\nQuarto de 1 a 3 :");
    scanf("%d",&numQrt);

    int valorReserva = totalDias * valorQuarto;
    printf("valor para %d dias no quarto %d será de: %d\n", totalDias, numQrt, valorReserva);
    system("pause");
    system("cls");

    return valorReserva;
}


int menu(){
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
}


