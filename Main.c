/*Dato un file di dati al suo interno si trovano 3*/ 
/*valori che definiscono un triangolo, determinare*/ 
/*che sia un triangolo e trovare l'area massima e*/ 
/*minima di tutti i triangoli [esame 7/12/2021]*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define YEL "\e[0;33m"
#define RED "\e[0;31m"
#define BLU "\e[0;34m"
#define rst "\e[0m"

int main()
{
    float a, b, c, area,p, min=FLT_MIN, max=FLT_MAX;
    char file[FILENAME_MAX];
    FILE *fp;

    printf(RED "(dati.txt) " YEL"Inserire nome file: " rst);
    gets(file);

    if ( (fp = fopen(file, "r")) == NULL){
        fprintf(stderr, "il file '%s' non esiste\n", file);
        return EXIT_FAILURE;
     }

    /* è impoertante dichiare float in questo caso*/
    /* tutte le variabili in float, !=EOF per leggere tutto il file*/
    
    while ( fscanf(fp, "%f %f %f", &a, &b, &c ) != EOF){

        if (a < b+c || b < a+c || c < b+a){
            p = (a+b+c) / 2;
            area = sqrt(p * (p - a) * (p - b) * (p - c)); 
            /* per utiizzare sqrt si deve includere math.h */
           
            if (area > max)
                max = area;
            else if (area < min)
                min = area;
                /*per fare questo tipo di confronto*/
                /*inzializzare max=0 e min=FLT_MAX*/ 
                /*previa inclusione di float.h*/
        }
        printf(RED "Area MAX: '%.3f' \n " BLU "Area min: '%.3f'\n" rst , max,min);
    }


    return EXIT_SUCCESS;
}
/*https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a*/
