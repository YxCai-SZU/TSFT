#include <stdbool.h>

/*@
    requires (0 <= (a) <= 10 && 0 <= (b) <= 10 && 0 <= (c) <= 10 && 0 <= (d) <= 10);
    ensures \result == (a * b <= c * d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    //@ assert (0 <= (a) <= 10 && 0 <= (b) <= 10 && 0 <= (c) <= 10 && 0 <= (d) <= 10);
    //@ assert 0 <= a * b <= 100;
    //@ assert 0 <= c * d <= 100;
    return a * b <= c * d;
}
