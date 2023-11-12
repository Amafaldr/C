#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char nome[50];
    int idade;
    float peso;
    float altura;
    int id;
} Paciente;

typedef struct No
{
    Paciente paciente;
    struct No* proximo;
} NoFila;

typedef struct
{
    NoFila* inicio;
    NoFila* fim;
} FilaEspera;

void inicializarFila(FilaEspera* fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

Paciente* buscarPaciente(FilaEspera* fila,int posicao)
{
    int i =0;
    NoFila* atual = fila->inicio;
    while (atual != NULL && i < posicao)
    {
        atual = atual->proximo;
        i++;
    }
    if (i== posicao && atual != NULL)
    {
        return &(atual->paciente);
    }
    else
    {
        return NULL;
    }
}

void adicionarPaciente(FilaEspera* fila, Paciente novoPaciente)
{
    NoFila* novoNo = (NoFila*)malloc(sizeof(NoFila));
    novoNo->paciente = novoPaciente;
    novoNo->proximo = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    else
    {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }

    printf("Paciente adicionado à fila: %s\n", novoPaciente.nome);
}
void chamarProximoPaciente(FilaEspera* fila) {
    if (fila->inicio != NULL) {
        NoFila* temp = fila->inicio;
        fila->inicio = fila->inicio->proximo;

        printf("Chamando paciente: %s\n", temp->paciente.nome);

        free(temp);
    } else {
        printf("Nao ha pacientes na fila.\n");
    }
}

void listarPacientes(FilaEspera* fila)
{
    NoFila* atual = fila->inicio;
    printf("Pacientes na fila de espera:\n");
    while (atual != NULL)
    {
        printf("-%s\n",atual->paciente.nome);
        atual = atual->proximo;
    }
}

void adicionarPacientePrioridade(FilaEspera* fila,Paciente novoPaciente)
{
    NoFila* novoNo = (NoFila*)malloc(sizeof(NoFila));
    novoNo->paciente=novoPaciente;
    novoNo->proximo=fila->inicio;
    fila->inicio = novoNo;

    printf("Paciente com prioridade adicionado a fila :) \t: %s\n", novoPaciente.nome);
}

int main ()
{
    FilaEspera fila;
    inicializarFila(&fila);
    int opcao;

    do
    {
        printf("\n### Controle da Fila de Espera ###\n");
        printf("1. Buscar paciente pela posicao na fila\n");
        printf("2. Chamar proximo paciente\n");
        printf("3. Adicionar novo paciente à fila\n");
        printf("4. Listar todos os pacientes na fila\n");
        printf("5. Adicionar paciente com prioridade\n");
        printf("0. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            int posicao;
            printf("Digite a posicao do paciente na fila: ");
            scanf("%d", &posicao);
            Paciente* paciente = buscarPaciente(&fila, posicao);
            if (paciente != NULL)
            {
                printf("Paciente na posicao %d: %s\n", posicao, paciente->nome);
            }
            else
            {
                printf("Nao ha paciente nessa posicao.\n");
            }
            break;
        }

        case 2:
        {
            chamarProximoPaciente(&fila);
            ///printf("funcao em desenvolvimento\n");
            break;
        }

        case 3:
        {
            Paciente novoPaciente;
            printf("Nome: ");
            scanf("%s", novoPaciente.nome);
            adicionarPaciente(&fila, novoPaciente);
            break;
        }

        case 4:
        {
            listarPacientes(&fila);
            break;
        }

        case 5:
        {
            Paciente novoPacientePrioritario;
            printf("Nome do paciente prioritario: ");
            scanf("%s", novoPacientePrioritario.nome);
            adicionarPacientePrioridade(&fila, novoPacientePrioritario);
            break;
        }

        case 0:
        {
            printf("Encerrando o programa. Obrigado!\n");
            break;
        }

        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    while (opcao != 0);

    return 0;
}


