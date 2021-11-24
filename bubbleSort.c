//#include <stdio.h>
//#include <stdlib.h>

#include <sys/time.h>  //gettimeofday()

main()
{
  int x = 0,
      y = 0,
      aux = 0;
      printf("*************************************************************\n");
      printf("|           METODO DE SORTING: BUBBLE SORT                   |\n");
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
        printf("%d ", v[i]);//Mostra o vetor gerado ao usuário
      }

      struct timeval start, end;
      gettimeofday(&start, NULL);
      //Utilizando sys/time.h, pega o tempo atual. Será utilizado para calcular o tempo levado para a organização.

  // coloca em ordem crescente (1,2,3,4,5...)
  for( x = 0; x < TAM; x++ )
  {
    for( y = x + 1; y < TAM; y++ ) // sempre 1 elemento a frente
    {
      //se (x > (x+1)) entao o x passa pra frente (ordenação crescente)
      //repete isso para cada elemento do vetor
      if ( v[x] > v[y] )
      {
         printf("\nValor na posicao %d e maior que da sua posicao vizinha! Movendo-o para frente...", x);
         aux = v[x];
         v[x] = v[y];
         v[y] = aux;
      }
    }
  }
  //Recebe o tempo em que o algoritmo organizou o vetor
  gettimeofday(&end, NULL);

  //Mostra o vetor ordenado ao usuário
  printf("\nVETOR ORGANIZADO...:");
  for( x = 0; x < TAM; x++ )
  {
    printf("\nVetor[%d] = %d ",x,v[x]); // exibe o vetor ordenado
  }

  //Transformando o tempo de execução em segundos e microsegundos para mostrar ao usuário.
  long seconds = (end.tv_sec - start.tv_sec);
  long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

  printf("\nTempo total de execucao: %d segundos e %d microsegundos.", seconds, micros);

}
