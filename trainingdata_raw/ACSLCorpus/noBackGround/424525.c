#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == true <==> a * b <= c * d;
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    //@ assert (1 <= (((a)) * ((b))) <= 10000);
    //@ assert (1 <= (((c)) * ((d))) <= 10000);
    return a * b <= c * d;
}
