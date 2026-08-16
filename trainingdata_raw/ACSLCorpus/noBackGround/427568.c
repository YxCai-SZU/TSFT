#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(a + (0 .. n-1));
  requires ((n) >= 2 && (n) <= 100000 &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 10000);
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= (int)n;
*/
int func(size_t n, int *a) {
    int res = 0;
    int prev = -1;
    size_t index = 0;
    
    /*@
      loop invariant (0 <= (index) && (index) <= (n) &&
      (res) >= 0 &&
      (res) <= (int)(index) &&
      ((index) > 0 ==> \forall size_t i; 0 <= i < (index) ==> 1 <= (a)[i] && (a)[i] <= 10000) &&
      (n) >= 2 && (n) <= 100000);
      loop assigns index, res, prev;
      loop variant n - index;
    */
    while (index < n) {
        int a_i = a[index];
        
        //@ assert 0 <= index && index < n;
        //@ assert 1 <= a_i && a_i <= 10000;
        
        if (a_i < prev) {
            //@ assert a_i < prev;
            res += 1;
        } else {
            //@ assert a_i >= prev;
            prev = a_i;
        }
        
        index += 1;
    }
    
    return res;
}
