#include <stdio.h>

int main(void) {
  FILE *pArquivo = NULL;
  pArquivo = fopen("alface.txt", "r");

  if (pArquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return 1; 
  }

  char destino[80];
  char pergunta;

  printf("Quer imprimir o nome de um personagem? P/F: ");
  scanf("%c", &pergunta);

  if ( pergunta == 'P') {

  fgets(destino, 80, pArquivo);
  printf("%s", destino);
  }

  if ( pergunta == 'F') {
    break;
  }

  else {
    printf("Resposta inválida!");
  }


  fclose(pArquivo);
  return 0; 
}