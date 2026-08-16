#include <stdbool.h>

/*@
    requires 10 <= a <= 99;
    ensures \result == (a / 10 == 9 || a % 10 == 9);
*/
bool func(unsigned long a)
{
    unsigned long a_c;
    unsigned long div;
    unsigned long mod_res;
    bool result;

    a_c = a;
    div = 0;
    mod_res = 0;

    /*@
        loop invariant 10 <= a <= 99;
        loop invariant 0 <= a_c <= a;
        loop invariant div <= a / 10;
        loop invariant a_c == ((a) - 10 * (div));
        loop assigns a_c, div;
    */
    while (a_c >= 10)
    {
        //@ assert a_c >= 10;
        a_c = a_c - 10;
        div = div + 1;
    }

    mod_res = a_c;

    //@ assert mod_res == a % 10;
    //@ assert div == a / 10;

    if (div == 9 || mod_res == 9)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
