#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char *matriz[10][5];
char matrizPreencher[10][5][30];
char condicao = 0;
int segunda = 0;
int indice = 1;

void copiaMatriz(char *matrizA[10][5]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      matriz[i][j] = matrizA[i][j];
    }
  }
}
void copiaString(char *chave[30]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      matriz[i][j] = *chave;
    }
  }
}
void preencher_matriz() {

  printf("\nDeseja carregar uma matriz pronta ou digitar uma ?(S)sim ou (N) "
         "nao.\n");
  scanf(" %c", &condicao);
  if ((condicao == 's') || (condicao == 'S')) {
    char *matrizA[10][5] = {
        {"Daniel", "Rua dois", "74723-190", "Agua Branca", "61982352337"},
        {"Gerson", "Rua tres", "74710-138", "Riviera", "61982854562"},
        {"Ana", "Rua quatro", "74753-100", "Novo Mundo", "61982158564"},
        {"Vitor", "Rua cinco", "74763-136", "Setor Universitario",
         "61982557482"},
        {"Tulio", "Rua seis", "74728-149", "Guanabara", "61992549685"},
        {"Alan de Marcos", "Rua dois", "74793-154", "Maysa", "61982457543"},
        {"Paulo", "Rua sete", "74711-186", "Sonho Verde", "61982651045"},
        {"Lucas", "Rua oito", "74712-115", "Aguas Claras", "61992559137"},
        {"Willian", "Rua nove", "74734-116", "Bueno", "61982533761"},
        {"Gustavo", "Rua 11", "75644-116", "Leste Vila Nova", "61992559564"}};
    copiaMatriz(matrizA);
  }

  else if ((condicao == 'n') || (condicao == 'N')) {
    // char matrizA[10][5][30];

    printf("\nPreencha os dados das tabelas");
    for (int i = 0; i < 2; i++) {

      printf("\n|Linha:|%i|", i + 1);
      printf("\n________________________________________\n");
      printf("\n|   Nome             =");
      scanf(" %s", matrizPreencher[i][0]);
      printf("\n|   Endereco         =");
      scanf(" %s", matrizPreencher[i][1]);
      printf("\n|   Codigo Postal    =");
      scanf(" %s", matrizPreencher[i][2]);
      printf("\n|   Bairro           =");
      scanf(" %s", matrizPreencher[i][3]);
      printf("\n|   Telefone         =");
      scanf(" %s", matrizPreencher[i][4]);
      printf("------------------------------------------");
    }
  }
}
void busca() {
  char chave[30];

  if (!segunda) {
    segunda = 1;
    /*int opcao = 0;
    printf("Digite a opcao: ");
    printf("\n___________________________________________\n");
    printf("|-----------------------------------------|\n");
    printf("|[1] Para buscar!                         |\n");
    printf("|[2] Para atualizar!                      |\n");
    printf("|-----------------------------------------|\n");
    scanf("%d", &opcao);*/
    printf("Digite um telefone para busca!\n");
    scanf(" %s", &chave);
    fflush(stdin);
  } else {

    printf("Digite uma chave qualquer para buscar!\n");
    scanf(" %s", &chave);
    fflush(stdin);
    // indice = 0;
  }

  int cond = 0;

  if ((condicao == 's') || (condicao == 'S')) {
    printf("\n_________________________________________________________________"
           "____________________________________________\n");
    printf("|        Nome        ||      Endereco      ||    Codigo Postal   "
           "||        Bairro      ||      Telefone      |\n");
    printf("-------------------------------------------------------------------"
           "-------------------------------------------\n");
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 5; j++) {
        if (strcmp(&chave, matriz[i][j]) == 0) {
          for (int k = 0; k < 5; k++) {
            printf("|%20s|", matriz[i][k]);
          }
          cond = 1;
        }
      }
    }
    printf("\n-----------------------------------------------------------------"
           "---------------------------------------------\n");

    if (!cond) {
      printf("\nNao encontrou\n");
    }
    printf("\n");

  } else if ((condicao == 'n') || (condicao == 'N')) {

    printf("\n_________________________________________________________________"
           "____________________________________________\n");
    printf("|        Nome        ||      Endereco      ||    Codigo Postal   "
           "||        Bairro      ||      Telefone      |\n");
    printf("-------------------------------------------------------------------"
           "-------------------------------------------\n");
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 5; j++) {
        if (strcmp(&chave, matrizPreencher[i][j]) == 0) {
          for (int k = 0; k < 5; k++) {
            printf("|%20s|", matrizPreencher[i][k]);
          }
          cond = 1;
        }
      }
    }
    printf("\n-----------------------------------------------------------------"
           "---------------------------------------------\n");

    if (!cond) {
      printf("\nNao encontrou\n");
    }
    printf("\n");
  }
}
void imprimirMatriz() {
  system("cls || Clear");

  printf("\n___________________________________________________________________"
         "__________________________________________\n");
  printf("|        Nome        ||      Endereco      ||    Codigo Postal   ||  "
         "      Bairro      ||      Telefone      |\n");
  printf("---------------------------------------------------------------------"
         "-----------------------------------------\n");
  if ((condicao == 's') || (condicao == 'S')) {
    for (int i = 0; i < 10; i++) {
      // printf("|%c|", matriz[i]);
      for (int j = 0; j < 5; j++) {
        printf("|%d||%20s|", i, matriz[i][j]);
      }
      printf("\n");
    }

  } else if ((condicao == 'n') || (condicao == 'N')) {
    for (int i = 0; i < 10; i++) {

      printf("|%2d|", i + 1);

      // printf("|%c|", matriz[i]);
      for (int j = 0; j < 5; j++) {
        printf("|%20s|", matrizPreencher[i][j]);
      }
      printf("\n");
    }
  }

  printf("---------------------------------------------------------------------"
         "-----------------------------------------\n");
}
void atualiza() {
  int cond;
  int i;
  imprimirMatriz();
  printf("Qual linha deseja atualizar?\n");
  scanf(" %d", &i);

  printf("\nQual informacao deseja atualizar?\n");
  printf("\n___________________________________________\n");
  printf("|-----------------------------------------|\n");
  printf("|[1] Para atualizar o nome!               |\n");
  printf("|[2] Para atualizar o endereco!           |\n");
  printf("|[3] Para atualizar o codigo postal!      |\n");
  printf("|[4] Para atualizar o bairro!             |\n");
  printf("|[5] Para atualizar o telefone!           |\n");
  printf("|-----------------------------------------|\n");
  scanf(" %d", &cond);

  printf("Digite o novo dado\n");
  switch (cond) {
  case 1:
    scanf(" %s", matrizPreencher[i - 1][0]);
    printf("%s", matrizPreencher[i - 1][0]);
    break;
  case 2:
    scanf(" %s", matrizPreencher[i - 1][1]);
    printf("%s", matrizPreencher[i - 1][1]);
    break;
  case 3:
    scanf(" %s", matrizPreencher[i - 1][2]);
    printf("%s", matrizPreencher[i - 1][2]);
    break;
  case 4:
    scanf(" %s", matrizPreencher[i - 1][3]);
    printf("%s", matrizPreencher[i - 1][3]);
    break;
  case 5:
    scanf(" %s", matrizPreencher[i - 1][4]);
    printf("%s", matrizPreencher[i - 1][4]);
    break;
  }
  /*printf("\nMatriz nova");
  for (int j = 0; j < 10; j++) {
    for (int k = 0; k < 5; k++) {
      printf("|%s|", matrizPreencher[j][k]);
    }
    printf("\n");
  }*/
  imprimirMatriz();
}
int main() {
  char chave[30];
  char condDois;

  int cond = 0;

  preencher_matriz();
  imprimirMatriz();
  // busca();
  do {
    int opcao = 0;
    printf("Digite a opcao: ");
    printf("\n___________________________________________\n");
    printf("|-----------------------------------------|\n");
    printf("|[1] Para buscar!                         |\n");
    printf("|[2] Para atualizar!                      |\n");
    printf("|-----------------------------------------|\n");
    scanf(" %d", &opcao);

    switch (opcao) {

    case 1:
      busca();
      break;

    case 2:
      atualiza();
      break;
    }
    /*
    printf("\nDeseja atualizar a tabela?\n");
    scanf(" %c", &condDois);
    if ((condDois == 's') || (condDois == 'S')) {
      atualiza();
    } else {
      busca();
    }*/

  } while (indice);
  system("cls || clear");
  printf("\n\nObrigado por utilizar nosso sistema!!\n");
  system("pause");
}
