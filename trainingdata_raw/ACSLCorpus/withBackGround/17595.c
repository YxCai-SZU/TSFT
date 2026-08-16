#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_array(uint32_t *a, size_t n) =
      n >= 2 && n <= 100000 &&
      \valid(a + (0 .. n-1)) &&
      \forall size_t i; 0 <= i < n ==> 1 <= a[i] && a[i] <= n;
*/

/*@ logic integer max(integer x, integer y) = (x > y) ? x : y;
*/

/*@ lemma result_bound:
      \forall uint32_t *a, size_t n, integer i, integer cur, integer res;
      valid_array(a, n) &&
      0 <= i <= n &&
      0 <= cur <= i &&
      0 <= res <= i ==>
      (cur <= i) && (res <= n);
*/

/*@ requires n >= 2 && n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires \forall size_t i; 0 <= i < n ==> 1 <= a[i] && a[i] <= n;
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
uint32_t func(size_t n, uint32_t *a) {
    uint32_t result = 0;
    uint32_t current = 0;
    size_t i = 0;

    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= current <= i;
        loop invariant 0 <= result <= i;
        loop invariant \forall size_t j; 0 <= j < i ==> 1 <= a[j] && a[j] <= n;
        loop invariant n >= 2 && n <= 100000;
        loop assigns i, current, result;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] == current + 1) {
            current += 1;
        } else {
            result += 1;
        }
        i += 1;
    }
    //@ assert i == n;
    //@ assert 0 <= result <= n;
    return result;
}
