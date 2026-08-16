#include <stdbool.h>

/*@
    requires ((length) >= 2 && (length) <= 200000 &&
        \valid((numbers) + (0 .. (length)-1)) &&
        \forall integer i; 0 <= i < (length) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000000000);
    ensures \result >= 0;
    ensures \exists integer j; 0 <= j < length && \result == numbers[j];
*/
int func(int *numbers, int length)
{
    int min;
    int i;
    
    min = numbers[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= length;
        loop invariant \forall integer k; 0 <= k < i ==> min <= numbers[k];
        loop invariant \exists integer k; 0 <= k < i && min == numbers[k];
        loop assigns min, i;
    */
    while (i < length)
    {
        int value;
        value = numbers[i];
        if (value < min)
        {
            min = value;
        }
        i = i + 1;
    }
    return min;
}
