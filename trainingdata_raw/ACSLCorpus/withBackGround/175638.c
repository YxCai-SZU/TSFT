#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer n) = (n & 1) == 0; */

/*@ lemma bit_range: \forall integer n; 0 <= n <= 0xFFFFFFFF ==> 
      (n & 1) == 0 || (n & 1) == 1; */

/*@ requires 0 <= n <= 0xFFFFFFFF;
    assigns \nothing;
    ensures \result == ((n & 1) == 0);
 */
bool test_bit_operations(uint32_t n)
{
    //@ assert (n & 1) == 0 || (n & 1) == 1;
    return (n & 1) == 0;
}
