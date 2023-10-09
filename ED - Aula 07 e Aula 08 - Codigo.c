#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void criar_lista(Lista *lista) {
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_no_inicio(Lista *lista, int num) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->valor = num;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
}

void buscar(Lista *lista, int num) {
    No *no = lista->inicio;
    while (no != NULL) {
        if (no->valor == num) {
            printf("Elemento encontrado: %d\n", no->valor);
            return;
        }
        no = no->proximo;
    }
    printf("Elemento nao encontrado!\n");
}

No* remover(Lista *lista, int num) {
    No *aux, *remover = NULL;

    if (lista->inicio != NULL) {
        if (lista->inicio->valor == num) {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
            free(remover);
            return remover;
        } else {
            aux = lista->inicio;
            while (aux->proximo != NULL && aux->proximo->valor != num) {
                aux = aux->proximo;
            }
            if (aux->proximo != NULL) {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
                free(remover);
                return remover;
            }
        }
    }
    return NULL;
}

void imprimir(Lista *lista) {
    No *no = lista->inicio;
    printf("\n\tLista tam %d: ", lista->tam);
    while (no != NULL) {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main() {
    int opcao, valor;
    Lista lista;
    No *removido;

    criar_lista(&lista);

    do {
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - InserirF\n\t3 - Remover\n\t4 - Exibir\n\t5 - Buscar\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_no_inicio(&lista, valor);
                printf("Elemento inserido com sucesso!\n");
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &valor);
//                inserir_no_fim(&lista, valor);
                printf("Elemento inserido com sucesso!\n");
                break;
            case 3:
                printf("Digite um valor a ser removido: ");
                scanf("%d", &valor);
                removido = remover(&lista, valor);
                if (removido) {
                    printf("Elemento removido: %d\n", removido->valor);
                    free(removido);
                } else {
                    printf("Elemento inexistente!\n");
                }
                break;
            case 4:
                imprimir(&lista);
                break;
            case 5:
                printf("Digite um valor a ser buscado: ");
                scanf("%d", &valor);
                buscar(&lista, valor);
                break;
            default:
                if (opcao != 0) {
                    printf("Opcao invalida!\n");
                }
        }

    } while (opcao != 0);

    return 0;
}
