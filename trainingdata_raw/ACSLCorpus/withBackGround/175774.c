#include <limits.h>
#include <stdbool.h>

/*@
    predicate bounds(integer v) = 1 <= v <= 100;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer x, y;
            -100 <= x <= 100 && -100 <= y <= 100 ==> -10000 <= product(x, y) <= 10000;
*/

/*@
    requires bounds(a) && bounds(b) && bounds(c) && bounds(d);
    ensures \result == true <==> (product(a - c, a - d) <= 0) || (product(b - c, b - d) <= 0);
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    bool a_less_than = false;
    bool b_less_than = false;
    bool result = false;
    int ac = 0;
    int ad = 0;
    int bc = 0;
    int bd = 0;
    int prod_ac_ad = 0;
    int prod_bc_bd = 0;

    // Precondition assertions
    //@ assert bounds(a);
    //@ assert bounds(b);
    //@ assert bounds(c);
    //@ assert bounds(d);

    // Calculate differences
    ac = a - c;
    ad = a - d;
    bc = b - c;
    bd = b - d;

    // Bounds verification for differences
    //@ assert -100 <= ac <= 100;
    //@ assert -100 <= ad <= 100;
    //@ assert -100 <= bc <= 100;
    //@ assert -100 <= bd <= 100;

    // Calculate products
    prod_ac_ad = ac * ad;
    prod_bc_bd = bc * bd;

    // Product bounds verification
    //@ assert -10000 <= prod_ac_ad <= 10000;
    //@ assert -10000 <= prod_bc_bd <= 10000;

    // Conditional assignments
    if (a < c) {
        a_less_than = true;
    }

    if (b < d) {
        b_less_than = true;
    }

    // Final result calculation
    result = (prod_ac_ad <= 0) || (prod_bc_bd <= 0);

    // Postcondition verification
    //@ assert result == true <==> (product(a - c, a - d) <= 0) || (product(b - c, b - d) <= 0);

    return result;
}
