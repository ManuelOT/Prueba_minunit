#include <stdio.h>
#include <stdlib.h>
#include "suma.h"
int main()
{
    int x,y;
    printf("Digite el valor de x y de y:  ");
    scanf("%d %d", &x ,&y);
    printf("El valor de la suma es: %d",suma(x,y));


}
