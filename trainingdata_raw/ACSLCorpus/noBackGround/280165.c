#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (b <= c || d <= c);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    bool result;

    //@ assert b <= c || d <= c ==> (b <= c || d <= c);
    result = b <= c || d <= c;
    return result;
}
