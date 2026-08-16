#include <stdbool.h>
#include <stddef.h>

/*@
  requires N >= 1 && N <= 20;
  requires ((N) >= 1 && (N) <= 20 &&
      \forall integer i; 0 <= i < (N) ==> (H)[i] >= 1 && (H)[i] <= 100);
  assigns \nothing;
  ensures \result >= 0 && \result <= N;
*/
int func(size_t N, int *H) {
    // Variable declarations at top of scope
    int min;
    int count;
    size_t i;
    int h;
    
    min = H[0];
    count = 0;
    i = 0;
    
    /*@ loop invariant (0 <= (i) <= (N) &&
      (((N)) >= 1 && ((N)) <= 20 &&
      \forall integer i; 0 <= i < ((N)) ==> ((H))[i] >= 1 && ((H))[i] <= 100) &&
      (min) >= 1 && (min) <= 100 &&
      (count) >= 0 && (count) <= (i));
        loop assigns i, min, count, h;
        loop variant N - i;
    */
    while (i < N) {
        h = H[i];
        
        //@ assert h >= 1 && h <= 100;
        
        if (min <= h) {
            //@ assert min <= h;
            count += 1;
            min = h;
        }
        
        i += 1;
    }
    
    return count;
}
