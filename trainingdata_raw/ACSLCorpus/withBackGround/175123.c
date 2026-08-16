#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10000;
    predicate b_in_range(integer b) = 1 <= b <= 10000;
    predicate product_in_range(integer a, integer b) = 
        a_in_range(a) && b_in_range(b) ==> a * b <= 10000 * 10000;
*/

/*@
    lemma product_bound: 
        \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> product_in_range(a, b);
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 != 0);
*/
bool func(unsigned int a, unsigned int b)
{
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert product_in_range(a, b);
    return (a * b) % 2 != 0;
}
