#include <stdint.h>

/*@ predicate is_valid_n(integer n) = 1 <= n && n <= 100; */

/*@ lemma square_bound: 
      \forall integer n; is_valid_n(n) ==> n * n <= 10000; */

/*@ requires is_valid_n(n);
    ensures \result == n * n;
    assigns \nothing;
 */
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    
    result = n * n;
    return result;
}

int main()
{
    return 0;
}
