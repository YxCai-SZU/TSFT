#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(unsigned int *a, size_t n) =
      n >= 1 && n <= 200000 &&
      \valid(a + (0 .. n-1)) &&
      \forall size_t i; 0 <= i < n ==> a[i] >= 1 && a[i] <= n;
*/

/*@ lemma count_bounds:
      \forall unsigned int count, size_t index, size_t n;
        0 <= index <= n && 0 <= count <= index ==> 0 <= count <= n;
*/

/*@ requires n >= 1 && n <= 200000;
    requires \valid(a + (0 .. n-1));
    requires \forall size_t i; 0 <= i < n ==> a[i] >= 1 && a[i] <= n;
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
unsigned int func(size_t n, const unsigned int *a) {
    unsigned int count = 0;
    size_t index = 0;
    bool has_zero = false;

    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant is_valid_array(a, n);
        loop assigns count, index, has_zero;
        loop variant n - index;
    */
    while (index < n) {
        unsigned int i = a[index];
        //@ assert i >= 1 && i <= n;
        if (i == count + 1) {
            count = count + 1;
        }
        index = index + 1;
        //@ assert 0 <= count <= index;
    }
    //@ assert 0 <= count <= n;
    return count;
}
