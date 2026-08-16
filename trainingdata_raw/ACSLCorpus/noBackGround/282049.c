#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(input + (0 .. 4));
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 1 <= (input)[i] && (input)[i] <= 5);
    requires (\exists integer i; 0 <= i < (5) && (input)[i] == 0);
    ensures 1 <= \result && \result <= 5;
    ensures input[\result - 1] == 0;
    ensures \forall integer i; 0 <= i < 5 && i != \result - 1 ==> input[i] != 0;
*/
int func(int *input)
{
    int i = 0;

    /*@
        loop invariant 0 <= i <= 5;
        loop invariant ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 1 <= (input)[i] && (input)[i] <= 5);
        loop invariant (\exists integer i; 0 <= i < (5) && (input)[i] == 0);
        loop invariant (\forall integer j; 0 <= j < (i) ==> (input)[j] != 0);
        loop invariant i < 5;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        //@ assert 0 <= i < 5;
        if (input[i] == 0)
        {
            //@ assert input[i] == 0;
            //@ assert \forall integer j; 0 <= j < i ==> input[j] != 0;
            return i + 1;
        }
        //@ assert input[i] != 0;
        i += 1;
    }
    return -1;
}
