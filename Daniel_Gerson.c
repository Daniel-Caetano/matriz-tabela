
/* Goiania, 30 de novembro de 2021

   Matriz Dados Usuarios

   Devs: Daniel Caetano
         Gerson Otavio
*/

// bibliotecas
#include "Daniel_Gerson.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// variavel para a matriz preenchida
char matrizPreenchida[10][5][30] = {
    {"Daniel", "Rua dois", "74723-190", "Agua Branca", "61982352337"},
    {"Gerson", "Rua tres", "74710-138", "Riviera", "61982854562"},
    {"Ana", "Rua quatro", "74753-100", "Novo Mundo", "61982158564"},
    {"Vitor", "Rua cinco", "74763-136", "Agua Branca", "61982557482"},
    {"Tulio", "Rua seis", "74728-149", "Guanabara", "61992549685"},
    {"Alan de Marcos", "Rua dois", "74793-154", "Bairro Feliz", "61982457543"},
    {"Paulo", "Rua sete", "74711-186", "Sonho Verde", "61982651045"},
    {"Lucas", "Rua oito", "74712-115", "Aguas Claras", "61992559137"},
    {"Willian", "Rua nove", "74734-116", "Bueno", "61982533761"},
    {"Gustavo", "Rua 11", "75644-116", "Leste Vila Nova", "61992559564"}};

// variavel para preenchimento da matriz
char matrizPreencher[10][5][30];

// variavel que verifica se encontrou a busca na matriz
int preenchida = 1;

// variavel do menu escolhido pelo usuario
int indice = 99;

// funcao para o preenchimento da matriz
void preencher_matriz() {

  preenchida = 0;

  printf("\nPreencha os dados das tabelas");
  for (int i = 0; i < 10; i++) {

    printf("\n|Linha:|%i|", (i + 1));
    printf("\n________________________________________\n");
    printf("\n|   Nome             |=");
    scanf(" %[^\n]", matrizPreencher[i][0]);
    printf("\n----------------------------------------");
    printf("\n|   Endereco         |=");
    scanf(" %[^\n]", matrizPreencher[i][1]);
    printf("\n----------------------------------------");
    printf("\n|   Codigo Postal    |=");
    scanf(" %[^\n]", matrizPreencher[i][2]);
    printf("\n----------------------------------------");
    printf("\n|   Bairro           |=");
    scanf(" %[^\n]", matrizPreencher[i][3]);
    printf("\n----------------------------------------");
    printf("\n|   Telefone         |=");
    scanf(" %[^\n]", matrizPreencher[i][4]);
    printf("\n----------------------------------------");
  }
  imprimirMatriz();
}

// funcao para buscar o que o usuario deseja
void busca() {
  // variavel que indentica a quantidade de vezes que entra na condicao
  int segunda = 0;
  // variavel com espaco de 30 caracteres
  char chave[30];
  int encontrou = 0;
  int igual = 0;

  if (!segunda) {
    segunda = 1;

    printf("Digite um telefone para busca!\n");
    // foi usado " %[^\n]" para que o programa considerasse o espaco digitado
    // pelo usuario
    scanf(" %[^\n]", &chave);
    // usado para limpar o buffer do teclado
    fflush(stdin);
  } else {

    printf("Digite uma chave qualquer para buscar!\n");
    // foi usado " %[^\n]" para que o programa considerasse o espaco digitado
    // pelo usuario
    scanf(" %[^\n]", &chave);
    // usado para limpar o buffer do teclado
    fflush(stdin);
  }

  if (preenchida) {
    printf("\n_________________________________________________________________"
           "____________________________________________\n");
    printf("|        Nome        ||      Endereco      ||    Codigo Postal   "
           "||        Bairro      ||      Telefone      |\n");
    printf("-------------------------------------------------------------------"
           "-------------------------------------------\n");
    // loop contado para percorrer a matriz
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 5; j++) {
        if (igual) {
          igual = 0;
          printf("\n");
        }
        // compara a string chave com a matrizpreenchida, se for igual entra no
        // for
        if (strcmp(&chave, matrizPreenchida[i][j]) == 0) {
          for (int k = 0; k < 5; k++) {
            printf("|%20s|", matrizPreenchida[i][k]);
          }
          encontrou = 1;
          igual = 1;
        }
      }
    }
    printf("\n-----------------------------------------------------------------"
           "---------------------------------------------\n");

    if (!encontrou) {
      printf("\nNao encontrou\n");
    }
    printf("\n");

  } else if (!preenchida) {

    printf("\n_________________________________________________________________"
           "____________________________________________\n");
    printf("|        Nome        ||      Endereco      ||    Codigo Postal   "
           "||        Bairro      ||      Telefone      |\n");
    printf("-------------------------------------------------------------------"
           "-------------------------------------------\n");
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 5; j++) {
        if (igual) {
          printf("\n");
          igual = 0;
        }
        // compara a string chave com a matrizpreenchida, se for igual entra no
        // for
        if (strcmp(&chave, matrizPreencher[i][j]) == 0) {
          for (int k = 0; k < 5; k++) {
            printf("|%20s|", matrizPreencher[i][k]);
          }
          igual = 1;
          encontrou = 1;
        }
      }
    }
    printf("\n-----------------------------------------------------------------"
           "---------------------------------------------\n");

    if (!encontrou) {
      printf("\nNao encontrou\n");
    }
    printf("\n");
  }
}
void imprimirMatriz() {
  // system("cls || Clear");

  printf(
      "\n____________________________________________________________________"
      "_____________________________________________\n");
  printf("|           Nome         ||      Endereco      ||    Codigo Postal   "
         "||  "
         "      Bairro      ||      Telefone      |\n");
  printf(
      "----------------------------------------------------------------------"
      "--------------------------------------------\n");
  if (preenchida) {
    for (int i = 0; i < 10; i++) {

      printf("|%2d|", i + 1);

      for (int j = 0; j < 5; j++) {
        printf("|%20s|", matrizPreenchida[i][j]);
      }
      printf("\n");
    }

  } else if (!preenchida) {
    for (int i = 0; i < 10; i++) {

      printf("|%2d|", i + 1);
      for (int j = 0; j < 5; j++) {
        printf("|%20s|", matrizPreencher[i][j]);
      }
      printf("\n");
    }
  }

  printf("---------------------------------------------------------------------"
         "---------------------------------------------\n");
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

  printf("Digite o novo dado!!\n");
  if (preenchida) {
    scanf(" %[^\n]", matrizPreenchida[i - 1][cond - 1]);

  } else if (!preenchida) {
    scanf(" %[^\n]", matrizPreencher[i - 1][cond - 1]);
  }
  imprimirMatriz();
}
int main() {

  do {

    printf("Digite a opcao: ");
    printf("\n___________________________________________\n");
    printf("|-----------------------------------------|\n");
    printf("|[1] Para carregar uma matriz preenchida! |\n");
    printf("|[2] Para preencher uma nova matriz!      |\n");
    printf("|[3] Para buscar!                         |\n");
    printf("|[4] Para atualizar!                      |\n");
    printf("|[5] Para sair!                           |\n");
    printf("|-----------------------------------------|\n");
    scanf(" %d", &indice);

    switch (indice) {
    case 1:
      preenchida = 1;
      imprimirMatriz();
      break;

    case 2:
      preenchida = 0;
      preencher_matriz();
      break;
    case 3:
      busca();
      break;

    case 4:
      atualiza();
      break;
    case 5:
      indice = 0;
      break;
    default:
      printf("Opcao invalida, digite novamente!\n");
      break;
    }

  } while (indice);
  system("cls || clear");
  printf("\n\nObrigado por utilizar nosso sistema!!\n");
  system("pause");
}
