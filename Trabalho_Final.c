//Gustavo Rodrigues de Melo --> 11/02/2022
//Trabalho Final --> Estrutura de Dados 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int div_teto(float soma, int qtd)
{
	float quociente = soma/qtd;
	//Tratamento para evitar a realização de arredondamento em números com divisão exata, sem resto. ex: 120/3 = 40
	if (quociente * qtd == soma) {
		return soma/qtd;
	}
	
	//Funções importantes 
	int multiplo = 5;
	float valor_a_ser_arredondado = soma/qtd;
	int arredondado_baixo = ((int)valor_a_ser_arredondado / multiplo) * multiplo;
	int arredondado_cima = arredondado_baixo + multiplo;
	  
    return arredondado_cima;
}

int main() {
	int num, av, i, j;
	float **notas, soma;

	//Recebendo quantidade de alunos e de avaliações;
	printf("Quantidade de alunos: ");
   
	scanf("%d", &num);
   
	printf("Numero de avaliacoes: ");
   
	scanf("%d", &av);

	// Aloca o vetor
	notas = malloc(sizeof(float *) * (num + 1));

	for(i = 0; i <= num; i++) {
		notas[i] = malloc(sizeof(float) * (av + 1));
	}
  
   // Lê as notas
	for(i = 0; i < av; i++) {
		printf("Avaliacao [%d]:\n", i + 1);
		for(j = 0; j < num; j++) {
			printf("Informe a nota do aluno [%d]: ", j + 1);
			scanf("%f", &notas[j][i]);
		}
	}
	
	//Calcula a média de cada aluno nas três avaliações
	for(i = 0; i < num; i++) {
		soma = 0;
		for(j = 0; j < av; j++) {
			soma = soma + notas[i][j];
		}
		notas[i][av] = div_teto(soma, av);
	}
	
	float *desvioPadrao;
	desvioPadrao = malloc(sizeof(float) * av);
	
	//Calcula a média de cada avaliação
	for(j = 0; j < av; j++) {
		soma = 0;
		for(i = 0; i < num; i++) {
			soma = soma + notas[i][j];
		}
		//Aloca a média da avaliação x na posição adicional do vetor
		notas[num][j] = soma/(float)num;
    }
    
    float media_avaliacao;
    float modulo_distancia, quadrado_distancia;
    
    for(j = 0; j < av; j++) {
		soma = 0;
		media_avaliacao = notas[num][j];
		
		for(i = 0; i < num; i++) {
			modulo_distancia = fabs(notas[i][j] - media_avaliacao);
			quadrado_distancia = modulo_distancia * modulo_distancia;
			soma = soma + quadrado_distancia;
		}
		desvioPadrao[j] = sqrt(soma/num);
    }
	
	// Mostra a media
	printf("Resultado final\n");

	printf("Medias arredondadas para cima dos alunos:\n");
    for(i = 0; i < num; i++){
		printf("%d > %.0f\n", i + 1, notas[i][av]);
	}

	printf("Media e desvio padrao (populacional) das avaliacoes:\n");

    printf("       Media   Desvio\n");

    for(i = 0;i < av ; i++){
      printf("Av%d.   %.2f      %.2f\n", i + 1, notas[num][i], desvioPadrao[i]);
    }
    
    free(notas);
    free(desvioPadrao);
    
	return 0;
	 
}
