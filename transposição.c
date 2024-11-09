#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
    //lendo o texto que deve ser cifrado e uma chave númerica
    //cifras de transposição normalmente usam palavras como chave para modificar também a ordem das colunas a ser lidas
    //mas aqui estamos apenas definindo o número de coulas e codificando elas da esquerda para a direita

    char texto[201];
    int n_colunas;
    scanf("%d", &n_colunas);
    fflush(stdin);
    printf("texto max 200 caracteres \n");
    fgets(texto, sizeof(texto), stdin);


    //calculamos a quantidade de linhas que uma tabela deve ter para caber nosso texto
    //baseado no tamanho do texto e nº de colunas escolhido
    float n_linhas = ceil((float)strlen(texto)/n_colunas);
    char tabela[n_colunas][(int)n_linhas];

    //iteramos pela tabela, adicionando cada letra em ordem
    //ao mesmo tempo printa a tabela
    int current_char = 0;
    for(int l = 0; l < n_linhas;l++){
        for(int c = 0;c < n_colunas;c++){
            tabela[c][l] = texto[current_char];
            printf("%c",tabela[c][l]);
            current_char++;
        }
        printf("\n");
    }

    //iteramos pela tabela novamente, mudando apenas a ordem
    printf("texto cifrado:\n");
    for(int c = 0; c < n_colunas; c++){
        for(int l = 0;l < n_linhas;l++){
            if(tabela[c][l] != '\n'){
                printf("%c",tabela[c][l]);
            }
        }
    }

}
