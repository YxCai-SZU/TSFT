#include <stdbool.h>
#include <stdint.h>

/*@ predicate all_even(int32_t *l, integer len) =
      \forall integer i; 0 <= i < len ==> l[i] % 2 == 0;
*/

/*@ predicate has_even(int32_t *l, integer len) =
      \exists integer i; 0 <= i < len && l[i] % 2 == 0;
*/

/*@ predicate all_greater_than(int32_t *l, integer len, int32_t threshold) =
      \forall integer i; 0 <= i < len ==> l[i] > threshold;
*/

/*@ predicate has_greater_than(int32_t *l, integer len, int32_t threshold) =
      \exists integer i; 0 <= i < len && l[i] > threshold;
*/

/*@ predicate all_odd(int32_t *l, integer len) =
      \forall integer i; 0 <= i < len ==> l[i] % 2 != 0;
*/

/*@ predicate has_odd(int32_t *l, integer len) =
      \exists integer i; 0 <= i < len && l[i] % 2 != 0;
*/

/*@
  requires 1 <= n <= 100;
  ensures \result == n * n;
  assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    //@ assert n <= 100;
    //@ assert n * n <= 10000;
    return n * n;
}
