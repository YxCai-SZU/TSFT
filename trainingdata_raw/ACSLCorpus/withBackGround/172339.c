#include <stdint.h>

/*@ predicate in_range(integer v) = 1 <= v <= 100; */
/*@ predicate product_in_range(integer a, integer b) = 
      1 <= a * b <= 10000; */

/*@ lemma product_bound: 
      \forall integer n, m; 
      in_range(n) && in_range(m) ==> product_in_range(n, m); */

/*@ requires in_range(r);
    ensures \result == r * r;
    assigns \nothing;
 */
int32_t func(int32_t r)
{
    //@ assert product_in_range(r, r);
    return r * r;
}

/*@ requires in_range(n) && in_range(m);
    ensures \result == n * m;
    assigns \nothing;
 */
int32_t func2(int32_t n, int32_t m)
{
    //@ assert product_in_range(n, m);
    return n * m;
}
