#include <stdio.h>

int main()
{
    int edad;
    int* p1;

    edad = 12;
    printf("Edad = %d\n", edad);

    p1 = &edad;
    printf("p1 = %p\n", p1);

    printf("Leyendo el contenido de lo apuntado %d\n", *p1);

    *p1 = 15;
    printf("Edad ahora vale: %d", edad);

    printf("Otra cosa: %d", *p1);

    return 0;
}