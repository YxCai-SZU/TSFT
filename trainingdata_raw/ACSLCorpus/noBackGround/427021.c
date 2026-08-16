#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    ensures \result == 1 <==> ((v[0]) < (v[1]) && (v[1]) < (v[2]));
    assigns \nothing;
*/
bool func(int v[3])
{
    bool result;

    if (v[0] < v[1] && v[1] < v[2])
    {
        //@ assert v[0] < v[1];
        result = true;
    }
    else
    {
        //@ assert !(v[0] < v[1] && v[1] < v[2]);
        result = false;
    }

    return result;
}
