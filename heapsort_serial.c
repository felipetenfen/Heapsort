#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define NUM_REP 100

void heap_sort(int *vet, int N);
void cria_heap(int *vetor, int i, int f);

int main()
{
   int *vetor, menu, tamanho_vetor, sair = 0, aleatorio = 0;
   double tempo_medio = 0.0;
   
   while (sair == 0)
   {
      printf("\n--------------------------------------\n");
      printf("\n ORDENACAO USANDO HEAPSORT SERIAL");
	  printf("\n 1-GERAR NOVO VETOR");
	  printf("\n 2-SAIR");
	  printf("\n >>>>>");
      printf("\n--------------------------------------\n");
      scanf("%d",&menu);
      system("cls");

      switch(menu)
	  {
		  case 1:
			printf("\nINSIRA O TAMANHO DO VETOR:\n");
            scanf("%d",&tamanho_vetor);
		  
            vetor = calloc(tamanho_vetor, sizeof(unsigned int));
			srand(time(NULL));

			for (int j = 0; j < NUM_REP; j++)
			{
				//Gera o vetor a ser ordenado (Aleatorio ou Inverso)
				if (aleatorio)
				{
				   for (int i  = 0; i < tamanho_vetor; i++)
				   {
					   vetor[i] = rand() % tamanho_vetor;
				   }
				}
				else
				{
				   for (int i = tamanho_vetor-1; i >= 0; i--)
				   {
					   vetor[i] = tamanho_vetor - i;
				   }
				}
				 
				//Inicia a contagem do tempo de execução
				clock_t tempo_uso = clock();

				//Realiza a chamada do algoritmo de ordenação sequencial				
				heap_sort(vetor, tamanho_vetor);

				//Obtem o tempo final, após o termino da ordenação do vetor
				tempo_uso = clock() - tempo_uso;
								
				//Realiza o calculo do tempo de execução do algoritmo em segundos
				double tempo_exec = ((double) tempo_uso) / CLOCKS_PER_SEC;
				printf("Heapsort serial executado em %g segundos\n", tempo_exec);

				//Realiza a soma do tempo de execução total do algoritmo
				tempo_medio += tempo_exec;
			}
			
			//Calcula o tempo médio de execução em relação ao número de repetições
			tempo_medio /= NUM_REP;

			printf("\nTamanho do Vetor = %d\n", tamanho_vetor);
			printf("\nTempo medio = %g segundos\n", tempo_medio);
                    
            system("pause");
            system("cls");
         break;
         
         case 2:
            printf("\nPrograma Finalizado!");
            sair=1;
            
         break;
            
      }
   }
}

void heap_sort(int *vet, int N)
{
	int i, aux;
	
	for ( i = (N -1)/2; i >= 0; i--)
	{
		cria_heap(vet, i, N-1);
	}
	
	for ( i = N-1; i >= 1; i--)
	{
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		
		cria_heap(vet, 0, i-1);
	}
}

void cria_heap(int *vet, int i, int f)
{
	int aux = vet[i];
	int j = i * 2 + 1;

	while (j <= f)
	{
		if (j < f)
		{
			if (vet[j] < vet[j+1])
			{
				j = j + 1;
			}
		}
		
		if ( aux < vet[j] )
		{
			vet[i] = vet[j];
			i = j;
			j = 2 * i + 1;
		}
		else
		{
			j = f + 1;
		}
	}

	vet[i] = aux;
}