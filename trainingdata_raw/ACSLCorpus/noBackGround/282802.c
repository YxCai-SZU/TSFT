#include <stdbool.h>
/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * 2 * 3);
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3;
    int result;
    //@ assert 1 <= r <= 100;
    //@ assert 1 <= r * 2 * 3 <= 100 * 2 * 3;
    result = r * 2 * pi;
    return result;
}
