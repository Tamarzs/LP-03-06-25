#include <stdio.h>

int main () {
    FILE *pArquivo = NULL;
    pArquivo = fopen("remedios.txt", "w");

   if (pArquivo == NULL) {
     perror("Erro ao abrir o arquivo");
     return 1;
  }

    char data[100];
    char horario[100];

    printf("Qual data você quer salvar?: ");
    scanf("%s", data);
    fprintf(pArquivo, "Data: %s", data);

    printf("Qual horário você quer salvar?: ");
    scanf("%s", horario);
    fprintf(pArquivo, " Hora: %s", horario);

    printf("Marcador salvo! (Data: %s Hora: %s\n)", data, horario);

    fclose(pArquivo);
    return 0;
}