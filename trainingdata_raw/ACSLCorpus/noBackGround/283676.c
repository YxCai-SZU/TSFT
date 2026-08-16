#include <stdbool.h>

/*@
    requires \valid_read(v + (0..3));
    requires 0 <= v[0] <= 23;
    requires 0 <= v[1] <= 59;
    requires 0 <= v[2] <= 23;
    requires 0 <= v[3] <= 59;
    ensures \result == (v[0]*60 + v[1] <= v[2]*60 + v[3]);
    assigns \nothing;
*/
bool func(const unsigned int v[4])
{
    unsigned int lhs;
    unsigned int rhs;
    bool result;

    lhs = v[0] * 60 + v[1];
    rhs = v[2] * 60 + v[3];

    //@ assert lhs == v[0] * 60 + v[1];
    //@ assert rhs == v[2] * 60 + v[3];
    
    //@ assert (0 <= (v[0]*60 + v[1]) <= 60*23 + 59);
    //@ assert (0 <= (v[2]*60 + v[3]) <= 60*23 + 59);
    
    result = lhs <= rhs;
    return result;
}
