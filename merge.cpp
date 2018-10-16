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

void merge(Quadrado **quadrados_entrada, int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio-inicio + 1;
    int n2 = fim-meio; 
  
    Quadrado *quadradosEsquerda[n1], *quadradosDireita[n2]; 
    
    for (i = 0; i < n1; i++)
        quadradosEsquerda[i] = quadrados_entrada[inicio+i];
    for (j = 0; j < n2; j++)
        quadradosDireita[j] = quadrados_entrada[meio+1+j];
 
    
    i = 0;
    j = 0; 
    k = inicio;
    while (i < n1 && j < n2)
    {
        if (quadradosEsquerda[i]->getLado() <= quadradosDireita[j]->getLado())
        {
            quadrados_entrada[k] = quadradosEsquerda[i];
            i++;
        }
        else
        {
            quadrados_entrada[k] = quadradosDireita[j];
            j++;
        }
        k++;
    }
 
 
    while (i < n1)
    {
        quadrados_entrada[k] = quadradosEsquerda[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        quadrados_entrada[k] = quadradosDireita[j];
        j++;
        k++;
    }
}
 
void mergeSort(Quadrado **quadrados_entrada, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio+(fim-inicio)/2;
        mergeSort(quadrados_entrada, inicio, meio);
        mergeSort(quadrados_entrada, meio+1, fim); 
        merge(quadrados_entrada, inicio, meio, fim);
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
	mergeSort(quadrados, 0, 5);	
	mostrarArray(quadrados, tamanho);
	return 1;
}






















