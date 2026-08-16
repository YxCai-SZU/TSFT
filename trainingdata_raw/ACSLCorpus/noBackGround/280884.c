#include <stdbool.h>

/*@
    requires \valid(v);
    requires (\valid((v)) &&
        \forall integer i; 0 <= i < 3 ==> 1 <= (v)[i] && (v)[i] <= 9);
    ensures \result == (((v)[1] - (v)[0]) == ((v)[2] - (v)[1]));
    assigns \nothing;
*/
bool func(int *v)
{
    // Declare all variables at the top
    bool result;
    int diff_10;
    int diff_21;

    //@ assert v[1] - v[0] >= -8 && v[1] - v[0] <= 8;
    diff_10 = v[1] - v[0];
    
    //@ assert v[2] - v[1] >= -8 && v[2] - v[1] <= 8;
    diff_21 = v[2] - v[1];
    
    result = (diff_10 == diff_21);
    return result;
}
