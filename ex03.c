#include <stdio.h>

int main(void) {
  FILE *pArquivo = NULL;
  char nomeDoLivro[80];
  int encerrar = 1;
  char personagens[80];

  printf("Digite o nome do livro: ");
  if (scanf("%79s", nomeDoLivro) != 1) {
    fprintf(stderr, "Erro ao ler o nome do livro.\n");
    return 1;
  }

  pArquivo = fopen(nomeDoLivro, "w");

  if (pArquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  while (encerrar == 1) {
    printf("Digite o nome dos personagens: ");
    if (scanf("%79s", personagens) != 1) {
      fprintf(stderr, "Erro ao ler o nome do personagem.\n");
      fclose(pArquivo);
      return 1;
    }
    fprintf(pArquivo, "%s\n", personagens);
    printf("Quer continuar digitando? 1/0 ");
    if (scanf("%d", &encerrar) != 1) {
      fprintf(stderr, "Erro ao ler a opção de continuar.\n");
      fclose(pArquivo);
      return 1;
    }
    
    while (getchar() != '\n');
  }

  fclose(pArquivo);

  char destino[80];
  char pergunta;

  printf("Quer imprimir o nome de um personagem? P/F: ");
  if (scanf(" %c", &pergunta) != 1) {
    fprintf(stderr, "Erro ao ler a opção de impressão.\n");
    return 1;
  }

  while (pergunta == 'P') {
    pArquivo = fopen(nomeDoLivro, "r");
    if (pArquivo == NULL) {
      perror("Erro ao abrir o arquivo para leitura");
      return 1;
    }

    printf("Nomes dos personagens:\n");
    while (fgets(destino, sizeof(destino), pArquivo) != NULL) {
      printf("%s", destino);
    }
    fclose(pArquivo);
   if (pergunta == 'F') {
    break;
  } else {
    printf("Resposta inválida!\n");
    printf("Quer imprimir o nome de um personagem? P/F: ");
    scanf(" %c", &pergunta);
  }
  }
  return 0;
}
