
/* Exemplo de manipula��o de Arquivo Texto

   Leitura e Escrita

   Usada fun��o fflush para efetivar as ultimas transa��es
   de leitura e escrita que estejam pendentes

   Usada fun��o rewind para voltar o ponteiro de leitura
   para o come�o do arquivo para listar todo o seu conte�do */

#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_CARACTERES 255

int main(){

    char  nomeArquivo[MAXIMO_CARACTERES], caracter;
    FILE* arquivo;

    printf("\n Entre com o nome do arquivo para abertura: ");
    fflush(stdin);

    gets(nomeArquivo);

    arquivo = fopen(nomeArquivo, "a+"); // Abre para leitura e escrita (posiciona o curso no in�cio)

    if (arquivo == NULL){
        printf("\n\a Erro na abertura do arquivo texto!\n");
        return -1;
    }

    printf("\n Gravando numeros...\n\n ");

    for (caracter = '0'; caracter <= '9'; caracter++){
        printf("%c ", caracter);
        fputc(caracter, arquivo); // Tamb�m pode ser usado putc
        fputc(' ', arquivo);      // Tamb�m pode ser usado putc
    }

    fflush(arquivo); // For�a terminar todas as opera��es pendentes

    rewind(arquivo); // Volta para o in�cio do arquivo

    printf("\n\n Lendo caracteres do arquivo...\n\n ");

    while((caracter = getc(arquivo)) != EOF){
        printf("%c", caracter);
    }

    fclose(arquivo);

    printf("\n\n Operacao realizada com sucesso!\n");

    return 0;
}
