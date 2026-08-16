#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 && (n) <= 100 &&
        \valid((input_numbers) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (input_numbers)[i] >= 0 && (input_numbers)[i] <= 1000);
    ensures \result >= 0;
    ensures \forall integer i; 0 <= i < n ==> \result <= input_numbers[i];
*/
int func(size_t n, int *input_numbers)
{
    int min = 100000000;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant min >= 0;
        loop invariant \forall integer j; 0 <= j < i ==> min <= input_numbers[j];
        loop assigns i, min;
    */
    while (i < n)
    {
        int a = input_numbers[i];
        if (a < min)
        {
            min = a;
        }
        i++;
        //@ assert min >= 0;
    }
    return min;
}
