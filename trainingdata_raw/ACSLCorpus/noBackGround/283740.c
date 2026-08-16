#include <stdbool.h>

/*@
    requires (\valid((v)) &&
        (v)[0] >= 1 && (v)[0] <= 13 &&
        (v)[1] >= 1 && (v)[1] <= 13 &&
        (v)[2] >= 1 && (v)[2] <= 13);
    ensures \result == 1 <==> ((v[1]) == (v[0]) || (v[2]) == (v[0]) || (v[2]) == (v[1]));
    assigns \nothing;
*/
bool func(int *v)
{
    //@ assert (\valid((v)) &&         (v)[0] >= 1 && (v)[0] <= 13 &&         (v)[1] >= 1 && (v)[1] <= 13 &&         (v)[2] >= 1 && (v)[2] <= 13);
    
    if (v[1] == v[0] || v[2] == v[0] || v[2] == v[1])
    {
        //@ assert ((v[1]) == (v[0]) || (v[2]) == (v[0]) || (v[2]) == (v[1]));
        return true;
    }
    else
    {
        //@ assert !((v[1]) == (v[0]) || (v[2]) == (v[0]) || (v[2]) == (v[1]));
        return false;
    }
}
