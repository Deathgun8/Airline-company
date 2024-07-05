#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, lugaresVoo[3], menu = 0, consulta = 0, count = 0, lugaresReservados, reserva;
    char origemVoo[3][60], destinoVoo[3][60], numeroVoo[3][11], checkNum[11], checkOrigem[60], checkDestino[60];
    char confirmacao;

    for (i = 0; i < 3; i++)
    {
        printf("\n%d aviao\n", i + 1);
        printf("----------------------------------------------------------------------------------------------------");
        printf("\nNumero do voo: ");
        scanf(" %s", numeroVoo[i]);
        printf("Origem do voo: ");
        scanf(" %s", origemVoo[i]);
        printf("Destino do voo: ");
        scanf(" %s", destinoVoo[i]);
        printf("Numero de lugares disponiveis no voo: ");
        scanf("%d", &lugaresVoo[i]);
    }

    while (menu != 4)
    {
        if (menu == 0)
        {
            printf("\nMenu do usuario\n");
            printf("----------------------------------------------------------------------------------------------------");
            printf("\nEscolha uma opcao:\nDigite 1 para consultar um voo.\nDigite 2 para efetuar uma reserva.\nDigite 4 para encerrar o programa.\n");
            scanf("%d", &menu);
        }

        // menu para consultar um voo
        if (menu == 1)
        {
            printf("\nBem vindo, faca sua consulta por:\n1 - Numero do voo\n2 - Origem do voo\n3 - Destino do voo\n4 - Voltar ao menu principal\n");
            scanf("%d", &consulta);
            switch (consulta)
            {
            // verificar se o numero do voo esta disponivel
            case 1:
                printf("Digite o numero do voo para ver se esta disponivel: ");
                scanf(" %s", checkNum);

                count = 0;
                confirmacao = '\0';

                for (i = 0; i < 3; i++)
                {
                    if (strcmp(checkNum, numeroVoo[i]) == 0)
                    {
                        count++;
                        while (confirmacao != 'S' && confirmacao != 's' && confirmacao != 'N' && confirmacao != 'n')
                        {
                            printf("\nO numero do voo esta disponivel!\nDeseja realizar a reserva? (Digite S ou N) ");
                            scanf(" %c", &confirmacao);
                            if (confirmacao == 'S' || confirmacao == 's')
                            {
                                menu = 2;
                            }
                            else if (confirmacao == 'N' || confirmacao == 'n')
                            {
                                menu = 1;
                            }
                        }
                    }
                }

                if (count == 0)
                {
                    printf("\nO numero do voo incorreto\n");
                }
                break;
            // verificar o voo pela origem
            case 2:
                printf("Digite a origem do voo para ver se ha algum disponivel: ");
                scanf(" %s", checkOrigem);

                count = 0;
                confirmacao = '\0';

                for (i = 0; i < 3; i++)
                {
                    if (strcmp(checkOrigem, origemVoo[i]) == 0)
                    {
                        count++;
                    }
                }

                if (count == 0)
                {
                    printf("\nOrigem do voo incorreta\n");
                }
                else
                {
                    while (confirmacao != 'S' && confirmacao != 's' && confirmacao != 'N' && confirmacao != 'n')
                    {
                        printf("\nHa %d voos saindo da origem inserida\nDeseja realizar a reserva? (Digite S ou N) ", count);
                        scanf(" %c", &confirmacao);
                        if (confirmacao == 'S' || confirmacao == 's')
                        {
                            menu = 2;
                        }
                        else if (confirmacao == 'N' || confirmacao == 'n')
                        {
                            menu = 1;
                        }
                    }
                }
                break;
            // verificar voo pelo destino
            case 3:
                printf("Digite o destino do voo para ver se ha algum disponivel: ");
                scanf(" %s", checkDestino);

                count = 0;
                confirmacao = '\0';

                for (i = 0; i < 3; i++)
                {
                    if (strcmp(checkDestino, destinoVoo[i]) == 0)
                    {
                        count++;
                    }
                }

                if (count == 0)
                {
                    printf("\nDestino do voo incorreto\n");
                }
                else
                {
                    while (confirmacao != 'S' && confirmacao != 's' && confirmacao != 'N' && confirmacao != 'n')
                    {
                        printf("\nHa %d voos para o destino inserido\nDeseja realizar a reserva? (Digite S ou N) ", count);
                        scanf(" %c", &confirmacao);
                        if (confirmacao == 'S' || confirmacao == 's')
                        {
                            menu = 2;
                        }
                        else if (confirmacao == 'N' || confirmacao == 'n')
                        {
                            menu = 1;
                        }
                    }
                }
                break;
            // voltar ao menu principal
            case 4:
                menu = 0;
                break;
            default:
                break;
            }
        }

        // menu para efetuar uma reserva
        if (menu == 2)
        {
            printf("Bem vindo ao menu reserva\nDigite 1 para voltar ao menu principal\nDigite 2 para realizar a reserva\n");
            scanf(" %d", &reserva);

            if (reserva == 1)
            {
                menu = 0;
            }
            else if (reserva == 2)
            {
                printf("Digite o numero do voo para fazer a reserva: ");
                scanf(" %s", checkNum);

                count = 0;
                confirmacao = '\0';

                for (i = 0; i < 3; i++)
                {
                    if (strcmp(checkNum, numeroVoo[i]) == 0)
                    {
                        if (lugaresVoo[i] > 0)
                        {
                            count++;
                            break;
                        }
                        else
                        {
                            count = -1;
                            break;
                        }
                    }
                }

                if (count == 0)
                {
                    printf("\nDestino do voo incorreto\n");
                }
                else if (count > 0)
                {
                    while (confirmacao != 'S' && confirmacao != 's' && confirmacao != 'N' && confirmacao != 'n')
                    {
                        printf("\nAinda ha %d lugares disponiveis no voo, deseja realizar reserva? ", lugaresVoo[i]);
                        scanf(" %c", &confirmacao);
                        if (confirmacao == 'S' || confirmacao == 's')
                        {
                            printf("\nQuantos lugares deseja reservar? ");
                            do
                            {
                                scanf("%d", &lugaresReservados);
                                if(lugaresReservados > lugaresVoo[i])
                                {
                                    printf("A quantidade que voce esta tentando reservar e maior que a quantidade de lugares no voo, por favor digite novamente ");
                                }
                            } while (lugaresReservados > lugaresVoo[i]);

                            printf("\nSua reserva de %d lugares no voo %s foi confirmada!\n", lugaresReservados, checkNum);
                            lugaresVoo[i] = lugaresVoo[i] - lugaresReservados;
                        }
                        else if (confirmacao == 'N' || confirmacao == 'n')
                        {
                            menu = 2;
                        }
                    }
                }
                else
                {
                    printf("\nNao ha lugares disponiveis para esse voo");
                }
            } else {
                menu = 2;
            }
        }
    }
}