#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(numbers + (0 .. 4));
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 1 <= (numbers)[i] && (numbers)[i] <= 5 &&
        \exists integer i; 0 <= i < (5) && (numbers)[i] == 0);
    ensures 1 <= \result && \result <= 5;
    ensures \exists integer i; 0 <= i < 5 && numbers[i] == 0 ==> \result == (integer)(i + 1);
*/
unsigned int func(const int *numbers)
{
    unsigned int i = 1;
    //@ assert 1 <= i && i <= 5;
    
    /*@
        loop invariant 1 <= i && i <= 6;
        loop invariant \forall integer k; 0 <= k < (integer)i - 1 ==> numbers[k] != 0;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i <= 5)
    {
        //@ assert 1 <= i && i <= 5;
        if (numbers[i - 1] == 0)
        {
            //@ assert numbers[i - 1] == 0;
            return i;
        }
        //@ assert numbers[i - 1] != 0;
        i = i + 1;
    }
    //@ assert i == 6;
    return 0;
}
