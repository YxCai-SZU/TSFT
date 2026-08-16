#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((((a) * 3 + (b))) % 2) == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int tmp = a * 3 + b;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert tmp == ((a) * 3 + (b));
    //@ assert tmp >= 0;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant tmp >= 0;
        loop invariant tmp <= ((a) * 3 + (b));
        loop invariant ((tmp) % 2) == ((((a) * 3 + (b))) % 2);
        loop assigns tmp;
        loop variant tmp;
    */
    while (tmp >= 2)
    {
        tmp -= 2;
    }

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant tmp >= -1;
        loop invariant tmp < 2;
        loop invariant ((tmp) % 2) == ((((a) * 3 + (b))) % 2);
        loop assigns tmp;
        loop variant 1 + tmp;
    */
    while (tmp < 0)
    {
        tmp += 2;
    }

    //@ assert ((tmp) % 2) == ((((a) * 3 + (b))) % 2);
    return tmp == 0;
}
