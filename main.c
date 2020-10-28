#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

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
    char rua[20];
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

void SetCursorPosition(int XPos, int YPos)
{
   COORD coord;
   coord.X = XPos; coord.Y = YPos;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int opcao = 0;
    int podeEntrar = 0;

    // Página de Login
    do
    {
        char loginCorreto[15] = "CadastroCovid";
        char senhaCorreta[15] = "Doutor12345";
        char login[15];
        char senha[15];

        system("cls");
        printf("\n  #-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |                               BEM-VINDO!                                 |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |                  FAVOR INSERIR SEUS DADOS DE ACESSO:                     |");
        printf("\n  |                                                                          |");
        printf("\n  |                  LOGIN:                                                  |");
        printf("\n  |                  SENHA:                                                  |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  #--------------------------------------------------------------------------#");

        SetCursorPosition(28, 9);
        scanf("%s", &login);

        SetCursorPosition(28, 10);
        scanf("%s", &senha);

        SetCursorPosition(0, 20);

        if (strcmp(login, loginCorreto) == 0 && strcmp(senha, senhaCorreta) == 0)
        {
            podeEntrar = 1;
        }

        else
        {
            printf("  [!] Dados incorretos! Pressione ENTER para continuar...");
            podeEntrar = 0;
            getch();
        }

    }
    while (podeEntrar != 1);

    // Menu Principal
    do
    {
        system("cls");
        printf("\n  #-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |                             MENU PRINCIPAL                               |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |            1 - CONSULTAR LISTA DE PACIENTES                              |");
        printf("\n  |            2 - CONSULTAR LISTA DE PACIENTES COM COMORBIDADES             |");
        printf("\n  |            3 - CADASTRAR UM NOVO PACIENTE                                |");
        printf("\n  |                                                                          |");
        printf("\n  |            0 - SAIR                                                      |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
        printf("\n  |                                                                          |");
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
            break;

            default:
                printf("\n\n  [!] Opção inválida! Pressione ENTER para continuar...");
                getch();
            break;
        }

    }
    while (opcao != 0);


    return 0;
}
