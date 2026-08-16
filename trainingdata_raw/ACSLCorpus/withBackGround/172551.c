#include <limits.h>

/*@
    predicate bounds(integer x, integer y, integer z) =
        x <= 8 && y <= 8 && z <= 8;

    lemma mod_less_than_divisor:
        \forall integer x, integer y; y > 0 ==> x % y < y;

    lemma mul_distributive_add:
        \forall integer x, integer y, integer z;
            bounds(x, y, z) ==> x * (y + z) == x * y + x * z;
*/

/*@
    requires y > 0;
    ensures \result < y;
    assigns \nothing;
*/
unsigned int verify_mod_less_than_divisor(unsigned int x, unsigned int y)
{
    //@ assert y > 0;
    return x % y;
}

/*@
    requires x <= 8 && y <= 8 && z <= 8;
    ensures \result == x * (y + z);
    ensures \result == x * y + x * z;
    assigns \nothing;
*/
unsigned int lemma_mul_is_distributive_add_takes_precedence(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert bounds(x, y, z);
    return x * (y + z);
}

/*@
    requires x <= 8 && y <= 8 && z <= 8;
    ensures \result == x * (y + z);
    ensures \result == x * y + x * z;
    assigns \nothing;
*/
unsigned int lemma_mul_is_distributive_add_takes_precedence_no_bounds(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert bounds(x, y, z);
    return x * (y + z);
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
