#include <stdio.h>
#include <stdlib.h>
#define MAIORQ0(x) (((x) > (0)) ? (x) : (0))

int digits(unsigned long long int number);
void displayTable(int vDigits, int fDigits, unsigned long long int v, unsigned long long int f);
unsigned long long int fatorial(unsigned long long int n);

int main(){
    int n, vDigits=0, fDigits=0;
    printf("Quantidade de números: ");
    scanf("%d", &n);
    unsigned long long int v[n], i, f[n];

    // Read the numbers and add the value of digits
    for(i=0, vDigits=0, fDigits=0; i < n; i++){
        printf("Digite o %dº número: ", i+1);
        scanf("%llu", &v[i]);
        
        // Calls factorial function
        f[i] = fatorial(v[i]);

        // Calculate length of digits
        vDigits = vDigits > digits(v[i]) ? vDigits : digits(v[i]);
        fDigits = fDigits > digits(f[i]) ? fDigits : digits(f[i]);
        if(v[i] <= 20)
            displayTable(vDigits, fDigits, v[i], f[i]);
        else{
            printf("|--------------------------------------------------------------|\n| VALOR MAIOR QUE 20, NÃO SUPORTADO POR unsigned long long int |\n|--------------------------------------------------------------|\n");
        }
    }

    return 0;
}

int digits(unsigned long long int number){
    int count = 0;
    while(number != 0){
        count++;
        number /= 10;
    }
    return count;
}

void displayTable(int vDigits, int fDigits, unsigned long long int v, unsigned long long int f){
    int i;
    printf("|------------------");
    for(i=0; i < MAIORQ0((fDigits-8)); i++)
        printf("-");
    printf("-|\n| Número | Fatorial");
    for(i=0; i < MAIORQ0((fDigits-8)); i++)
        printf(" ");
    printf(" |\n| %d", v);
    for(i=0; i < MAIORQ0((7-vDigits)); i++)
        printf(" ");
    printf("| %llu", f);
    for(i=0; i < MAIORQ0((8-fDigits)); i++)
        printf(" ");
    printf(" |\n|------------------");
    for(i=0; i < MAIORQ0((fDigits-8)); i++)
        printf("-");
    printf("-|\n");
}

// Recursive factorial implementation
unsigned long long int fatorial(unsigned long long int n){
    if(n >= 1)
        return n*fatorial(n-1);
    else
        return 1;
}