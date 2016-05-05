#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Punto 1 programa para escribir dos archivos de forma pendeja segun omar
//Recibir por teclado solo letras y guardarlas en un archivo A
//Recibir por teclado solo numeros y gurdarlos en un archivo B
//Crear un archivo C con 3 letras del File A y 2 numeros del File B

int main(){
    //variable de ingreso
    FILE *A, *B;
    char texto[100]; // DOnde puedo usar MALLOC para eso haaaaa
    char numeros[20];
    
    printf("++++++Programa Punto 1++++++\n");
    printf("\nIngresa letras por favor: ");
    scanf("%[A-z]", texto); 

    while(getchar()!=10){}//para liberar el buffer de entrada

    printf("\ningresa a ahora solo numeros: ");
    scanf ("%[0-9]", numeros);
    while(getchar()!=10){}//para liberar el buffer de entrada
    


    getchar();
    int x=0;
    
    int limpiar=0;
    for(x;x<100;x++){
        if(limpiar==1){
            texto[x]=' ';
        }
        if(texto[x]=='\0'){
            limpiar=1;
        }                
    }
    limpiar=0;
    x=0;
    for(x;x<20;x++){
        if(limpiar==1){
            numeros[x]=' ';
        }
        if(numeros[x]=='\0'){
            limpiar=1;
        }                
    }
    
    //Ahora escribir en cada fichero correspondiente
    //Escribiendo el Fichero A
    A = fopen("ficheroA.txt", "w");
//    fwrite( texto, sizeof(char), sizeof(texto), A );
    fputs( texto, A );
    fclose(A);
    //***********************************
    //Escribiendo el Fichero B
    B = fopen("ficheroB.txt", "w");
    fputs(numeros,B);
    fclose(B);
    //*********************************************
    char leidoA[3];
    char leidoB[2];
    printf("\nAhora se comenzara a escribir el fichero C");
    
    printf("\nLeyendo...");
    
    A = NULL;
    A = fopen("ficheroA.txt", "r");
    if(A==NULL){
        perror("Error al abrir el archivo");
        
    }else{
        if(fgets(leidoA,4,A)!=NULL){
            printf("\nEsto se leyo del A: %s", leidoA);
        }
    }
    fclose(A);
    
    B=NULL;
    B = fopen("ficheroB.txt", "r");
    if(A==NULL){
        perror("Error al abrir el archivo");
        
    }else{
        if(fgets(leidoB,3,B)!=NULL){
            
        }
    }
    fclose(B);
    
    FILE * C;
    char salidaC[5];
    
    for(x=0;x<5;x++){
        if(x<3){
        salidaC[x]=leidoA[x];
        }
        if(x>=3){
            salidaC[x]=leidoB[x-3];
        }
    }
    
    
    C = fopen("FicheroC", "w");
    fputs(salidaC,C);
    fclose(C);
    
    
    

    return 0;

}
