#include <stdint.h>
#include <stdbool.h>

/*@ predicate is_valid_index(integer i, integer n) = 0 <= i < n; */

/*@ predicate element_in_range(integer val) = -100 <= val <= 100; */

/*@ predicate array_in_range(int32_t* a, integer n) =
      \forall integer i; 0 <= i < n ==> element_in_range(a[i]); */

/*@ logic integer bound(integer i) = 100 * i; */

/*@ lemma sum_bound_lemma:
      \forall integer i, integer n, integer sum;
        0 <= i <= n &&
        -bound(i) <= sum <= bound(i) &&
        i == n ==>
        -bound(n) <= sum <= bound(n); */

/*@ requires
      0 < n <= 100 &&
      \valid(a + (0 .. n-1)) &&
      array_in_range(a, n);
    ensures
      -bound(n) <= \result <= bound(n); */
int32_t func(uint32_t n, int32_t* a)
{
    int32_t sum = 0;
    uint32_t i = 0;

    /*@ loop invariant
          0 <= i <= n &&
          -bound(i) <= sum <= bound(i) &&
          array_in_range(a, n);
      loop assigns
          sum, i; */
    while (i < n)
    {
        //@ assert is_valid_index(i, n);
        //@ assert element_in_range(a[i]);
        sum += a[i];
        i++;
    }

    //@ assert i == n;
    //@ assert -bound(n) <= sum <= bound(n);
    return sum;
}
