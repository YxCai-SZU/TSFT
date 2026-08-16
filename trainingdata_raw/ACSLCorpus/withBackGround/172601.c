#include <stddef.h>
#include <stdint.h>

/*@ predicate is_valid_array(int64_t *p, size_t n) =
      n >= 1 && n <= 200000 &&
      \valid(p + (0 .. n-1)) &&
      \forall size_t i; 0 <= i < n ==> p[i] >= 1 && p[i] <= (int64_t)n &&
      \forall size_t i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@ lemma count_bounds:
      \forall size_t n; n >= 1 && n <= 200000 ==>
      \forall size_t index; 1 <= index <= n ==>
      \forall int32_t count; 1 <= count <= (int32_t)index ==> 1 <= count <= (int32_t)n;
*/

/*@ requires is_valid_array(p, n);
    assigns \nothing;
    ensures 1 <= \result <= (int32_t)n;
*/
int32_t func(size_t n, const int64_t *p) {
    int32_t count;
    size_t index;
    int64_t p1;
    int64_t p2;

    count = 1;
    index = 1;
    p1 = p[0];
    p2 = p[0];

    /*@ loop invariant 1 <= index <= n;
        loop invariant 1 <= count <= (int32_t)index;
        loop invariant is_valid_array(p, n);
        loop assigns count, index, p1, p2;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert count <= (int32_t)index;
        if (p1 >= p2) {
            p1 = p2;
            count += 1;
        } else {
            p2 = p[index];
        }
        index += 1;
    }

    //@ assert 1 <= count <= (int32_t)n;
    return count;
}
