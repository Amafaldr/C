#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Aluno
{
    int RA_aluno[14];
    char nome_aluno[100];
    struct Aluno*proximo;
};

struct Aluno* novoAluno(int RA_aluno[],char nome_aluno[])
{
    struct Aluno* aluno = (struct Aluno*)malloc(sizeof(struct Aluno));
    strcpy(aluno->RA_aluno, RA_aluno);
    strcpy(aluno->nome_aluno, nome_aluno);
    aluno->proximo = NULL;
    return aluno;
};

int main ()
{
    struct Aluno* listaAlunos=NULL;
    struct Aluno* aluno1 = novoAluno("0040482221000","Rafael");
    struct Aluno* aluno2 = novoAluno("0040482221001","Antonio");
    struct Aluno* aluno3 = novoAluno("0040482221002","Amafaldo");

    aluno1->proximo = listaAlunos;
    listaAlunos = aluno1;
    aluno2->proximo = listaAlunos;
    listaAlunos = aluno2;
    aluno3->proximo = listaAlunos;
    listaAlunos = aluno3;

    printf("Lista de Alunos:\n");
    printf("RA: %d, Nome: %s\n",current->RA_aluno,current->nome_aluno);


// no codigo abordei os principais topicos da estrutura, pode conter bugs mas em breve terá atualizações;
