#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int d_abs;
    int t_abs;
    int s_abs;
    bool result;

    // Declare all variables at the top
    d_abs = (d < 0) ? -d : d;
    t_abs = (t < 0) ? -t : t;
    s_abs = (s < 0) ? -s : s;

    //@ assert 1 <= t_abs <= 10000;
    //@ assert 1 <= s_abs <= 10000;
    //@ assert t_abs * s_abs <= 10000 * 10000;
    //@ assert t_abs * s_abs >= 0;

    result = (t_abs * s_abs >= d_abs);
    return result;
}
