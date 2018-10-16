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



void mostrarArray (Quadrado **quadrados_entrada, int tamanho_entrada){
	for (unsigned int i = 0; i < tamanho_entrada; i ++)
	{
		printf("Quadrado %d \n", i+1);
		quadrados_entrada[i]->mostrarQuadrado();
		printf("\n");
	}
}

void quickSort(Quadrado **quadrados_entrada, int inicio, int fim)
{
	int i, j, pivo;
	Quadrado *quadrado_auxiliar;
    if (inicio < fim)
    {
        pivo = fim;   
		i = (inicio - 1);
		for (j = inicio; j <= fim-1; j++)
		{
		    if (quadrados_entrada[j]->getLado() <= quadrados_entrada[pivo]->getLado())
		    {
		        i++;
		        quadrado_auxiliar = quadrados_entrada[i];
		        quadrados_entrada[i] = quadrados_entrada[j];
		        quadrados_entrada[j] = quadrado_auxiliar;
		    }
		}
		quadrado_auxiliar = quadrados_entrada[i+1];
		quadrados_entrada[i+1] = quadrados_entrada[fim];
		quadrados_entrada[fim] = quadrado_auxiliar; 
		pivo = i+1;

        quickSort(quadrados_entrada, inicio, pivo - 1);
        quickSort(quadrados_entrada, pivo + 1, fim); 
    }
    
    
		
}

int main (){
	srand (time(NULL));		
	Quadrado *quadrados[6];
	int tamanho = 6;
	for (unsigned int i = 0; i < tamanho; i += 1)
	{
		double lado;
		printf("Digite o lado do %do quadrado:\n", i+1);
		scanf("%lf", &lado);
		quadrados[i] = new Quadrado(i, lado);
	}
	mostrarArray(quadrados, tamanho);
	printf("-------------------------\n\n");
	quickSort(quadrados, 0, 5);	
	mostrarArray(quadrados, tamanho);
	return 1;
}






















