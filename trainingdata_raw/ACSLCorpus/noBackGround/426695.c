#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == ( (a == b && c == a) || (a != b && b != c && c != a) );
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int state = 0;

    //@ assert 0 <= state <= 3;

    if (a == b)
    {
        state = 1;
    }

    //@ assert 0 <= state <= 3;

    if (b == c)
    {
        state = state + 1;
    }

    //@ assert 0 <= state <= 3;

    if (a == c)
    {
        state = state + 1;
    }

    //@ assert state == 0 || state == 1 || state == 2 || state == 3;

    return state == 3 || state == 0;
}
