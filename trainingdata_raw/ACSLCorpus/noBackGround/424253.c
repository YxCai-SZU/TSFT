#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    requires ((a) <= (b)) && ((c) <= (d));
    ensures \result == (b < c || a <= d);
*/
bool func(long a, long b, long c, long d)
{
    // Variable declarations at scope top
    long a_local = a;
    long b_local = b;
    long c_local = c;
    long d_local = d;
    bool result;

    if (b_local < c_local || a_local <= d_local)
    {
        result = true;
        //@ assert result == (b_local < c_local || a_local <= d_local);
    }
    else
    {
        if (a_local == c_local && b_local == d_local)
        {
            //@ assert a_local == c_local && b_local == d_local;
            result = true;
        }
        else if (a_local == c_local && b_local < d_local)
        {
            //@ assert a_local == c_local && b_local < d_local;
            result = true;
        }
        else if (a_local < c_local && b_local == d_local)
        {
            //@ assert a_local < c_local && b_local == d_local;
            result = true;
        }
        else if (a_local < c_local && b_local < d_local)
        {
            //@ assert a_local < c_local && b_local < d_local;
            result = true;
        }
        else
        {
            //@ assert a_local != c_local && b_local != d_local;
            result = false;
        }
    }

    return result;
}
