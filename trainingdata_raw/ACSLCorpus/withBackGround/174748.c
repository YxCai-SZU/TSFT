#include <stdint.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

/*@
    requires 1 <= r <= 100;
    ensures \result == r * r;
    assigns \nothing;
*/
uint32_t func(uint32_t r)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert 1 <= r <= 100;
    //@ assert r * r <= 10000;
    
    result = r * r;
    return result;
}

/*@
    lemma square_bounds:
        \forall integer r; 1 <= r <= 100 ==> r * r <= 10000;
*/

int main()
{
    return 0;
}
