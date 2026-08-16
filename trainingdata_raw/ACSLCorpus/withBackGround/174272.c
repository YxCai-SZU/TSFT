#include <limits.h>

/*@
    predicate bounds(integer x, integer y, integer z) =
        x >= 0 && x <= 10000 &&
        y >= 0 && y <= 10000 &&
        z >= 0 && z <= 10000;

    logic integer compute(integer x, integer y, integer z) = (x + y) * (y + z);

    lemma multiplication_bound:
        \forall integer x, y, z;
            bounds(x, y, z) ==> compute(x, y, z) <= 20000 * 20000;
*/

/*@
    requires bounds(x, y, z);
    ensures \result == compute(x, y, z);
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    // Variable declarations at top of scope
    int result;

    //@ assert bounds(x, y, z);
    //@ assert compute(x, y, z) <= 20000 * 20000;
    
    result = (x + y) * (y + z);
    
    //@ assert result == compute(x, y, z);
    return result;
}

int main()
{
    return 0;
}
