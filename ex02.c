#include <stdio.h>

int main(void) {
  FILE *pArquivo = NULL;
  char nomeDoLivro[80];
  char personagens[80];
  int encerrar = 1;




  printf("Digite o nome do livro: ");
  scanf("%s", nomeDoLivro);

  pArquivo = fopen(nomeDoLivro, "w");

  if (pArquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  while ( encerrar == 1 ) {

  printf("Digite o nome dos personages: ");
  scanf("%s", personagens);
  fprintf(pArquivo, "%s\n", personagens);
  printf("Quer continuar digitando? 1/0 ");
  scanf("%d", &encerrar);

  }


  fclose(pArquivo);
  return 0; 
}