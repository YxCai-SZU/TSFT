#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (c >= a && c <= a + b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int state = 0;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);

    if (c < a)
    {
        state = -1;
    }

    if (c > a + b)
    {
        state = 1;
    }

    //@ assert (state == 0) ==> (c >= a && c <= a + b);
    //@ assert (state != 0) ==> !(c >= a && c <= a + b);

    return state == 0;
}
