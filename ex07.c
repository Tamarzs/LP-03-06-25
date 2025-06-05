#include <stdio.h>

struct filme {
  char nome[20];
  int classIndicativa;
  double duracao;
};

int main(void) {
  struct filme retorno;

  FILE *pArquivo;
  pArquivo = fopen("filme.txt", "rb");

  fread(&retorno, sizeof(struct filme), 1, pArquivo);

  fclose(pArquivo);

  printf("Nome: %s\n", retorno.nome);
  printf("Duração: %.0f Minutos\n", retorno.duracao);
  printf("Classificação Indicativa: %d Anos\n", retorno.classIndicativa);

  return 0;
}  