#include <stdbool.h>
#include <stdint.h>

/*@
  requires ((n) >= 1 && (n) <= 200000 &&
      \valid((p) + (0 .. (n)-1)) &&
      (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n)) &&
      (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]));
  ensures \result >= 1 && \result <= n;
  assigns \nothing;
*/
uint32_t func(uint32_t n, int32_t *p) {
    uint32_t count = 1;
    uint32_t index = 1;
    int32_t p_prev = p[0];
    
    /*@
      loop invariant (1 <= (index) && (index) <= (n) &&
      1 <= (count) && (count) <= (index) &&
      (((n)) >= 1 && ((n)) <= 200000 &&
      \valid(((p)) + (0 .. ((n))-1)) &&
      (\forall integer i; 0 <= i < ((n)) ==> ((p))[i] >= 1 && ((p))[i] <= ((n))) &&
      (\forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j])) &&
      ((index) > 1 ==> (\forall integer k; 0 <= k < (index) ==> (p)[k] >= 1 && (p)[k] <= (n))) &&
      ((index) > 1 ==> (\forall integer k, l; 0 <= k < l < (index) ==> (p)[k] != (p)[l])));
      loop assigns index, count, p_prev;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert (1 <= (index) && (index) <= (n) &&       1 <= (count) && (count) <= (index) &&       (((n)) >= 1 && ((n)) <= 200000 &&       \valid(((p)) + (0 .. ((n))-1)) &&       (\forall integer i; 0 <= i < ((n)) ==> ((p))[i] >= 1 && ((p))[i] <= ((n))) &&       (\forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j])) &&       ((index) > 1 ==> (\forall integer k; 0 <= k < (index) ==> (p)[k] >= 1 && (p)[k] <= (n))) &&       ((index) > 1 ==> (\forall integer k, l; 0 <= k < l < (index) ==> (p)[k] != (p)[l])));
        
        if (p[index] <= p_prev) {
            count += 1;
            p_prev = p[index];
        }
        index += 1;
    }
    
    //@ assert count >= 1 && count <= n;
    return count;
}
