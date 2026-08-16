#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == ( (a < c && b < c) || (a > c && b > c) );
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    bool ret;
    ret = false;

    //@ assert !ret;
    if (a < c && b < c)
    {
        ret = true;
        //@ assert a < c && b < c;
    }
    else if (a > c && b > c)
    {
        ret = true;
        //@ assert a > c && b > c;
    }

    //@ assert ret == ( (a < c && b < c) || (a > c && b > c) );
    return ret;
}
