#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (((a) + (b)) % 2 != 0);
    ensures \result == 0 ==> (((a) + (b)) % 2 == 0);
*/
int func(unsigned int a, unsigned int b)
{
    unsigned int c;
    bool is_odd;

    c = a + b;
    is_odd = (c % 2) != 0;

    if (is_odd)
    {
        //@ assert (((a) + (b)) % 2 != 0);
        return 1;
    }
    else
    {
        //@ assert (((a) + (b)) % 2 == 0);
        return 0;
    }
}
