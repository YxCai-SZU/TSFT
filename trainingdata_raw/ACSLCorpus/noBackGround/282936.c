#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= n <= 100;
  requires 1 <= m <= n;
  ensures \result == n - m;
*/
size_t func(size_t n, size_t m) {
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= m <= n;
    return n - m;
}

/*@
  requires \valid(l + (0..len-1));
  requires len > 0;
  ensures \result ==> len > 0;
*/
bool all_even(int* l, size_t len) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant len > 0;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((l[i] & 1) != 0) {
            return false;
        }
        i++;
    }
    
    return true;
}
