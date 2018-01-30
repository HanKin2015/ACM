#include <stdio.h>
#include <time.h>

int main(void)
{
    clock_t t = clock();
    int i = 1;
    double sum = 0;
    for( ; ; ) {
        sum += 1.0 / i;
        //printf("%ld\n",i++);
        i++;
        if(sum >=115.0 )	break;
    }
    printf("\n\n%d\n", clock() - t);
    return 0;
}

