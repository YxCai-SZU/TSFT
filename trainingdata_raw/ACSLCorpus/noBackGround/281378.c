#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures (a * b % 2 == 0) ==> \result == 0;
    ensures (a * b % 2 != 0) ==> \result == 1;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations
    unsigned int c;
    bool is_even;
    unsigned int temp;

    // Precondition verification
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;

    // Ensure multiplication does not overflow
    //@ assert a * b <= 10000 * 10000;

    c = a * b;
    is_even = true;
    temp = c;

    /*@
        loop invariant 1 <= a <= 10000;
        loop invariant 1 <= b <= 10000;
        loop invariant temp <= a * b;
        loop invariant temp >= 0;
        loop invariant temp % 2 == c % 2;
        loop invariant c % 2 == a * b % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp != 0)
    {
        is_even = false;
    }

    //@ assert (is_even ==> c % 2 == 0) && (!is_even ==> c % 2 == 1);
    
    if (is_even)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
