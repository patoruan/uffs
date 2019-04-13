#include <stdio.h>
#include <stdlib.h>
#define MAIORQ0(x) (((x) > (0)) ? (x) : (0))

typedef struct tp_Aluno{
    int matricula;
    double notaFinal;
}Aluno;

int digits(int number);
char conceito(double nota);

int main(){
    Aluno alunos[75];
    int i, bigDigit=0, j;
    for(i=0; i<75; i++){
        printf("Digite a matricula do aluno: ");
        scanf("%d", &alunos[i].matricula);
        bigDigit = digits(alunos[i].matricula);
        printf("Digite a nota do aluno: ");
        scanf("%lf", &alunos[i].notaFinal);
    }

    // Display
    printf("|----------------------");
    for(j=0; j<MAIORQ0(bigDigit-11); j++)
        printf("-");
    printf("|\n| MATRICULA | CONCEITO |\n");
    printf("|----------------------");
    for(j=0; j<MAIORQ0(bigDigit-11); j++)
        printf("-");
    printf("|\n");
    for(i=0; i<75; i++){
        printf("| %d", alunos[i].matricula);
        for(j=0; j<MAIORQ0(9-bigDigit); j++)
            printf(" ");
        printf(" | %c        |\n", conceito(alunos[i].notaFinal));
        printf("|----------------------");
        for(j=0; j<MAIORQ0(bigDigit-11); j++)
            printf("-");
        printf("|\n");
    }

    return 0;
}

int digits(int number){
    int count = 0;
    while(number != 0){
        count++;
        number /= 10;
    }
    return count;
}

char conceito(double nota){
    if(nota>=0.0 && nota<5)
        return 'D';
    if(nota>=5.0 && nota<=6.9)
        return 'C';
    if(nota>=7.0 && nota<=8.9)
        return 'B';
    if(nota>=9.0 && nota<=10)
        return 'A';
}