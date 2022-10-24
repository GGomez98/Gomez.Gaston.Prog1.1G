#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
  int id;
  char nombre[20];
  char tipo;
  float efectividad;
}eVacuna;

float aplicarAumento(float precio);
void ordenarPorTipo(eVacuna arr[], int tam);

int main()
{
    float precioProducto = 100;
    printf("%.2f\n",precioProducto);
    precioProducto = aplicarAumento(precioProducto);
    printf("%.2f\n",precioProducto);

    eVacuna vacunas[4] = {{1,"uno",'c',15},{2,"dos",'a',20},{3,"tres",'a',30}};

    ordenarPorTipo(vacunas, 4);

    for(int i=0; i<4; i++){
        printf("%d %s %c %.2f\n", vacunas[i].id, vacunas[i].nombre, vacunas[i].tipo, vacunas[i].efectividad);
    }

    return 0;
}

float aplicarAumento(float precio)
{
    precio+= precio*5/100;

    return precio;
}

void ordenarPorTipo(eVacuna arr[], int tam)
{
    eVacuna aux;

    for(int i=0; i<tam-1; i++){
        for(int j=1; j<tam; j++){
            if(arr[i].tipo<arr[j].tipo){
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
            else if(arr[i].tipo==arr[j].tipo){
                if(arr[i].efectividad<arr[j].efectividad){
                    aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                }
            }
        }
    }
}
