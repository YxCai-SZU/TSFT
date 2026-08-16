#include <stdint.h>
#include <stddef.h>

/*@
  requires ((N) >= 1 && (N) <= 100000 &&
      \valid((Hs) + (0 .. (N)-1)) &&
      \forall integer i; 0 <= i < (N) ==> ((Hs)[i] >= 1 && (Hs)[i] <= 1000000000));
  ensures \result <= N - 1;
  assigns \nothing;
*/
uint64_t func(size_t N, uint64_t *Hs) {
    uint64_t max_count = 0;
    uint64_t tmp_count = 0;
    size_t index = 0;

    //@ assert ((index) <= (N) - 1 &&       (max_count) <= (index) &&       (tmp_count) <= (index) &&       (((N)) >= 1 && ((N)) <= 100000 &&       \valid(((Hs)) + (0 .. ((N))-1)) &&       \forall integer i; 0 <= i < ((N)) ==> (((Hs))[i] >= 1 && ((Hs))[i] <= 1000000000)));
    
    /*@
      loop invariant ((index) <= (N) - 1 &&
      (max_count) <= (index) &&
      (tmp_count) <= (index) &&
      (((N)) >= 1 && ((N)) <= 100000 &&
      \valid(((Hs)) + (0 .. ((N))-1)) &&
      \forall integer i; 0 <= i < ((N)) ==> (((Hs))[i] >= 1 && ((Hs))[i] <= 1000000000)));
      loop invariant index <= N - 1;
      loop assigns index, max_count, tmp_count;
      loop variant N - index;
    */
    while (index < N - 1) {
        //@ assert index < N - 1;
        
        if (Hs[index + 1] <= Hs[index]) {
            tmp_count += 1;
        } else {
            if (tmp_count >= max_count) {
                max_count = tmp_count;
            }
            tmp_count = 0;
        }
        index += 1;
        
        //@ assert ((index) <= (N) - 1 &&       (max_count) <= (index) &&       (tmp_count) <= (index) &&       (((N)) >= 1 && ((N)) <= 100000 &&       \valid(((Hs)) + (0 .. ((N))-1)) &&       \forall integer i; 0 <= i < ((N)) ==> (((Hs))[i] >= 1 && ((Hs))[i] <= 1000000000)));
    }
    
    if (tmp_count >= max_count) {
        max_count = tmp_count;
    }
    
    //@ assert max_count <= N - 1;
    return max_count;
}
