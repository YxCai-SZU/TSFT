#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == ((a * b) % 2 == 1);
*/
bool func(int a, int b)
{
    int product;
    int rem;

    product = a * b;
    rem = product;

    /*@
        loop invariant 1 <= a <= 3;
        loop invariant 1 <= b <= 3;
        loop invariant rem >= 0;
        loop invariant rem <= product;
        loop invariant rem % 2 == product % 2;
        loop assigns rem;
    */
    while (rem >= 2)
    {
        rem -= 2;
    }

    /*@
        loop invariant 1 <= a <= 3;
        loop invariant 1 <= b <= 3;
        loop invariant rem >= -1;
        loop invariant rem < 2;
        loop invariant rem % 2 == product % 2;
        loop assigns rem;
    */
    while (rem < 0)
    {
        rem += 2;
    }

    //@ assert rem == product % 2;
    return rem == 1;
}
