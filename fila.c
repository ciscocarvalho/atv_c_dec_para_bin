#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

// Codigo baseado nos slides, nao assumo responsabilidade

#define MAX 20

struct fila {
  int ini, fim;
  int vet[MAX];
};

int vazia(Fila *f) { return (f->ini == f->fim); }

void liberar(Fila *f) { free(f); }

int incr(int i) {
  if (i == MAX - 1) {
    return 0;
  }

  return i + 1;
}

Fila *cria() {
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->ini = 0;
  f->fim = 0;
  return f;
}

void enqueue(Fila *f, int valor) {
  // verificar se está cheia
  if (incr(f->fim) == f->ini) {
    printf("Fila cheia");
    exit(1);
  }
  f->vet[f->fim] = valor;
  f->fim = incr(f->fim);
}

int dequeue(Fila *f) {
  int valor;
  if (vazia(f)) {
    printf("Fila vazia");
    exit(1);
  } else {
    valor = f->vet[f->ini];
    f->ini = incr(f->ini);
    return valor;
  }
}
