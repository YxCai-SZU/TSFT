#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        (v)[0] >= -100 && (v)[1] <= 100 && (v)[2] >= 0 &&
        (v)[0] <= (v)[1]);
    ensures \result == (v[2] <= v[1] - v[0]);
    assigns \nothing;
*/
bool func(int *v)
{
    // Variable declarations at top
    bool result;
    int diff_val;

    //@ assert v[1] - v[0] >= -100;
    //@ assert v[1] - v[0] <= 200;

    diff_val = v[1] - v[0];

    if (v[2] <= diff_val)
    {
        //@ assert v[2] <= v[1] - v[0];
        result = true;
    }
    else
    {
        //@ assert !(v[2] <= v[1] - v[0]);
        result = false;
    }

    return result;
}
