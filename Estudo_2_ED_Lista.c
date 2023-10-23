#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defini��o da estrutura anime
struct anime
{
    char nome[100];
    int duracao;
    float nota;
    struct anime *anterior;
    struct anime *proximo;
};

// Fun��o para adicionar um anime
struct anime *addanime(const char nome[100], int duracao, float nota)
{
    struct anime *novoanime = (struct anime*)malloc(sizeof(struct anime));
    if (novoanime != NULL)
    {
        strncpy(novoanime->nome, nome, 100);
        novoanime->duracao = duracao;
        novoanime->nota = nota;
        novoanime->anterior = NULL;
        novoanime->proximo = NULL;
    }
    return novoanime;
}

// Fun��o para incluir o anime no in�cio da lista
void incluirnoinicio(struct anime** lista, struct anime* novoanime)
{
    if (novoanime != NULL)
    {
        novoanime->proximo = *lista;
        if (*lista != NULL)
        {
            (*lista)->anterior = novoanime;
        }
        *lista = novoanime;
    }
}

// Fun��o para incluir no final da lista
void incluirnofinal(struct anime **lista, struct anime* novoanime)
{
    if (novoanime != NULL)
    {
        if (*lista == NULL)
        {
            *lista = novoanime;
        }
        else
        {
            struct anime* atual = *lista;
            while (atual->proximo != NULL)
            {
                atual = atual->proximo;
            }
            atual->proximo = novoanime;
            novoanime->anterior = atual;
        }
    }
}

// Fun��o para mostrar a lista em ordem normal
void ordemnormal(struct anime* lista)
{
    while (lista != NULL)
    {
        printf("Nome: %s\n", lista->nome);
        printf("Dura��o: %d\n", lista->duracao);
        printf("Nota IMDb: %.1f\n", lista->nota);
        printf("\n");
        lista = lista->proximo;
    }
}

// Fun��o para mostrar a lista em ordem inversa
void ordeminversa(struct anime* lista)
{
    if (lista == NULL)
    {
        return;
    }
    while (lista->proximo != NULL)
    {
        lista = lista->proximo;
    }
    while (lista != NULL)
    {
        printf("Nome: %s\n", lista->nome);
        printf("Dura��o: %d\n", lista->duracao);
        printf("Nota IMDb: %.1f\n", lista->nota);
        printf("\n");
        lista = lista->anterior;
    }
}

// Fun��o para pesquisar um anime pela nota
struct anime* pesquisapelanota(struct anime* lista, float nota)
{
    while (lista != NULL)
    {
        if (lista->nota == nota)
        {
            return lista;
        }
        lista = lista->proximo;
    }
    return NULL;
}

int main()
{
    struct anime* lista = NULL;
    int opcao;
    char nome[100];
    int duracao;
    float nota;

    do {
        printf("Escolha uma op��o:\n");
        printf("1. Adicionar um anime\n");
        printf("2. Listar animes em ordem normal\n");
        printf("3. Listar animes em ordem inversa\n");
        printf("4. Pesquisar anime pela nota IMDb\n");
        printf("0. Sair\n");
        printf("Op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do anime: ");
                scanf("%s", nome);
                printf("Digite a dura��o do anime (em minutos): ");
                scanf("%d", &duracao);
                printf("Digite a nota IMDb do anime: ");
                scanf("%f", &nota);
                struct anime *novoanime = addanime(nome, duracao, nota);
                incluirnofinal(&lista, novoanime);
                break;
            case 2:
                printf("Lista de Animes em Ordem Normal:\n");
                ordemnormal(lista);
                break;
            case 3:
                printf("Lista de Animes em Ordem Inversa:\n");
                ordeminversa(lista);
                break;
            case 4:
                printf("Digite a nota IMDb para pesquisar: ");
                scanf("%f", &nota);
                struct anime *animeEncontrado = pesquisapelanota(lista, nota);
                if (animeEncontrado != NULL) {
                    printf("Anime encontrado com nota IMDb %.1f: %s\n", nota, animeEncontrado->nome);
                } else {
                    printf("Nenhum anime encontrado com nota IMDb %.1f\n", nota);
                }
                break;
            case 0:
                // Sair do programa
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Libere a mem�ria antes de sair
    while (lista != NULL) {
        struct anime* temp = lista;
        lista = lista->proximo;
        free(temp);
    }

    return 0;
}


