#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= N <= 100;
  requires 0 <= A <= N * N;
  ensures \result == 1 || \result == 0;
  ensures \result == 1 ==> (N * N - A) % 2 == 0;
  ensures \result == 0 ==> (N * N - A) % 2 != 0;
*/
int func(size_t N, size_t A) {
    // Variable declarations at scope top
    size_t diff;
    bool is_even;
    size_t temp_diff;
    
    //@ assert N * N <= 10000;
    
    diff = N * N - A;
    is_even = true;
    temp_diff = diff;
    
    /*@
      loop invariant 0 <= temp_diff <= diff;
      loop invariant ((diff) % 2 == (temp_diff) % 2);
      loop invariant temp_diff <= N * N;
      loop assigns temp_diff;
    */
    while (temp_diff >= 2) {
        //@ assert temp_diff >= 2;
        temp_diff -= 2;
        //@ assert ((diff) % 2 == (temp_diff) % 2);
    }
    
    if (temp_diff != 0) {
        is_even = false;
    }
    
    //@ assert is_even == (temp_diff == 0);
    //@ assert is_even == (diff % 2 == 0);
    
    if (is_even) {
        return 1;
    } else {
        return 0;
    }
}
