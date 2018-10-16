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

void selectionSort(Quadrado **quadrados_entrada, int tamanho_entrada){
	int menor;
	for (unsigned int i = 0; i < tamanho_entrada; i += 1)
	{		
	menor = i;
		for (unsigned int j = i+1; j < tamanho_entrada; j += 1)
		{
			if (quadrados_entrada[j]->getArea()<quadrados_entrada[menor]->getArea()){					
				menor=j;
			}
		}
	Quadrado *aux = quadrados_entrada[i];
	quadrados_entrada[i] = quadrados_entrada[menor];
	quadrados_entrada[menor] = aux;	
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
	selectionSort(quadrados, tamanho);
	mostrarArray(quadrados, tamanho);
	return 1;
}



















