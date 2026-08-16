#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_vector(int n, uint32_t *v) =
      n > 0 && n <= 200 &&
      \valid(v + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> v[i] < 100;
*/

/*@ predicate count_bounds(int i, int n, uint32_t n3, uint32_t n5, uint32_t n7) =
      i <= n &&
      n3 >= 0 && n3 <= (uint32_t)i &&
      n5 >= 0 && n5 <= (uint32_t)i &&
      n7 >= 0 && n7 <= (uint32_t)i;
*/

/*@ lemma vector_preserved:
      \forall int n, uint32_t *v, int i;
      valid_vector(n, v) && 0 <= i < n ==> v[i] < 100;
*/

/*@
  requires valid_vector(n, v);
  ensures \result >= 0 && \result <= n;
  ensures valid_vector(n, v);
*/
int32_t func(int n, uint32_t *v) {
    uint32_t n3 = 0;
    uint32_t n5 = 0;
    uint32_t n7 = 0;
    int i = 0;
    int32_t res = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant count_bounds(i, n, n3, n5, n7);
      loop invariant valid_vector(n, v);
      loop assigns i, n3, n5, n7;
      loop variant n - i;
    */
    while (i < n) {
        uint32_t value = v[i];
        
        //@ assert value < 100;
        
        if (value % 3 == 0) {
            n3 += 1;
        }
        if (value % 5 == 0) {
            n5 += 1;
        }
        if (value % 7 == 0) {
            n7 += 1;
        }
        i += 1;
    }

    if (n3 > n5 && n3 > n7) {
        res = (int32_t)n3;
    } else if (n5 > n3 && n5 > n7) {
        res = (int32_t)n5;
    } else {
        res = (int32_t)n7;
    }

    //@ assert res >= 0 && res <= n;
    return res;
}
