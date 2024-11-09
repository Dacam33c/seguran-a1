#include <stdio.h>
#include <stdlib.h>

void main() {
    //lendo um texto cifrado
    char texto[200];
    printf("texto max 200 caracteres \n");
    fgets(texto, sizeof(texto), stdin);
    char letra;

    //definimos uma lista com espaço para cada letra e inicializamos o valor em cada posição para 0
    int lista[26];
    for(int i = 0; i < 26;i++){
        lista[i] = 0;
    }

    int valido = 0;

    //iteramos por cada letra do texto cifrado até achar o caracter nulo
    for(int i = 0; texto[i + 1] != '\0'; i++){
        letra = texto[i];
        valido = 0;

        //checa se é uma letra. se for, coloca o "A" na posição 0 e define valido para 1
        if(letra >= 65 && letra <= 90){
            letra -= 65;
            valido = 1;
    }
        else if(letra >= 97 && letra <= 122){
            letra -= 97;
            valido = 1;
        }

        //se o caractere for valido, ou seja uma letra, incrementa o valor na posição daquele caractere na lista criada
        if(valido){
            lista[letra] = lista[letra] + 1;
        }
    }
    //agora a lista tem uma contagem de quantas vezes cada letra aparece no texto cifrado

    for(int i = 0;i < 26;i++){
        printf("\n %c %d \n", 65 + i, lista[i]);
    }


    int a = 0;
    int pos_a = 0;
    int e = 0;
    int pos_e = 0;

    //iteramos pela lista e checamos qual o maior valor nela, que indica qual letra mais se repete
    for(int i = 0; i < 26;i++){
        if(a < lista[i]){
            a = lista[i];
            pos_a = i;
        }
    }

    lista[pos_a] = 0;

    //repetimos para uma segunda letra
    for(int i = 0; i < 26;i++){
        if(e < lista[i]){
            e = lista[i];
            pos_e = i;
        }
    }

    //as duas letras mais comuns na lingua portuguesa são "A" e "E"
    //então vamos iterar pela lista e achar as duas letras que mais se repetem
    //poderia ser mais preciso checando mais letras, repetindo esse processo mais vezes


    printf("\n a: %d    e:%d",pos_a,pos_e);

    //como "a" normalmente estaria na posição 0 e "e" na 4, podemos supor qual foi o deslocamento
    int deslocamentoa = pos_a;
    int deslocamentoe = pos_e -4;

    //se as duas letras indicarem o mesmo valor, é provavel que a chave esteja correta
    if(deslocamentoa == deslocamentoe){
        printf("\n chave provavelmente = %d \n", deslocamentoa);
    }

    //repetimos o mesmo processo que foi usado para cifrar o texto, porém agora no sentido contrário para decodifica-lo
    for (int i = 0; texto[i + 1] != '\0'; i++) {
        if (texto[i] >= 65 && texto[i] <= 90){
            printf("%c",((texto[i] +26 - deslocamentoa - 65) % 26) + 65);
        }
        else if(texto[i] >= 97 && texto[i] <= 122){
            printf("%c",((texto[i] + 26 - deslocamentoa - 97) % 26) + 97);
        }
        else{
            printf("%c",texto[i]);
        }
    }

    //esse método fica mais preciso à medida que aumentamos o tamanho do texto.
    //palavras únicas frequentemente falham. Para deixar o algorítimo melhor poderiamos
    //adicionar a checagem com mais letras repetindo o mesmo processo já feito
}
