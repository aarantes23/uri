// Desenvolvido por Arthur Arantes Faria
// arthurarantes23@hotmail.com
#include <bits/stdc++.h>
#define M 50

using namespace std;

/*
	Em resumo, o nucleo consiste em um algoritmo de busca em profundidade.
*/

/*

Premissas, Espcificacoes iniciais,
1 - Para qualquer número de saída T, ele terá sempre que: 0 < T < 2000;
2 - Para qualquer número de entrada I, ele terá sempre que: 0 < I < 200;
3 - Haverá sempre pelo menos dois números iniciais e sete no máximo;
4 - Todos os numeros envovolvidos sao inteiros;
5 - Adicao, multiplicacao, subtracao, divisao;
6 - Cada numero pode ser utilizado no maximo uma vez;
7 - Nao ha nenhuma obrigacao em usar todos os numeros iniciais.

*/

/* 
Parametros da funcao dfs, Deep First Search.	
   d = Inicio do vetor atual
   Array = Lista de numeros
   Size = Quantidade de numeros
   T = Numero de destino			 
   Depth = profundidade vetor atual
   Output = Resultado de saida
*/
inline bool dfs(int d, int *arr, int size, int T, int depth, char output[][M])
{
	
	// Percorre todo o vetor tentanto encontrar um numero igual ao numero de destino
	for (int i = 0; i < size; i++)
	{
		// Se encontrar, retorna verdadeiro e sai da funcao.
		if (arr[i] == T)
		{
			return true;
		}
	}
	 
	// Se o inicio for maior que o fim, entao nao encontrou o resultado, retorna false e desfaz a ultima recusividade.
	if (d >= depth)
	{
		return false;
	}
	
	/*	
	  Operacaoes por ordem de ordem de prioridade, 
	  Adição - Multiplicação - Subtração - Divisão
	*/
	
	// Adição	
	int len = 0, tmp[10] = {0};
	
	// Percorre ate o tamanho total
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			len = 1; // Igonora a primeira posicao, porque nela, a posicao 0 (Zero), sera a soma dos valores dois valores iniciais do vetor.
			for (int k = 0; k < size; k++)
			{
				if (k!=i && k!=j)
				{
					// Move todo o vetor uma posicao para tras
					tmp[len++] = arr[k];
				}
			}
			
			// Soma os 2 primeiros elementos.
			tmp[0] = arr[i] + arr[j];
			
			// verifica se obteve o resultado tendo esse novo valor no vetor, para isso passa agora o vetor como parametro
			if (dfs(d+1, tmp, len, T, depth, output))
			{
				// resultado de saida igual ao do exemplo
				int MAX = max(arr[i], arr[j]), MIN = min(arr[i], arr[j]);
				sprintf(output[d], "%d + %d = %d", MAX, MIN, arr[i]+arr[j]);
				return true;
			}
		}
	}
	
	// Multiplicação

	// Analogo ao metodo da adicao.
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			len = 1;		
			for (int k = 0; k < size; k++)
			{		
				if (k!=i && k!=j)
				{
		
					tmp[len++] = arr[k];
				}		
			}
			
			// Multiplica os 2 primeiros elementos.
			tmp[0] = arr[i] * arr[j];
			
			if (dfs(d+1, tmp, len, T, depth, output))
			{
				int MAX = max(arr[i], arr[j]), MIN = min(arr[i], arr[j]);
				sprintf(output[d], "%d x %d = %d", MAX, MIN, arr[i]*arr[j]);
				return true;
			}
		}
	}
	
	// Subtração

	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{			
			int MAX = max(arr[i], arr[j]), MIN = min(arr[i], arr[j]);
			
			// verificacao da igualdade da variavel MAX e a MIN 
			if (MAX == MIN)
			{
				continue;	
			}
			
			len = 1;
			
			for (int k = 0; k < size; k++)
			{
				if (k!=i && k!=j)
				{
					tmp[len++] = arr[k];
				}
			}
			
			// Subtrai os 2 primeiros elementos.
			tmp[0] = MAX - MIN;
			
			if (dfs(d+1, tmp, len, T, depth, output))
			{
				sprintf(output[d], "%d - %d = %d", MAX, MIN, MAX-MIN);
				return true;
			}
		}
	}
	
	// Divisão

	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			int MAX = max(arr[i], arr[j]), MIN = min(arr[i], arr[j]);
			
			// se o resto da divisao de MAX por MIN for diferente de 0
			if (MAX % MIN != 0)
			{			
				continue;
			}
			
			len = 1;
			
			for (int k = 0; k < size; k++)
			{
				if (k!=i && k!=j)
				{
					tmp[len++] = arr[k];
				}
			}
			
			
			tmp[0] = MAX / MIN;
			if (dfs(d+1, tmp, len, T, depth, output))
			{
				sprintf(output[d], "%d / %d = %d", MAX, MIN, MAX/MIN);
				return true;
			}
		}
	}

	
	return false;
}

int main()
{
	// Definicoes iniciais 
	// T = Numero de destino
	// N = Quantidade de numeros iniciais
	// arr = Vetor de tamanho 10
	int T, N, arr[10];
	// output = Resultados de saida
	char output[10][M];
	
	// Leitura do numero de destino
	// Enquanto nao houver um Zero ele le novamente
	while(scanf("%d", &T)==1, T)
	{		
	
		// Quantidade de numeros iniciais
		scanf("%d", &N);
		
		// Numeros iniciais
		for (int i = 0; i < N; i++)
		{
			scanf("%d", arr+i);
		}
		
		// Alocacao de memoria
		memset(output, '\0', sizeof(output[0][0])*10*M);

		int depth = 1;		
		for (int depth = 1; depth <= N; depth++)
		{
			
			if (depth == N)
			{
				puts("No solution");
				break;
			}
			
			/*
			Parametros
			 0 = Inicio do vetor atual
			 Array = Numeros iniciais
			 N = Quantidade de numeros iniciais
			 T = Numero de destino			 
			 Depth = profundidade do vetor atual
			 Output = Saida
			*/
			if (dfs(0, arr, N, T, depth, output))
			{
				
				for (int i = 0; i < depth-1; i++)
				{
					// Imprime na tela uma string especificada, incluindo uma nova linha ('\n') ao final da impressao.
					puts(output[i]);
				}
				//Para cada caso de teste a ultima linha deve produzir este print
				printf("%s <-\n", output[depth-1]);
				break;
			}
		}
	}
	
	return 0;
}
