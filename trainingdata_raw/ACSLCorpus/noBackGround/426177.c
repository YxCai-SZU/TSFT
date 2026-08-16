#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int result;

    //@ assert a >= b;
    //@ assert a - b >= 0;
    //@ assert c + (a - b) >= c;

    if (c + (a - b) > 0)
    {
        result = a;
    }
    else
    {
        result = b - (b - c);
    }

    return result;
}
