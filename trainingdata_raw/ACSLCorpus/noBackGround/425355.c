#include <stdbool.h>
#include <stddef.h>

/*@
    requires (\valid((input) + (0 .. 4)) &&
        (\forall integer i; 0 <= i < 5 ==> 0 <= (input)[i] && (input)[i] <= 5) &&
        (\exists integer i; 0 <= i < 5 && (input)[i] == 0));
    ensures 1 <= \result && \result <= 5;
    ensures input[\result - 1] == 0;
    assigns \nothing;
*/
int func(int *input)
{
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\valid((input) + (0 .. 4)) &&
        (\forall integer i; 0 <= i < 5 ==> 0 <= (input)[i] && (input)[i] <= 5) &&
        (\exists integer i; 0 <= i < 5 && (input)[i] == 0));
        loop invariant (\forall integer k; 0 <= k < (i) ==> (input)[k] != 0);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        //@ assert 0 <= i < 5;
        if (input[i] == 0)
        {
            //@ assert input[i] == 0;
            return (int)(i + 1);
        }
        //@ assert input[i] != 0;
        i++;
    }
    return -1;
}
