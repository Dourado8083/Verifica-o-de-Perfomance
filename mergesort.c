#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>  //gettimeofday()

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);
int * randomArray(int *v ); //Gera um array de 8 numeros entre -100 e 100


int main (void) {

      printf("*************************************************************\n");
      printf("|           METODO DE SORTING: MERGE SORT                   |\n");
      printf("*************************************************************\n");
      printf("Entre com um valor desejado para o tamanho do vetor...");

      int sizeAux;

      scanf("%d", &sizeAux);
      #define TAM sizeAux //define a constante do tamanho do vetor....
      int v[TAM]; //Declara o vetor com o tamanho escolhido

      printf("Vetor gerado aleatoriamente (range -100 ate 100): \n ");
      for (int i = 0; i < TAM; i++){
        //Método rand gera um numero aleatorio entre 0 e 32767. Por dividir esse numero por 200 e pegando o resto, Podemos ter certeza que o numero nao ira passar de 200.
        //Em seguida, subtraimos 100 do numero em questao. Dessa forma, o numero pode ser negativo, variando entre -100 a 100.
        v[i] = (rand() % 200) - 100;
        printf("%d ", v[i]);
      }
      int i;

  //Utilizando sys/time.h, pega o tempo atual. Será utilizado para calcular o tempo levado para a organização.
  struct timeval start, end;
  gettimeofday(&start, NULL);

  //Executa o algoritmo no array declarado. Passa o tamanho do vetor para saber o numero de iterações.
  mergesort(v, TAM);

  gettimeofday(&end, NULL);
  printf("\nVetor organizado: (ordem crescente)\n");
  for (i = 0; i < TAM; i++) printf(" Vetor[%d]: %d \n",i, v[i]);


  long seconds = (end.tv_sec - start.tv_sec);
  long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
  printf("\nTempo total de execucao: %d segundos e %d microsegundos.", seconds, micros);

}

/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n); //Alocacao de espaco na memória em um vetor correspondente ao tamanho do vetor gerado acima...
  sort(v, c, 0, n - 1); //Passa o vetor, o inicio e o final para a organização...
  free(c); //Libera o espaço da memória alocada para a organização...
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenacao.
*/
void sort(int *v, int *c, int i, int f) {
  //Caso o valor do inicio do vetor seja maior ou igual que o fim, este ja foi organizado
  if (i >= f) return;

  //Encontra o meio do vetor
  int m = (i + f) / 2;
  printf("\nPosicao do meio do vetor: %d\n", m);

  //Divide novamente o vetor em dois e executa o método novamente...
  printf("Posicao Inicio: %d \t Fim: %d\n",i, f );
  printf("Dividindo o vetor...\n");
  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  // Se v[m] <= v[m + 1], então v[i..f] já está ordenado...
  if (v[m] <= v[m + 1]) return;

  //Método que junta os vetores em ordem crescente...
  merge(v, c, i, m, f);
}


/*
  Dado um vetor v e tres inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++){
        c[z] = v[z];
  }
  z = i;

  while (iv <= m && ic <= f) {
    //INVARIANTE: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente.
    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];
  while (ic <= f) v[z++] = c[ic++];
}
