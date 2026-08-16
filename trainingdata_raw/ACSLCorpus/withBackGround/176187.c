#include <stdbool.h>

/*@ predicate is_ordered(integer x, integer y, integer z) = x < y && y < z; */

/*@
    requires -100 <= x <= 100;
    requires -100 <= y <= 100;
    requires -100 <= z <= 100;
    ensures \result == (x < y && y < z);
    assigns \nothing;
*/
bool func(int x, int y, int z)
{
    //@ assert -100 <= x && x <= 100;
    //@ assert -100 <= y && y <= 100;
    //@ assert -100 <= z && z <= 100;
    return (x < y) && (y < z);
}

/*@
    requires -100 <= x <= 100;
    requires -100 <= y <= 100;
    requires -100 <= z <= 100;
    ensures \result == (x < y && y < z);
    assigns \nothing;
*/
bool func_complex(int x, int y, int z)
{
    //@ assert -100 <= x && x <= 100;
    //@ assert -100 <= y && y <= 100;
    //@ assert -100 <= z && z <= 100;
    return (x < y) && (y < z);
}
