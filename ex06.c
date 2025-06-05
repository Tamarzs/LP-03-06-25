#include <stdio.h>

struct filme {
  char nome[20];
  int classIndicativa;
  double duracao;
};

int main(void) {
  struct filme retorno;

  printf("Digite o nome do filme: ");
  scanf("%s", retorno.nome);

  printf("Digite a classificação indicativa: ");
  scanf("%d", &retorno.classIndicativa);

  printf("Digite a duração do filme: ");
  scanf("%lf", &retorno.duracao);

  FILE *pArquivo;
  pArquivo = fopen("filme.txt", "wb");

   fwrite(&retorno, sizeof(struct filme), 1, pArquivo);

  fclose(pArquivo);
  return 0;
}  