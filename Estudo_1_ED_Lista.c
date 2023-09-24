#include<stdio.h>
#include<stdlib.h>


struct node
{
    int dado;
    struct node* proximo;
};
/// programa principal
int main ()
{
    struct node* head = NULL;
    int operador;
    float valor1;
    float valor2;
    float resultado;

    printf("Seja bem vindo, digite o valor correspondente para realizar a operacao\n");
    printf("1. Soma\n");
    printf("2. Subitracao\n");
    printf("3. Multiplicacao\n");
    printf("4. Divisao\n");
    while (scanf("%d", &operador) < 1 || operador < 1 || operador > 4)//validando a entrada do menu
    {
        printf("Entrada invalida. Digite novamente (1 a 4): ");
        while (getchar() != '\n'); // Limpar o buffer de entrada
    }


    struct node* novonode =(struct node*)malloc(sizeof(struct node));// alocando a memoria utilizando a opção escolhida no menu
    novonode->dado = operador;
    novonode->proximo = NULL;

    if(head == NULL)
    {
        head = novonode;
    }
    else
    {
        struct node* current = head;
        while (current->proximo != NULL)
        {
            current=current->proximo;
        }
        current->proximo=novonode;
    }

    if (operador == 1)// assim como em todas as operações, não permite digitar um valor invalido
    {
        printf("Digite o valor do primeiro numero\n");
        while(scanf("%f", &valor1)!=1)
        {
            printf("Entrada Invalida, digite novamente\n");
            while (getchar()!='\n');
        }
        printf("Digite o valor do segundo numero\n");
        while(scanf("%f", &valor2)!=1)
        {
            printf("Entrada Invalida, digite novamente\n");
            while (getchar()!='\n');
        }


        resultado=valor1+valor2;

        printf("A operacao escolhida foi: Soma\n");
        printf("O primeiro valor digitado foi: %2.f\n",valor1);
        printf("O segundo valor digitado foi: %2.f\n",valor2);
        printf("O resultado e: %2.f\n", resultado);

    }

    if (operador == 2)
    {
        printf("Digite o valor do primeiro numero\n");
        while(scanf("%f", &valor1)!=1)
        {
            printf("Entrada Invalida, digite novamente\n");
            while (getchar()!='\n');
        }
        printf("Digite o valor do segundo numero\n");
        while(scanf("%f", &valor2)!=1)
        {
            printf("Entrada Invalida, digite novamente\n");
            while (getchar()!='\n');
        }


        resultado=valor1-valor2;

        printf("A operacao escolhida foi: Subtracao\n");
        printf("O primeiro valor digitado foi: %2.f\n",valor1);
        printf("O segundo valor digitado foi: %2.f\n",valor2);
        printf("O resultado e: %2.f\n", resultado);

    }
    if (operador == 3)
    {
        printf("Digite o valor do primeiro numero\n");
        while(scanf("%f", &valor1)!=1)
        {
            printf("Entrada Invalida, digite novamente\n");
            while (getchar()!='\n');
        }
        printf("Digite o valor do segundo numero\n");
        while(scanf("%f", &valor2)!=1)
        {
            printf("Entrada Invalida, digite novamente\n");
            while (getchar()!='\n');
        }


        resultado=valor1*valor2;

        printf("A operacao escolhida foi: Multiplicacao\n");
        printf("O primeiro valor digitado foi: %2.f\n",valor1);
        printf("O segundo valor digitado foi: %2.f\n",valor2);
        printf("O resultado e: %2.f\n", resultado);

    }
    if (operador == 4)
    {
        printf("Digite o valor do primeiro numero\n");
        while(scanf("%f", &valor1)!=1)
        {
            printf("Entrada Invalida, digite novamente\n");
            while (getchar()!='\n');
        }
        printf("Digite o valor do segundo numero\n");
        while(scanf("%f", &valor2)!=1 || valor2 == 0)// aqui tem uma validação especial, não permite que o divisor seja 0.
        {
            printf("Entrada Invalida, digite novamente\n");
            while (getchar()!='\n');
        }

        resultado=valor1/valor2;

        printf("A operacao escolhida foi: Divisao\n");
        printf("O primeiro valor digitado foi: %2.f\n",valor1);
        printf("O segundo valor digitado foi: %2.f\n",valor2);
        printf("O resultado e: %2.f\n", resultado);

        printf("Obrigado\n");// para mostrar a educação do programador, obrigado Vicentini !
        free(head);// liberando a memoria alocada
        return 0;
    }
}
