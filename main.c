#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
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
    char cpf[12];
    char telefone[15];
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
        int p=0;
        do
        {
            senha[p]=getch();
            if(senha[p]!='\r' && senha[p]!='\b')
            {
                printf("*");
            }
            if(senha[p]=='\b' && p >= 1)
            {
                p-=2;
                SetCursorPosition(29+p, 10);
                printf(" ");
                SetCursorPosition(29+p, 10);
            }
            p++;
        }
        while(senha[p-1]!='\r');
        senha[p-1]='\0';

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
            {
                FILE *listaPacientes;
                listaPacientes = fopen("listaPacientes.txt", "r");

                if (listaPacientes == NULL)
                {
                    printf("  [!] Não há pacientes cadastrados! Pressione ENTER para continuar...");
                    break;
                }

                char pacientes[1500];

                while (fgets(pacientes, 1500, listaPacientes) != NULL)
                {
                    printf("%s", pacientes);
                }

                fclose(listaPacientes);

                break;
            }

            case 2:
            {
                FILE *grupoDeRisco;
                grupoDeRisco = fopen("grupoDeRisco.txt", "r");

                if (grupoDeRisco == NULL)
                {
                    printf("  [!] Não há pacientes com comorbidades! Pressione ENTER para continuar...");
                    break;
                }

                char comorbidades[1500];

                while (fgets(comorbidades, 1500, grupoDeRisco) != NULL)
                {
                    printf("%s", comorbidades);
                }

                fclose(grupoDeRisco);

                break;
            }

            case 3:
            {
                PACIENTE novoPaciente;

                system("cls");
                printf("\n  #-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#");
                printf("\n  |                                                                          |");
                printf("\n  |                       CADASTRO DE NOVO PACIENTE                          |");
                printf("\n  |                                                                          |");
                printf("\n  |  NOME: ______________________________       CPF: _____________           |");
                printf("\n  |                                                                          |");
                printf("\n  |  TELEFONE: _______________       NASCIMENTO: __ / __ / ____              |");
                printf("\n  |                                                                          |");
                printf("\n  |  RUA: _____________________      N: ____    BAIRRO: ________________     |");
                printf("\n  |                                                                          |");
                printf("\n  |  CIDADE: _______________         ESTADO: __     CEP: _________           |");
                printf("\n  |                                                                          |");
                printf("\n  |  E-MAIL: ______________________________   DIAGNOSTICO: __ / __ / ____    |");
                printf("\n  |                                                                          |");
                printf("\n  |  COMORBIDADES: __________________________________________________        |");
                printf("\n  |                                                                          |");
                printf("\n  #--------------------------------------------------------------------------#");

                SetCursorPosition(11, 5);
                scanf("%s", &novoPaciente.nome);

                SetCursorPosition(28, 5);
                scanf("%s", &novoPaciente.cpf);

                SetCursorPosition(28, 7);
                scanf("%s", &novoPaciente.telefone);

                SetCursorPosition(28, 7);
                scanf("%i", &novoPaciente.nasc.dia);

                SetCursorPosition(28, 7);
                scanf("%i", &novoPaciente.nasc.mes);

                SetCursorPosition(28, 7);
                scanf("%i", &novoPaciente.nasc.ano);

                SetCursorPosition(28, 9);
                scanf("%s", &novoPaciente.endereco.rua);

                SetCursorPosition(28, 9);
                scanf("%s", &novoPaciente.endereco.n);

                SetCursorPosition(28, 9);
                scanf("%s", &novoPaciente.endereco.bairro);

                SetCursorPosition(28, 11);
                scanf("%s", &novoPaciente.endereco.cidade);

                SetCursorPosition(28, 11);
                scanf("%s", &novoPaciente.endereco.estado);

                SetCursorPosition(28, 11);
                scanf("%s", &novoPaciente.endereco.cep);

                SetCursorPosition(28, 13);
                scanf("%s", &novoPaciente.email);

                SetCursorPosition(28, 13);
                scanf("%i", &novoPaciente.diagnostico.dia);

                SetCursorPosition(28, 13);
                scanf("%i", &novoPaciente.diagnostico.mes);

                SetCursorPosition(28, 13);
                scanf("%i", &novoPaciente.diagnostico.ano);

                SetCursorPosition(28, 15);
                scanf("%s", &novoPaciente.comorbidades);

                break;
            }

            case 0:
            {
                break;
            }

            default:
            {
                printf("\n\n  [!] Opção inválida! Pressione ENTER para continuar...");
                getch();
                break;
            }

        }

    }
    while (opcao != 0);


    return 0;
}
