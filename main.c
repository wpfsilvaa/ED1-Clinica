#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int CodPac;
    char Nome[100];
    char fone[12];
} paciente;
typedef struct
{
    int horas;
    int minutos;
    int segundos;
} horario;
typedef struct
{
    int dia;
    int mes;
    int ano;
    horario hora;
} data;
typedef struct
{
    int CodCons;
    int CodPac;
    data date;
} consulta;


int main()
{
    paciente paciente[50];
    consulta consulta[50];

    int n_pac = 0, codigo, cod_aux = 0,duplicado = 0,existe = 0, n_cons = 0;
    int op;
    do
    {
        system("cls");
        printf("[1]Cadastrar dados pessoais[Pacientes Cadastrados:%d]\n[2]Agendar consulta[Consultas Agendadas:%d]\n[3]Listar Agendamentos\n[4]Alterar Horario da consulta\n[5]Alterar Data da consulta\n[9]Sair\n\nDigite a opcao:\nMENU:",n_pac,n_cons);
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            duplicado = 0;
            printf("Cadastro de dados pessoais:\n");
            printf("Digite o codigo do paciente: ");
            scanf("%d", &paciente[n_pac].CodPac);

            for (int i = 0; i < n_pac ; i++)
            {
                if (paciente[n_pac].CodPac == paciente[i].CodPac)
                {

                    printf("Paciente %s[ID:%d] ja existe !!", paciente[i].Nome, paciente[i].CodPac);
                    duplicado = 1;
                    printf("\nPressione qualquer tecla para continuar. . .");
                    getch();
                }
            }
            if (duplicado == 0)
            {
                setbuf(stdin,NULL);
                printf("Digite o nome do paciente: ");
                fgets(paciente[n_pac].Nome,99,stdin);
                setbuf(stdin,NULL);
                paciente[n_pac].Nome[strcspn(paciente[n_pac].Nome, "\n")] = 0; // Retirar /n da string
                printf("Digite o telefone: ");
                fgets(paciente[n_pac].fone,11,stdin);
                paciente[n_pac].fone[strcspn(paciente[n_pac].fone, "\n")] = 0;
                n_pac = n_pac +1;
                printf("Paciente adicionado com sucesso!!");
                printf("\nPressione qualquer tecla para continuar. . .");
                getch();
            }
            break;

        case 2:
            if (n_pac == 0)
            {
                printf("Nao existem pacientes cadastrados no momento, realize o cadastro!\n");
                printf("\nPressione qualquer tecla para continuar. . .");
                getch();
                break;
            }
            existe = 0;
            duplicado = 0;
            printf("Agendamento de consultas:\n");
            printf("Digite o codigo do paciente: ");
            scanf("%d", &codigo);
            for (int i = 0; i < n_pac ; i++)
            {
                if (codigo == paciente[i].CodPac)
                {
                    cod_aux = i;
                    existe = 1;
                }
            }
            if (existe == 1)
            {
                printf("Marcando horario para: %s\n", paciente[cod_aux].Nome);
                consulta[n_cons].CodPac = paciente[cod_aux].CodPac;
                printf("Digite o codigo da consulta: ");
                scanf("%d", &codigo);
                for (int i = 0; i < n_cons; i++)
                {
                    if ( codigo == consulta[i].CodCons)
                    {
                        while ( codigo == consulta[i].CodCons)
                        {

                            printf("Consulta ja no sistema!\n");
                            printf("Digite o codigo da consulta:");
                            scanf("%d", &codigo);
                            i = 0;
                        }
                    }
                }
                consulta[n_cons].CodCons = codigo;
                do
                {
                    printf("Hora[XX]: ");
                    scanf("%d", &consulta[n_cons].date.hora.horas);
                    if(consulta[n_cons].date.hora.horas < 0 || consulta[n_cons].date.hora.horas > 23)
                        printf("Digite um dado valido!\n");
                }
                while(consulta[n_cons].date.hora.horas < 0 || consulta[n_cons].date.hora.horas > 23);
                do
                {
                    printf("Minutos[XX]: ");
                    scanf("%d", &consulta[n_cons].date.hora.minutos);
                    if(consulta[n_cons].date.hora.minutos <0 || consulta[n_cons].date.hora.minutos > 59)
                        printf("Digite um dado valido!\n");
                }
                while (consulta[n_cons].date.hora.minutos <0 || consulta[n_cons].date.hora.minutos > 59);
                do
                {
                    printf("Segundos[XX]: ");
                    scanf("%d", &consulta[n_cons].date.hora.segundos);
                    if(consulta[n_cons].date.hora.segundos < 0 || consulta[n_cons].date.hora.segundos > 59)
                        printf("Digite um dado valido!\n");
                }
                while (consulta[n_cons].date.hora.segundos < 0 || consulta[n_cons].date.hora.segundos > 59);
                do
                {
                    printf("Dia[XX]: ");
                    scanf("%d", &consulta[n_cons].date.dia);
                    if(consulta[n_cons].date.dia < 1 || consulta[n_cons].date.dia > 31)
                        printf("Digite um dado valido!\n");
                }
                while (consulta[n_cons].date.dia < 1 || consulta[n_cons].date.dia > 31);
                do
                {
                    printf("Mes[XX]: ");
                    scanf("%d", &consulta[n_cons].date.mes);
                    if( consulta[n_cons].date.mes < 1 || consulta[n_cons].date.mes > 12)
                        printf("Digite um dado valido!\n");
                }
                while ( consulta[n_cons].date.mes < 1 || consulta[n_cons].date.mes > 12);
                do
                {

                    printf("Ano[XXXX]: ");

                    scanf("%d", &consulta[n_cons].date.ano);
                    if (consulta[n_cons].date.ano > 0 && consulta[n_cons].date.ano < 99)
                    {
                        consulta[n_cons].date.ano = (consulta[n_cons].date.ano)+2000;
                    }
                    if (consulta[n_cons].date.ano < 2000 || consulta[n_cons].date.ano > 2099)
                        printf("Digite um dado valido!\n");
                }
                while (consulta[n_cons].date.ano < 2000 || consulta[n_cons].date.ano > 2099);
                for (int i = 0; i < n_cons ; i++)
                {
                    if ( consulta[n_cons].CodPac == consulta[i].CodPac && consulta[i].date.dia == consulta[n_cons].date.dia && consulta[i].date.mes == consulta[n_cons].date.mes && consulta[i].date.ano == consulta[n_cons].date.ano)
                    {
                        printf("Consulta ja existente!\n");
                        duplicado = 1;
                        printf("\nPressione qualquer tecla para continuar. . .");
                        getch();
                        break;
                    }
                }
                if (duplicado != 1)
                {

                    printf("\nDados salvos com sucesso!!\nPaciente: %s\nHorario marcado: %d:%d:%d para o dia: %d/%d/%d",paciente[cod_aux].Nome,consulta[n_cons].date.hora.horas,consulta[n_cons].date.hora.minutos,consulta[n_cons].date.hora.segundos,consulta[n_cons].date.dia,consulta[n_cons].date.mes,consulta[n_cons].date.ano);
                    n_cons++;
                    printf("\nPressione qualquer tecla para continuar. . .");
                    getch();
                    break;
                }
                if (duplicado == 1)
                    break;
            }
            else
            {

                printf("Nao existe o paciente no sistema!");
                printf("\nPressione qualquer tecla para continuar. . .");
                getch();
                break;
            }
            break;

        case 3:
            if (n_pac == 0)
            {
                printf("Nao existem pacientes cadastrados, faca o cadastro!\n");
                printf("\nPressione qualquer tecla para continuar. . .");
                getch();
                break;
            }
            existe = 0;
            printf("Listagem de Agendamentos:\n");
            printf("Digite o codigo do paciente: ");
            scanf("%d", &codigo);
            for (int i = 0; i < n_pac ; i++)
            {
                if (codigo == paciente[i].CodPac)
                {
                    cod_aux = i;
                    existe = 1;
                }
            }
            if (existe == 1)
            {
                for ( int i = 0; i < n_cons ; i++)
                {
                    if ( codigo == consulta[i].CodPac)
                    {
                        printf("===================================\n");
                        printf("Codigo do paciente: %d\n", paciente[cod_aux].CodPac);
                        printf("Nome: %s\n", paciente[cod_aux].Nome);
                        printf("Data da consulta: %d/%d/%d\n",consulta[i].date.dia,consulta[i].date.mes,consulta[i].date.ano);
                        printf("Horario da Consulta: %d:%d:%d\n",consulta[i].date.hora.horas,consulta[i].date.hora.minutos,consulta[i].date.hora.segundos);
                        printf("Codigo da consulta: %d\n", consulta[i].CodCons);
                        printf("===================================\n");
                    }
                }

                printf("Pressione qualquer tecla para continuar. . .");
                getch();
            }
            else
            {
                printf("Nao existem consultas cadastradas para esse paciente.");
                printf("\nPressione qualquer tecla para continuar. . .");
                getch();
                break;
            }
            break;

        case 4:
            if (n_pac == 0)
            {
                printf("Nao existem pacientes cadastrados, faca o cadastro!\n");
                printf("\nPressione qualquer tecla para continuar. . .");
                getch();
                break;
            }
            existe = 0;
            printf("Digite o codigo do paciente: ");
            scanf("%d", &codigo);
            for (int i = 0; i < n_pac ; i++)
            {
                if (codigo == paciente[i].CodPac)
                {
                    cod_aux = i;
                    existe = 1;
                }
            }
            if (existe == 1)
            {
                for ( int i = 0; i < n_cons ; i++)
                {
                    if ( codigo == consulta[i].CodPac )
                    {
                        printf("===================================\n");
                        printf("Codigo da consulta: %d\n", consulta[i].CodCons);
                        printf("Codigo do paciente: %d\n", paciente[cod_aux].CodPac);
                        printf("Nome: %s\n", paciente[cod_aux].Nome);
                        printf("Data da consulta: %d/%d/%d\n",consulta[i].date.dia,consulta[i].date.mes,consulta[i].date.ano);
                        printf("Horario da Consulta: %d:%d:%d\n",consulta[i].date.hora.horas,consulta[i].date.hora.minutos,consulta[i].date.hora.segundos);
                        printf("===================================\n");
                    }
                }
                printf("Digite o codigo da consulta a ser alterada: ");
                scanf("%d", &codigo);
                for (int i = 0; i < n_cons ; i++)
                {
                    if ( codigo == consulta[i].CodCons)
                    {
                        printf("Digite o novo horario:\n");
                        do
                        {
                            printf("Hora[XX]: ");
                            scanf("%d", &consulta[i].date.hora.horas);
                            if(consulta[i].date.hora.horas < 0 || consulta[i].date.hora.horas > 23)
                                printf("Digite um dado valido!\n");
                        }
                        while(consulta[i].date.hora.horas < 0 || consulta[i].date.hora.horas > 23);
                        do
                        {
                            printf("Minutos[XX]: ");
                            scanf("%d", &consulta[i].date.hora.minutos);
                            if(consulta[i].date.hora.minutos <0 || consulta[i].date.hora.minutos > 59)
                                printf("Digite um dado valido!\n");
                        }
                        while (consulta[i].date.hora.minutos <0 || consulta[i].date.hora.minutos > 59);
                        do
                        {
                            printf("Segundos[XX]: ");
                            scanf("%d", &consulta[i].date.hora.segundos);
                            if(consulta[i].date.hora.segundos < 0 || consulta[i].date.hora.segundos > 59)
                                printf("Digite um dado valido!\n");
                        }
                        while (consulta[i].date.hora.segundos < 0 || consulta[i].date.hora.segundos > 59);
                    }
                }
                printf("Alterado com sucesso!");
                getch();
            }
            else
            {
                printf("Nao existem consultas cadastradas para esse paciente.");
                printf("\nPressione qualquer tecla para continuar. . .");
                getch();
                break;
            }
            break;

        case 5:
            if (n_pac == 0)
            {
                printf("Nao existem pacientes cadastrados, faca o cadastro!\n");
                printf("\nPressione qualquer tecla para continuar. . .");
                getch();
                break;
            }
            existe = 0;
            printf("Digite o codigo do paciente: ");
            scanf("%d", &codigo);
            for (int i = 0; i < n_pac ; i++)
            {
                if (codigo == paciente[i].CodPac)
                {
                    cod_aux = i;
                    existe = 1;
                }
            }
            if (existe == 1)
            {
                for ( int i = 0; i < n_cons ; i++)
                {
                    if ( codigo == consulta[i].CodPac )
                    {
                        printf("===================================\n");
                        printf("Codigo da consulta: %d\n", consulta[i].CodCons);
                        printf("Codigo do paciente: %d\n", paciente[cod_aux].CodPac);
                        printf("Nome: %s\n", paciente[cod_aux].Nome);
                        printf("Data da consulta: %d/%d/%d\n",consulta[i].date.dia,consulta[i].date.mes,consulta[i].date.ano);
                        printf("Horario da Consulta: %d:%d:%d\n",consulta[i].date.hora.horas,consulta[i].date.hora.minutos,consulta[i].date.hora.segundos);
                        printf("===================================\n");
                    }
                }
                printf("Digite o codigo da consulta a ser alterada: ");
                scanf("%d", &codigo);
                for (int i = 0; i < n_cons ; i++)
                {
                    if ( codigo == consulta[i].CodCons)
                    {
                        printf("Digite a nova data:");
                        do
                        {
                            printf("\nDia[XX]: ");
                            scanf("%d", &consulta[i].date.dia);
                            if(consulta[i].date.dia < 1 || consulta[i].date.dia > 31)
                                printf("Digite um dado valido!\n");
                        }
                        while (consulta[i].date.dia < 1 || consulta[i].date.dia > 31);
                        do
                        {
                            printf("Mes[XX]: ");
                            scanf("%d", &consulta[i].date.mes);
                            if( consulta[i].date.mes < 1 || consulta[i].date.mes > 12)
                                printf("Digite um dado valido!\n");
                        }
                        while ( consulta[i].date.mes < 1 || consulta[i].date.mes > 12);
                        do
                        {
                            printf("Ano[XXXX]: ");
                            scanf("%d", &consulta[i].date.ano);
                            if (consulta[i].date.ano > 0 && consulta[i].date.ano < 99)
                            {
                                consulta[i].date.ano = (consulta[i].date.ano)+2000;
                            }
                            if (consulta[i].date.ano < 2000 || consulta[i].date.ano > 2099)

                                printf("Digite um dado valido!\n");
                        }
                        while (consulta[i].date.ano < 2000 || consulta[i].date.ano > 2099);
                    }
                }
                printf("Alterado com sucesso!");
                getch();
            }
            else
            {
                printf("Nao existem consultas cadastradas para esse paciente.");
                printf("\nPressione qualquer tecla para continuar. . .");
                getch();
                break;
            }
            break;
        }
    }
    while(op != 9);
    printf("Obrigado por usar nosso sistema!");
    getch();
    return 0;
}

