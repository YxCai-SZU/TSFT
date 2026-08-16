#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    ensures \result <==> (500 * k >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= k && k <= 100;
    //@ assert 1 <= x && x <= 100000;
    //@ assert 500 * k >= x <==> 500 * k >= x;

    result = (500 * k >= x);
    return result;
}
