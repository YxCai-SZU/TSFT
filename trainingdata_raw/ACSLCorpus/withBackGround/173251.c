#include <stdint.h>

/*@ predicate valid_range(integer a, integer b) =
      1 <= a && a <= b && b <= 100;
*/

/*@ logic integer price_upper_bound(integer diff) =
      diff * 50 / 10;
*/

/*@ lemma diff_bound: \forall integer a, b;
      valid_range(a, b) ==> b - a <= 100;
*/

/*@ lemma price_bound: \forall integer a, b;
      valid_range(a, b) ==> (b - a) * 50 / 10 <= 5000;
*/

/*@
  requires valid_range(a, b);
  ensures \result == -1 ||
          (\result >= 0 && \result < 1000000 &&
           \result * 8 / 100 == a && \result * 10 / 100 == b);
  assigns \nothing;
*/
int64_t func(uint64_t a, uint64_t b)
{
    uint64_t diff = b - a;
    uint64_t price = diff * 50 / 10;

    /*@
      loop invariant 1 <= a && a <= b && b <= 100;
      loop invariant price <= diff * 50 / 10;
      loop invariant price >= 0;
      loop invariant diff <= 100;
      loop invariant price <= 5000;
      loop assigns price;
      loop variant price;
    */
    while (price > 0)
    {
        //@ assert price * 8 / 100 <= 100;
        if (price * 8 / 100 == a && price * 10 / 100 == b)
        {
            return (int64_t)price;
        }
        price -= 1;
    }

    return -1;
}
