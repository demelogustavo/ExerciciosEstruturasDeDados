//Gustavo Rodrigues de Melo - EP1 Estrutura de Dados - 11/11/2021
#include <stdio.h>
#include<math.h>

int main(){
int a, i=0,j=0 ,tamanho=0;
float maior=0,op=0,mediana=0,menor=0,soma=0,dp=0;

printf("Quantos números na sua série (N): ");
scanf("%d",&tamanho);

float n[tamanho];

//achar maior e menor
printf("\n");
for (a=0;a<tamanho;a++){
printf("Escreva o %d º Número: ", a+1);
scanf("%f", &n[a]);
if(a==0){maior=n[a];menor=n[a];}
if(n[a]>maior){
maior=n[a];
}
else{
if(n[a]<menor){
menor=n[a];
}
}
soma=soma+n[a];
}
//mediana
for(i=0;i<tamanho-1;i++){
for(j=i+1;j<tamanho;j++){
  
if(n[i] > n[j]){
  
op= n[i];
n[i] = n[j];
n[j] = op;
}
}
}

if(tamanho%2){
mediana = n[tamanho/2];
} else {
mediana = (n[tamanho/2-1]+n[tamanho/2])/2;
}
for (a=0;a<tamanho;a++){
dp+=(n[a]-(soma/tamanho))*(n[a]-(soma/tamanho));
}

printf("\nValor mínimo: %2.1f\n", menor);
printf("\nValor Máximo: %2.1f\n", maior);
printf("\nMédia: %2.1f\n",soma/tamanho);
printf("\nMediana: %2.1f \n", mediana);
printf("\nDesvio padrão: %f \n",sqrt(dp/(tamanho-1)));

return 0;
}
