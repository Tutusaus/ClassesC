#include <stdio.h>
#include <math.h>

int es_primer(int num) {
    for(int i=2;i<num;i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("%d",es_primer(18));

    return 0;
}