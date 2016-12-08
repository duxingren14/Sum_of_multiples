#include <stdio.h>

int getSumOfAllMultiplesBelow(int upper_bound, int factor){
    int max_times = (upper_bound-1)/factor;
    return (((max_times+1)*max_times)/2)*factor;
}

int max_public_factor(int n1, int n2){
    if(n1%n2==0) return n2;
    else return max_public_factor(n2, n1%n2);
}

int min_public_multiple(int n1, int n2){
    return n1 * n2/max_public_factor(n1,n2);
}

int getSumOfAllMultiplesBelow2(int upper_bound, int factor1, int factor2){
    return getSumOfAllMultiplesBelow(upper_bound,factor1)+
            getSumOfAllMultiplesBelow(upper_bound, factor2) -
            getSumOfAllMultiplesBelow(upper_bound, min_public_multiple(factor1, factor2));
}
int main()
{
    printf("%d\n",getSumOfAllMultiplesBelow2(1000,3,5));
    return 0;
}
