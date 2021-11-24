#include <time.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>  //gettimeofday()


//Métodos a serem utilizados na execução...:
// Função que troca a posição dos dois elementos....
  void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  //Função que encontra os maiores elementos nos nós esquerdo e direito arvore binaria
  void heapify(int v[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && v[left] > v[largest]){
      largest = left;
      //printf("\nNo esquerdo: v[%d] (%d) -- No pai: v[%d] (%d) ",left, v[left],i, v[i]);
    }
    if (right < n && v[right] > v[largest]){
      largest = right;

      //printf("\nNo direito:  v[%d] (%d) -- No pai: v[%d] (%d)", right, v[right],i, v[i]);
    }
    //Troca e continua a aplicar o método heapify se nao for o maior
    if (largest != i) {
      printf("\nTrocando v[%d] (%d) com v[%d] (%d)...",  largest, v[largest], i, v[i]);

      troca(&v[i], &v[largest]);
      heapify(v, n, largest);
    }
  }

  //Função principal que realiza o heap sort
  void heapSort(int v[], int n) {
    //Monta o heap (arvore binária)
    for (int i = n / 2 - 1; i >= 0; i--)

      heapify(v, n, i);

    //realiza a troca
    for (int i = n - 1; i >= 0; i--) {
       printf("\nTrocando v[%d](%d) com v[%d] (%d)", 0, v[0], i, v[i] );
       troca(&v[0], &v[i]);

      //Aplica o método heapify para pegar o maior elemento da raiz

      heapify(v, i, 0);
    }
  }

  int main() {
    printf("*************************************************************\n");
      printf("|           METODO DE SORTING: HEAP SORT                    |\n");
      printf("*************************************************************\n");
      printf("Entre com um valor desejado para o tamanho do vetor...");
      int sizeAux;
      scanf("%d", &sizeAux);
      #define TAM sizeAux
      int v[TAM];
      printf("Vetor gerado aleatoriamente (range -100 ate 100): \n ");
      for (int i = 0; i < TAM; i++){
        //Método rand gera um numero aleatorio entre 0 e 32767. Por dividir esse numero por 200 e pegando o resto, Podemos ter certeza que o numero nao ira passar de 200.
        //Em seguida, subtraimos 100 do numero em questao. Dessa forma, o numero pode ser negativo, variando entre -100 a 100.
        v[i] = (rand() % 200) - 100;
        printf("%d ", v[i]);
      }
      int i;


    struct timeval start, end;
    gettimeofday(&start, NULL);


    //Após gerar o vetor e contar o tempo, inicia o processo de organização
    printf("\nDividindo o vetor em uma arvore binaria...");
    heapSort(v, TAM);
    gettimeofday(&end, NULL);

    printf("\nVetor organizado (ordem crescente): ");
    for (i = 0; i < TAM; i++){
    printf("\n Vetor[%d]: %d", i, v[i]);
  }
  long seconds = (end.tv_sec - start.tv_sec);
  long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
  printf("\nTempo total de execucao: %d segundos e %d microsegundos.", seconds, micros);
}
