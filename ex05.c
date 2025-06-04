#include <stdio.h>

int main () {
    FILE *pArquivo = NULL;
    pArquivo = fopen("remedios.txt", "r");

   if (pArquivo == NULL) {
     perror("Erro ao abrir o arquivo");
     return 1;
  }

  char ultima[100];

  while (fgets(ultima, sizeof(ultima), pArquivo) != NULL) {
    
  };
  fclose(pArquivo);

  printf("Última: %s\n", ultima);
  return 0;
}