#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (N) && (N) <= 100000);
  requires (\valid((Hs)+(0..(N)-1)) && 
      \forall integer i; 0 <= i < (N) ==> (1 <= ((Hs)[i]) && ((Hs)[i]) <= 1000000000));
  ensures \result <= N - 1;
  assigns \nothing;
*/
unsigned int func(size_t N, unsigned int *Hs) {
    unsigned int max_count;
    unsigned int tmp_count;
    size_t i;
    
    max_count = 0;
    tmp_count = 0;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= N-1;
      loop invariant tmp_count <= i;
      loop invariant max_count <= i;
      loop invariant (\valid((Hs)+(0..(N)-1)) && 
      \forall integer i; 0 <= i < (N) ==> (1 <= ((Hs)[i]) && ((Hs)[i]) <= 1000000000));
      loop invariant (1 <= (N) && (N) <= 100000);
      loop assigns i, tmp_count, max_count;
      loop variant N-1-i;
    */
    while (i < N - 1) {
        if (Hs[i + 1] <= Hs[i]) {
            tmp_count = tmp_count + 1;
        } else {
            tmp_count = 0;
        }
        
        //@ assert tmp_count <= i+1;
        
        if (max_count > tmp_count) {
            max_count = max_count;
        } else {
            max_count = tmp_count;
        }
        
        //@ assert max_count <= i+1;
        
        i = i + 1;
    }
    
    //@ assert max_count <= N-1;
    return max_count;
}
