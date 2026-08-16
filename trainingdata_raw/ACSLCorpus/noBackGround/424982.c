#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int result;

    //@ assert (1 <= (r) && (r) <= 100);
    result = r;
    //@ assert result == r;
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert r * r <= 10000;
    result *= r;
    //@ assert result == r * r;
    return result;
}
