#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 20 && 1 <= (b) && (b) <= 20);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (a * b) % 2 == 0;
    ensures \result == 0 ==> (a * b) % 2 != 0;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int x;
    bool is_even;
    unsigned int temp;

    //@ assert (1 <= (a) && (a) <= 20 && 1 <= (b) && (b) <= 20);
    //@ assert a * b <= 400;

    x = a * b;
    is_even = false;
    temp = x;

    /*@
        loop invariant 1 <= a && a <= 20;
        loop invariant 1 <= b && b <= 20;
        loop invariant 0 <= temp;
        loop invariant temp <= a * b;
        loop invariant temp % 2 == x % 2;
        loop invariant x == a * b;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 0)
    {
        is_even = true;
    }

    if (is_even)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
