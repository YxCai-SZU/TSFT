#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer bc_mod(integer a, integer b, integer c) = (b * 10 + c) % 4;
    logic integer ab_mod(integer a, integer b, integer c) = (a * 10 + b) % 4;
    logic integer ac_mod(integer a, integer b, integer c) = (a * 10 + c) % 4;

    lemma mod_range:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            0 <= bc_mod(a,b,c) <= 3 &&
            0 <= ab_mod(a,b,c) <= 3 &&
            0 <= ac_mod(a,b,c) <= 3;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result == (bc_mod(a,b,c) < 1 || ab_mod(a,b,c) < 1 || ac_mod(a,b,c) < 1);
*/
bool func(long a, long b, long c)
{
    long bc;
    long ab;
    long ac;
    long bc_mod;
    long ab_mod;
    long ac_mod;
    bool result;

    bc = b * 10 + c;
    ab = a * 10 + b;
    ac = a * 10 + c;
    bc_mod = bc % 4;
    ab_mod = ab % 4;
    ac_mod = ac % 4;

    //@ assert bc_mod == bc_mod(a,b,c);
    //@ assert ab_mod == ab_mod(a,b,c);
    //@ assert ac_mod == ac_mod(a,b,c);

    if (bc_mod < 1 || ab_mod < 1 || ac_mod < 1)
    {
        result = true;
        //@ assert bc_mod < 1 || ab_mod < 1 || ac_mod < 1;
    }
    else
    {
        //@ assert bc_mod >= 1 && ab_mod >= 1 && ac_mod >= 1;
        result = false;
    }

    return result;
}
