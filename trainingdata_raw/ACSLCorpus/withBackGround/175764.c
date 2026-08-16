#include <stdint.h>

/*@ predicate bounds(integer a, integer b) =
      1 <= a && a <= 100 &&
      1 <= b && b <= 100;
*/

/*@ logic integer total_sum(integer a, integer b) =
      a * 8 + b;
*/

/*@ lemma sum_nonnegative:
      \forall integer a, b; bounds(a, b) ==> total_sum(a, b) >= 0;
*/

/*@
  requires bounds(a, b);
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> \result <= total_sum(a, b);
  ensures \result == -1 ==> total_sum(a, b) / 2 < 1;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;
    uint32_t temp_sum;
    uint32_t count;

    sum = a * 8 + b;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
      loop invariant bounds(a, b);
      loop invariant 0 <= temp_sum;
      loop invariant 0 <= count;
      loop invariant temp_sum + 2 * count == sum;
      loop assigns temp_sum, count;
      loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }

    if (count < 1)
    {
        return -1;
    }
    else
    {
        result = count;
    }

    return (int32_t)result;
}
