#include <stdio.h>

int main()
{
    int V[5] = {10, 5, 4, 16, 1};
    printf("\n&V\t%p", &V);
    printf("\nV\t%p\n\n", V);

    for (int i = 0; i < 5; i++)
    {
        printf("\n&V[%d]\t%p\tV[%d]\t%d", i, &V[i], i, V[i]);
        printf("\n(V+%d)\t%p\t*(V+%d)\t%d\n", i, (V+i), i, *(V+i));
    }

    return 0;
}
