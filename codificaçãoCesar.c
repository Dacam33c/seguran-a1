#include <stdio.h>
#include <stdlib.h>

void main() {
    //essa primeira parte do codigo serve apenas para
    //pegar uma chave e texto que deve ser codificado
    char texto[201];
    int deslocamento;
    scanf("%d", &deslocamento);
    fflush(stdin);
    printf("texto max 200 caracteres \n");
    fgets(texto, sizeof(texto), stdin);

    printf("Texto cifrado \n");

    //o loop se repete usando i como contador que acessa cada caractere do texto e para quando o próximo elemento é o caractere nulo
    for (int i = 0; texto[i + 1] != '\0'; i++) {

        //na tabela ascii, as letras maiúsculas começam na posição 65, então aqui checamos se a letra em questão é maiúscula
        if (texto[i] >= 65 && texto[i] <= 90){
            //se a condição for verdadeira, subtraímos 65 para fazer com que o "A" fique na posição 0
            //e utilizamos o modulo 26 para que as letras deem um "loop" depois do "Z"
            //por fim adicionamos 65 para voltar ao valor correto da tabela ascii
            printf("%c",((texto[i] + deslocamento - 65) % 26) + 65);
        }

        //exatamente a mesma coisa porém para letras minúsculas
        else if(texto[i] >= 97 && texto[i] <= 122){
            printf("%c",((texto[i] + deslocamento - 97) % 26) + 97);
        }

        //se não for uma letra o caractere não é modificado
        else{
            printf("%c",texto[i]);
        }
    }
}
