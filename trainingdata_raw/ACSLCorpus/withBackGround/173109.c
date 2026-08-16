#include <stdbool.h>

/*@ predicate is_valid_range(integer n) = 1 <= n <= 100; */

/*@
  requires is_valid_range(n);
  ensures \result == 1 || \result == 0;
  ensures \result == 1 ==> is_valid_range(n);
  ensures \result == 0 ==> is_valid_range(n);
*/
int func(int n) {
    int i;
    int result;
    
    i = 0;
    /*@
      loop invariant 0 <= i <= 100;
      loop invariant is_valid_range(n);
      loop assigns i;
    */
    while (i < 100) {
        i += 1;
    }
    
    if (n >= 1 && n <= 100) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == 1 || result == 0;
    return result;
}
