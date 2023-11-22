#include <stdio.h>
#include <string.h>

struct carro
{
    char placa[10];
    int manobras;
};

void imprimirMensagem(struct carro estacionamento[], int index, int chegada)
{
    if (chegada)
    {
        if (index == -1)
        {
            printf("N�o h� vaga dispon�vel, tente mais tarde\n");
        }
        else
        {
            printf("Carro com a placa %s estacionado\n", estacionamento[index].placa);
        }
    }
    else
    {
        printf("Carro com a placa %s acabou de sair\n", estacionamento[index].placa);
    }
}

int encontrarCarro(struct carro estacionamento[], char placa[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(estacionamento[i].placa, placa) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Fun��o principal
int main()
{
    struct carro estacionamento[10];
    int numCarros = 0;

    while (1)
    {
        printf("\nEscolha uma op��o:\n");
        printf("1 - Carro chegar\n");
        printf("2 - Carro sair\n");
        printf("0 - Sair do programa\n");

        int escolha;
        scanf("%d", &escolha);

        if (escolha == 0)
        {
            break;
        }
        else if (escolha == 1)
        {
            if (numCarros < 10)
            {
                printf("Digite a placa do carro que est� chegando: ");
                scanf("%s", estacionamento[numCarros].placa);

                int pos = encontrarCarro(estacionamento, estacionamento[numCarros].placa);
                imprimirMensagem(estacionamento, pos, 1);

                if (pos == -1)
                {
                    numCarros++;
                }
            }
            else
            {
                printf("Estacionamento lotado. N�o � poss�vel receber mais carros.\n");
            }
        }
        else if (escolha == 2)
        {
            char placaSaida[10];
            printf("Digite a placa do carro que est� saindo: ");
            scanf("%s", placaSaida);

            int pos = encontrarCarro(estacionamento, placaSaida);
            if (pos != -1)
            {
                for (int i = pos; i < numCarros - 1; i++)
                {
                    estacionamento[i] = estacionamento[i + 1];
                }
                numCarros--;
                imprimirMensagem(estacionamento, pos, 0);
            }
            else
            {
                printf("Carro com placa %s n�o encontrado no estacionamento.\n", placaSaida);
            }
        }
        else
        {
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    }

    return 0;
}
