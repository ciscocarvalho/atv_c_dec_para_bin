typedef struct fila Fila;

int vazia(Fila *f);
void liberar(Fila *f);
Fila *cria();
void enqueue(Fila *f, int valor);
int dequeue(Fila *f);
