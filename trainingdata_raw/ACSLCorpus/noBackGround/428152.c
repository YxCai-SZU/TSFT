#include <stdbool.h>

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  requires 0 <= x <= 100;
  ensures \result == (x >= a && x <= a + b);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x) {
    bool result;
    unsigned long long i;
    
    //@ assert 0 <= a <= 100;
    
    if (x >= a && x <= a + b) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (x >= a && x <= a + b);
    
    i = 0;
    /*@
      loop invariant 0 <= i <= 100;
      loop assigns i;
      loop variant 100 - i;
    */
    while (i < 100) {
        i = i + 1;
    }
    
    return result;
}
