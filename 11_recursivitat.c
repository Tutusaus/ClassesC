#include <stdio.h>
#include <stdlib.h>

/*int fact(int n){
    int res,i;
    for(i=1;i<=n;i++){
        res=res*i;
    }
    return res;
}*/

int fact(int n){
    int res;
    if (n>1){
        res=n*fact(n-1);
    }
    else{
        res=1;
    }
    return res;
}

int main(void){
    printf("%d\n", fact(4));

    return 0;
}