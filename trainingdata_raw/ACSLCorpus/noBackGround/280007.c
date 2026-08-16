#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000 &&
        (d) <= (t) * (s));
    ensures \result == true;
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    long local_d;
    long local_t;
    long local_s;
    bool result;

    local_d = d;
    local_t = t;
    local_s = s;

    //@ assert 1 <= local_t <= 10000;
    //@ assert 1 <= local_s <= 10000;
    //@ assert local_t * local_s <= 100000000;

    //@ assert 1 <= local_d <= 10000;
    //@ assert 1 <= local_t <= 10000;
    //@ assert 1 <= local_s <= 10000;
    //@ assert local_d <= local_t * local_s;

    //@ assert local_t * local_s <= 100000000;

    if (local_d <= local_t * local_s)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true;
    return result;
}
