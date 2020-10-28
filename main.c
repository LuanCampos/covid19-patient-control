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

int fileExists(const char* filename)
{
    FILE *file;
    if (file = fopen(filename, "r"))
    {
        fclose(file);
        return 1;
    }
    return 0;
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

    // Checando os arquivos
    if (fileExists("listaPacientes.txt") == 0)
    {
        FILE *listaPacientes;
        listaPacientes = fopen("listaPacientes.txt", "w");
        fclose(listaPacientes);
    }

    if (fileExists("grupoDeRisco.txt") == 0)
    {
        FILE *grupoDeRisco;
        grupoDeRisco = fopen("grupoDeRisco.txt", "w");
        fclose(grupoDeRisco);
    }

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
                int salvarCadastro = 0;
                int ano = 2020;
                int idade;

                // Cadastro de Paciente
                do
                {
                    char temp;

                    system("cls");
                    printf("\n  #-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#");
                    printf("\n  |                                                                          |");
                    printf("\n  |                       CADASTRO DE NOVO PACIENTE                          |");
                    printf("\n  |                                                                          |");
                    printf("\n  |  NOME: ______________________________       CPF: ____________            |");
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
                    printf("\n\n   (Registre nos campos acima os dados do paciente)");
                    printf("\n   (Caso não haja comorbidades, deixar o campo em branco)");

                    SetCursorPosition(11, 5);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.nome);

                    SetCursorPosition(53, 5);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.cpf);

                    SetCursorPosition(15, 7);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.telefone);

                    SetCursorPosition(49, 7);
                    scanf("%i", &novoPaciente.nasc.dia);

                    SetCursorPosition(54, 7);
                    scanf("%c",&temp);
                    scanf("%i", &novoPaciente.nasc.mes);

                    SetCursorPosition(59, 7);
                    scanf("%i", &novoPaciente.nasc.ano);

                    SetCursorPosition(10, 9);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.endereco.rua);

                    SetCursorPosition(40, 9);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.endereco.n);

                    SetCursorPosition(56, 9);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.endereco.bairro);

                    SetCursorPosition(13, 11);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.endereco.cidade);

                    SetCursorPosition(45, 11);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.endereco.estado);

                    SetCursorPosition(57, 11);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.endereco.cep);

                    SetCursorPosition(13, 13);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.email);

                    SetCursorPosition(59, 13);
                    scanf("%i", &novoPaciente.diagnostico.dia);

                    SetCursorPosition(64, 13);
                    scanf("%c",&temp);
                    scanf("%i", &novoPaciente.diagnostico.mes);

                    SetCursorPosition(69, 13);
                    scanf("%i", &novoPaciente.diagnostico.ano);

                    SetCursorPosition(19, 15);
                    scanf("%c",&temp);
                    scanf("%[^\n]", &novoPaciente.comorbidades);

                    SetCursorPosition(1, 19);
                    printf("                                                                     ");
                    printf("                                                                     ");
                    SetCursorPosition(1, 19);
                    printf("  > Deseja salvar este cadastro? (1 = sim; 0 = não) _");
                    SetCursorPosition(53, 19);
                    scanf("%i",&salvarCadastro);

                }
                while (salvarCadastro != 1);

                FILE *listaPacientes;
                listaPacientes = fopen("listaPacientes.txt", "a");

                fprintf(listaPacientes, "NOME: %s\n", novoPaciente.nome);
                fprintf(listaPacientes, "CPF: %s\n", novoPaciente.cpf);
                fprintf(listaPacientes, "TELEFONE: %s\n", novoPaciente.telefone);
                fprintf(listaPacientes, "ENDEREÇO: %s, nº %s\n", novoPaciente.endereco.rua, novoPaciente.endereco.n);
                fprintf(listaPacientes, "BAIRRO: %s\n", novoPaciente.endereco.bairro);
                fprintf(listaPacientes, "CIDADE: %s - %s\n", novoPaciente.endereco.cidade, novoPaciente.endereco.estado);
                fprintf(listaPacientes, "CEP: %s\n", novoPaciente.endereco.cep);
                fprintf(listaPacientes, "DATA DE NASCIMENTO: %s / %s / %d\n", novoPaciente.nasc.dia, novoPaciente.nasc.mes, novoPaciente.nasc.ano);
                fprintf(listaPacientes, "E-MAIL: %s\n", novoPaciente.email);
                fprintf(listaPacientes, "DATA DO DIAGNÓSTICO: %s / %s / %d\n", novoPaciente.diagnostico.dia, novoPaciente.diagnostico.mes, novoPaciente.diagnostico.ano);
                fprintf(listaPacientes, "COMORBIDADES: %s\n\n\n", novoPaciente.comorbidades);
                idade = ano - novoPaciente.nasc.ano;

                fclose(listaPacientes);

                FILE *grupoDeRisco;
                grupoDeRisco = fopen("grupoDeRisco.txt", "a");

                if (idade >= 65)
                {
                    fprintf(grupoDeRisco, "IDADE: %d\n", idade);
                    fprintf(grupoDeRisco, "CEP: %s\n\n\n", novoPaciente.endereco.cep);
                }

                fclose(grupoDeRisco);

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
