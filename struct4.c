#include <stdio.h>
#include <stdlib.h>
 
typedef struct Movie_info{ 
    char *name; 
    char *ACC; 
} InfoPeli;
 
int main(){
    InfoPeli *M;    //M és una adreca que punta a una estructura InfoPeli
    M = (InfoPeli *)malloc(sizeof(InfoPeli));   //Assignem la memòria corresponent per a l'apuntador M

    printf("Mida de l'estructura InfoPeli: %d\n",sizeof(InfoPeli)); //sizeof(char)+sizeof(char)=8+8=16
    printf("Adreca que s'emmagatzema a M: %x\n",M);  //Valor de M (apunta a la primera posició de memòria assignada)
    printf("Mida de M: %d\n",sizeof(M));  //8 perquè tot apuntador té mida 8
    printf("Adreca de M: %x\n",&M); //M a part d'emmagatzemar una adreça com a valor, també té una adreça en memòria com a apuntador que és
    
    M->name = "Python with JournalDev";
    M->ACC="A";

    printf("Movie Information:");
    printf("\nName: %s", M->name);
    printf("\nACC: %s", M->ACC);
    return 0;
}