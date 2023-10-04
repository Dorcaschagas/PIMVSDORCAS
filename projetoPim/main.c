#include <stdio.h>
#include <stdlib.h>

struct clientes {
    char nome[50];
    char sobrenome[50];
};

struct funcionarios {
    char nome [50];
    char senha[6];
};

struct quartosF1{
    int inferior, medio, top;
};

struct quartosF2{
    int inferior, medio, top, muitoTop;
};

struct dataReservada{
    int ano, mes, dia;
};
int dataResevada(ano,mes,dia){

    struct dataReservada dtr1;
    dtr1.ano = ano;
    dtr1.mes = mes;
    dtr1.dia = dia;

    printf("------------------------------------------------------------------\n");
    printf("Data escolhida  %d/%d/%d.\n" , dtr1.ano, dtr1.mes, dtr1.dia);
    printf("------------------------------------------------------------------\n\n");
}

int main(){
    struct funcionarios f1;
    struct clientes cliente1;
    struct quartosF1 qts1, qts2, qts3; //primeira filial
    struct quartosF2 qts4, qts5, qts6, qts7; //Segunda filial
    int opcao,mes,ano,dia,i,quarto,res;
    char resposta = " ";


    //------------------------------------------------------------------------------
    //--------------------------informacoes do funcionario
    //------------------------------------------------------------------------------
    //funcionario cadastrado
    strcpy(f1.nome, "Dorcas");
    printf("Usuario:");
    gets(f1.nome);
    while(strcmp(f1.nome, "Dorcas")){
        printf("%s nao esta cadastrado como usuario, digite novamente:\n", f1.nome);
        gets(f1.nome);
    }
    printf("Senha:");
    gets(f1.senha);
    while(strcmp(f1.senha, "123456")){
        printf("Senha invalida, digite novamente:\n", f1.nome);
        gets(f1.senha);
    }
    system("pause"); //pede para apertar qualquer botão para continuar
    system("cls"); //limpa tela
    //------------------------------------------------------------------------------
    //--------------------------informacoes do cliente
    //------------------------------------------------------------------------------
    printf("--------------------------Hotel[Nome]-----------------------------\n");
    printf("Digite o nome do cliente: \n");
    gets(cliente1.nome);
    printf("Digite o Sobrenome do cliente: ");
    gets(cliente1.sobrenome);
    system("pause"); //pede para apertar qualquer botão para continuar
    system("cls"); //limpa tela
    printf("------------------------------------------------------------------\n");
    printf("Ola,%s Seja bem vindo(a) ao Hotel[Nome] \n\n", cliente1.nome);
    printf("------------------------------------------------------------------\n");

    //------------------------------------------------------------------------------
    //----------------------------Data para reserva
    //------------------------------------------------------------------------------
    while (resposta != "n" || resposta != "N"){

    printf("\t\tQual sera a data da reserva?\n");
    printf("------------------------------------------------------------------\n");
    printf("\nAno (entre 2023 e 2024):");
    scanf("%d", &ano);
    //apenas anos 2023 e 2024
    while (ano < 2023 || ano > 2024){
        printf("Ano invalido, digite um ano entre 2023 e 2024:\n");
        scanf("%d", &ano);
    }
    printf("%d/Mes:",ano);
    scanf("%d", &mes);
    fflush(stdin);
    //meses de 1 a 12
    while (mes < 0 || mes > 12 ){
        printf("Mes invalido, digite um numero entre 1 e 12 onde cada um respresenta um mes do ano!\n");
        scanf("%d", &mes);
    }
    //meses com 31 de janeiro a julho
    if(mes <= 7){
        if(mes % 2 == 1){
            printf("%d/%d/Dia:", ano, mes);
            scanf("%d", &dia);
            while (dia > 31 || dia < 1){
                printf("Data invalida, datas ate dia [31]\n");
                printf("%d/%d/Dia:", ano, mes);
                scanf("%d", &dia);
            }
        } else if( mes == 2 ){ //fevereiros com 29 dias.
            if((ano % 4 == 4 && ano % 100 != 0) || ano % 400 == 0){
                printf("%d/%d/Dia:", ano, mes);
                scanf("%d", &dia);
                while (dia > 29|| dia < 1){
                    printf("Data invalida, mes com 29 dias\n");
                    printf("%d/%d/Dia:", ano, mes);
                    scanf("%d", &dia);
                }
            } else {//fevereiro com 28 dias
                printf("%d/%d/Dia:", ano, mes);
                scanf("%d", &dia);
                while (dia > 28 || dia < 1){
                    printf("Data invalida, mes com 28 dias\n");
                    printf("%d/%d/Dia:", ano, mes);
                    scanf("%d", &dia);
                }
            }
        }
    //meses com 31 de agosto a dezembro
    }
    if(mes >= 7){
        if(mes % 2 == 0){
            printf("%d/%d/Dia:", ano, mes);
            scanf("%d", &dia);
            while (dia > 31 || dia < 1){
                printf("Data invalida, datas ate dia [31]\n");
                printf("%d/%d/Dia:", ano, mes);
                scanf("%d", &dia);
            }
        }else {
            printf("%d/%d/Dia:", ano, mes);
            scanf("%d", &dia);
            while (dia > 30 || dia < 1){
                printf("Data invalida, datas ate dia [30]\n");
                printf("%d/%d/Dia:", ano, mes);
                scanf("%d", &dia);
            }
        }
    }
    dataResevada(ano, mes, dia);
    //------------------------------------------------------------------------------
    //-------------------------------exibe menu
    //------------------------------------------------------------------------------
    printf("Para fazer sua reserva escolha uma opcao digitando um numero entre [1 e 3] onde:\n\n");
    printf("\t[1] Filial:  1\n");
    printf("\t[2] Filial:  2\n");
    printf("\t[3] Sair:    3\n\n");
    printf("Digite um numero para escolher uma opcao: ");
    scanf("%d", &opcao);
    while(opcao < 1 || opcao > 3){
        printf("------------------------------------------------------------------\n\n");
        printf("\nPara fazer sua reserva escolha uma opcao digitando um numero entre [1 e 3] onde:\n\n");
        printf("[1] Filial 1\n");
        printf("[2] Filial 2\n");
        printf("[3] Sair 3\n\n");
        printf("Digite um numero para escolher uma opcao: ");
        scanf("%d", &opcao);
    }
    printf("------------------------------------------------------------------\n");
    fflush(stdin);
    switch(opcao){
        //-------------------------------------------------------------------------------------
        //-------------------------------filial Um
        //-------------------------------------------------------------------------------------
        case 1:
            //opcoes de quartos
            printf("Bem vindo(a) a Filial 1\n");
            printf("------------------------------------------------------------------\n\n");
            printf("Escolha um quarto\n");
            printf("[1] Quartos de 1 a 3\n");
            printf("[2] Quartos de 4 a 6\n");
            printf("[3] Quartos de 7 a 9\n");
            printf("[4] Para conhecer nossas opcoes");
            printf("[5] Sair\n");
            printf("[0] Voltar ao menu inicial!\n");
            printf("Escolha uma opcao de 0 a 5 para darmos segmentos:\n");
            scanf("%d",&quarto);

            while(quarto < 0 || quarto > 4){
                printf("Opcao invalida, escolha umas das opcoes a seguir:\n");
                printf("[1] Quartos de 1 a 3\n");
                printf("[2] Quartos de 4 a 6\n");
                printf("[3] Quartos de 7 a 9\n");
                printf("[4] Para conhecer nossas opcoes");
                printf("[5] Sair\n");
                printf("[0] Voltar ao menu inicial!\n");
                printf("Escolha uma opcao de 0 a 5 para darmos segmentos:\n");
                scanf("%d",&quarto);
            }
            printf("------------------------------------------------------------------\n\n");
            switch(quarto){
                case 1:
                    printf("Qual quarto voce gostaria de reservar? 1,2 ou 3\n");
                    printf("Escolha uma opcao para saber se esta disponivel.\n");
                    printf("[1] Quarto 1\n");
                    printf("[2] Quarto 2\n");
                    printf("[3] Quarto 3\n");
                    scanf("%d", res);
                    fflush(stdin);

                    while(res < 0 || res > 3){
                        printf("Valor invalido, [1,2 ou 3]");
                        scanf("%d", res);
                    }
                    if(res == 1){
                        qts1.inferior = 1;
                    }else if(res == 2){
                         qts1.inferior = 2;
                    } else if(res == 3){
                        qts1.inferior = 3;
                    }
                    printf("Quer fazer uma nova reserva?\n");
                    gets(resposta);

                    //conferindo data
                   /*if(ano == dtr1.ano && mes == dtr1.mes && dia == dtr1.dia){
                        if(qts1.inferior == 1 || qts1.inferior == 2 || qts1.inferior == 3){
                            printf("Data reservada para este quarto!");
                        }
                    }*/


                    break;
                case 2:
                    printf("Qual quarto voce gostaria de reservar? 4,5 ou 6\n");
                    printf("Escolha uma opcao para saber se esta disponivel.\n");
                    printf("[4] Quarto 4\n");
                    printf("[5] Quarto 5\n");
                    printf("[6] Quarto 6\n");
                    if(quarto == 4){
                        //verificar disponibilidade
                    }else if(quarto == 5){
                        //verificar disponibilidade
                    } else if(quarto == 6){
                        //verificar disponibilidade
                    }
                    break;
                case 3:
                    printf("Qual quarto voce gostaria de reservar? 7,8 ou 9\n");
                    printf("Escolha uma opcao para saber se esta disponivel.\n");
                    printf("[7] Quarto 7\n");
                    printf("[8] Quarto 8\n");
                    printf("[9] Quarto 9\n");
                    if(quarto == 7){
                        //verificar disponibilidade
                    }else if(quarto == 8){
                        //verificar disponibilidade
                    } else if(quarto == 9){
                        //verificar disponibilidade
                    }
                    break;
                case 4:
                    //descrever os quarots e estadias!
                    printf("Os Quartos de 1 a 3 sao mais inferiores!\n");
                    printf("Os Quartos de 4 a 6 sao medianos!\n");
                    printf("Os Quartos de 7 a 9 sao mais Sofisticados!\n");
                    break;
                case 5:
                    printf("            Hotel [Nome] agradece, volte sempre! .\n");
                    printf("------------------------------------------------------------------\n\n");
                    break;
                default:
                    printf("Opcao invalida.\n");
                    printf("------------------------------------------------------------------\n\n");
            }

            break;

        case 2:
            //-------------------------------------------------------------------------------------
            //-------------------------------filial Dois
            //-------------------------------------------------------------------------------------


            break;
        case 3:
            printf("            Hotel [Nome] agradece, volte sempre! .\n");
            printf("------------------------------------------------------------------\n\n");
            break;
        default:
            printf("Opcao invalida.\n");
            printf("------------------------------------------------------------------\n\n");

        }
    }
    return 0;
}




