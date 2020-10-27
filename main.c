#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct data DATA;
struct data
{
    int dia;
    int mes;
    int ano;
};

typedef struct local LOCAL;
struct local
{
    char rua[15];
    char n[4];
    char bairro[15];
    char cidade[15];
    char estado[2];
    char cep[9];
};

typedef struct paciente PACIENTE;
struct paciente
{
    char nome[30];
    int cpf;
    int telefone;
    LOCAL endereco;
    DATA nasc;
    char email[30];
    DATA diagnostico;
    char comorbidades[50];
};

int main()
{
    setlocale(LC_ALL, "portuguese");

    //Declarações
    int opcao;

    //Instruções
    do
    {
        system("cls");
        printf("\n  #-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |                                MENU PRINCIPAL                            |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |          1 - CADASTRAR                                                   |");
        printf("\n  |          2 - LISTAR                                                      |");
        printf("\n  |          3 - REMOVER                                                     |");
        printf("\n  |          0 - SAIR                                                        |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |     Programador:                                                         |");
        printf("\n  |          Luan Campos                                                     |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  #--------------------------------------------------------------------------#");
        printf("\n\n  > Escolha uma opção: ");
        scanf("%i", &opcao);

        switch(opcao)
        {
            case 1:
                //Instruções
            break;
            case 2:
                //Instruções
            break;
            case 3:
                //Instruções
            break;
            case 0:
                //Finaliza
            break;
            default:
                printf("\n\n [!] Opção inválida! Pressione ENTER para continuar...");
                getch();
            break;
        }
    }
    while (opcao != 0);



    return 0;
}
