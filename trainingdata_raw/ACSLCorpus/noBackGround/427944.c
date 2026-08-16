#include <stdbool.h>
/*@
    requires ((2) == 2 &&
        \valid((v) + (0 .. 1)) &&
        (v)[0] >= 1 && (v)[0] <= 16 &&
        (v)[1] >= 1 && (v)[1] <= 16 &&
        (v)[0] + (v)[1] <= 16);
    ensures \result == true <==> (v[0] <= 8 && v[1] <= 8);
    assigns \nothing;
*/
bool func(int *v)
{
    bool result;

    //@ assert ((2) == 2 &&         \valid((v) + (0 .. 1)) &&         (v)[0] >= 1 && (v)[0] <= 16 &&         (v)[1] >= 1 && (v)[1] <= 16 &&         (v)[0] + (v)[1] <= 16);
    //@ assert ((v)[(0)]) >= 1 && ((v)[(0)]) <= 16;
    //@ assert ((v)[(1)]) >= 1 && ((v)[(1)]) <= 16;
    //@ assert ((v)[(0)]) + ((v)[(1)]) <= 16;

    if (v[0] <= 8 && v[1] <= 8)
    {
        //@ assert ((((v))[(0)]) <= 8 && (((v))[(1)]) <= 8);
        result = true;
    }
    else
    {
        //@ assert !((((v))[(0)]) <= 8 && (((v))[(1)]) <= 8);
        result = false;
    }

    //@ assert result == true <==> (v[0] <= 8 && v[1] <= 8);
    return result;
}
