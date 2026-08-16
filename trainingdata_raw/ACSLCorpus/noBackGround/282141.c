#include <stdbool.h>

/*@
    requires 1 <= N <= 10000;
    requires 0 <= A <= 1000;
    ensures \result == (N % 500 <= A);
    assigns \nothing;
*/
bool func(unsigned int N, unsigned int A)
{
    unsigned int r;

    r = N % 500;

    if (r > A)
    {
        //@ assert r > A;
        return false;
    }
    else
    {
        //@ assert r <= A;
        return true;
    }
}
