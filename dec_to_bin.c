#include "fila.c"
#include <stdio.h>
#include <stdlib.h>

int decimal_para_binario(int n) {
  int resultado = 0;
  int resto;
  int qtd_algarismos = 0;
  int *algarismos = (int *)malloc(qtd_algarismos);
  int tamanho_int = sizeof(int);
  Fila *f = cria();

  while (1) {
    resto = n % 2;
    n = n / 2;

    enqueue(f, resto);

    if (n < 2) {
      enqueue(f, n);
      break;
    }
  }

  while (vazia(f) == 0) {
    algarismos = (int *)realloc(algarismos, tamanho_int * ++qtd_algarismos);
    algarismos[qtd_algarismos - 1] = dequeue(f);
  }

  for (int i = qtd_algarismos - 1; i >= 0; i--) {
    resultado = resultado * 10 + algarismos[i];
  }

  liberar(f);
  free(algarismos);

  return resultado;
}

// Teste simples
int main() {
  int n = 14;

  printf("Número em decimal: %d\n", n);
  printf("O número em binário é: %d\n", decimal_para_binario(n));

  return 0;
}
