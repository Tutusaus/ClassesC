#include <stdio.h>
#include <stdlib.h>

int main(){
    int age = 40;
    float dist = 43.7867546747562457415263673672357;
    double dist2 = 43.7867546747562457415263673672357;
    char grade = 'A'; //cal que les apòstrofs siguin així ' i no pas així ".
    char sentence[] = "Hola";

    printf("Age: %d\n",age); // &d és el que s'anomena un format specifier igual que %f entre d'altres.
    printf("Dist: %f\n",dist);
    printf("Dist2: %0.16lf\n",dist2);
    printf("Grade: %c\n",grade);
    printf("Sentence: %20.3s\n",sentence);
}