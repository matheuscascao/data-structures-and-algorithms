#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    p = (int*)malloc(sizeof(int)*10);
    *(p + 5) = 10;
    *(p + 10) = 10;

    printf("%d", *(p+10));
    // printf("%ld", sizeof(p));
    // printf("%ld", sizeof(int)*10);

    return 0;
}