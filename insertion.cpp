#include <stdio.h>
#include <time.h>
#include <stdlib.h>


class Quadrado {
private:
	int id;
	double area, lado;
	
	void calcularArea(){
		area = lado*lado;
	}

public:
	Quadrado(int id_entrada, double lado_entrada){
		id = id_entrada;
		lado = lado_entrada;
		calcularArea();	
	}	
	
	Quadrado(){
		
	}
	
	~Quadrado(){
	}

	void setLado(double lado_entrada){
		lado = lado_entrada;
		calcularArea();
	}

	double getLado(){
		return lado;
	}

	double getArea(){
		return area;
	}
	
	void mostrarQuadrado(){
		for (int i = 0; i < lado; i += 1)
		{
			for (int j = 0; j < lado; j += 1)
			{
				if(i==0 or i==lado-1){
					printf("* ");				
				}
				else if(j==0 or j==lado-1){
					printf("* ");				
				}
				else{
					printf("  ");				
				}

			}
			printf("\n");
		}
	}
	
	
}; 

void insertionSort(Quadrado **quadrados_entrada, int tamanho_entrada){	
   int i, j;
   Quadrado *quadrado_teste;
   for (i = 1; i < tamanho_entrada; i++)
   {
       quadrado_teste = quadrados_entrada[i];
       j = i-1;
       while (j >= 0 && quadrados_entrada[j]->getLado() > quadrado_teste->getLado())
       {
           quadrados_entrada[j+1] = quadrados_entrada[j];
           j = j-1;
       }
       quadrados_entrada[j+1] = quadrado_teste;
   }
}

void mostrarArray (Quadrado **quadrados_entrada, int tamanho_entrada){
	for (unsigned int i = 0; i < tamanho_entrada; i += 1)
	{
		printf("Quadrado %d \n", i+1);
		quadrados_entrada[i]->mostrarQuadrado();
		printf("\n");
	}
}

int main (){
	srand (time(NULL));		
	Quadrado *quadrados[5];
	int tamanho = 5;
	for (unsigned int i = 0; i < tamanho; i += 1)
	{
		double lado;
		printf("Digite o lado do %do quadrado:\n", i+1);
		scanf("%lf", &lado);
		quadrados[i] = new Quadrado(i, lado);
	}
	mostrarArray(quadrados, tamanho);
	printf("-------------------------\n\n");
	insertionSort(quadrados, tamanho);
	mostrarArray(quadrados, tamanho);
	return 1;
}



















