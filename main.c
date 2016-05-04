#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Punto 1 programa para escribir dos archivos de forma pendeja segun omar

int main(){
    //variable de ingreso
    FILE *A, *B;
    char **texto; // DOnde puedo usar MALLOC para eso haaaaa
    char numeros[20];
    int largo=0;

    printf("++++++Programa Punto 1++++++\n");
    printf("\nIngresa letras por favor: ");
    largo = scanf("%[A-z]", texto); // aqui esto si hace lo que debe o no???


    while(getchar()!=10){}//para liberar el buffer de entrada
    printf("\nEl largo es: %i", largo);

    printf("\ningresa a ahora solo numeros: ");
    scanf ("%[0-9]", numeros);
    while(getchar()!=10){}//para liberar el buffer de entrada
    printf("\nMucho mejor ahora: mostrando texto: %s", texto);
    printf("\nMostrando numero %s", numeros);


    getchar();
    //Ahora escribir en cada fichero correspondiente
    //Escribiendo el Fichero A
    A = fopen("ficheroA.txt", "w");
    fwrite( texto, sizeof(char), sizeof(texto), A );
    fclose(A);
    //***********************************
    //Escribiendo el Fichero B
    B = fopen("ficheroB.txt", "w");
    fputs(numeros,B);
    fclose(B);

    return 0;

}
