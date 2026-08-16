#include <stdbool.h>

/*@
    requires ((3) == 3 &&
        \valid((v) + (0 .. 2)) &&
        (v)[0] >= 0 && (v)[0] <= 100 &&
        (v)[1] >= 0 && (v)[1] <= 100 &&
        (v)[2] >= 0 && (v)[2] <= 100);
    ensures \result == 1 <==> ((v)[0] <= (v)[2] && (v)[0] + (v)[1] >= (v)[2]);
    assigns \nothing;
*/
bool func(int *v)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert v[0] >= 0 && v[0] <= 100;
    result = (v[0] <= v[2] && v[0] + v[1] >= v[2]);
    
    //@ assert result == 1 <==> ((v)[0] <= (v)[2] && (v)[0] + (v)[1] >= (v)[2]);
    return result;
}
