#include <stdbool.h>

/*@
  requires (1 <= (a) <= 3) && (1 <= (b) <= 3);
  ensures \result == (a * b % 2 != 0);
  assigns \nothing;
*/
bool func(unsigned long a, unsigned long b) {
    unsigned long c;
    bool is_odd = false;
    unsigned long temp_c;
    
    //@ assert a * b <= 9;
    if (a == 1 || a == 3) {
        c = a * b;
    } else if (b == 1 || b == 3) {
        c = a * b;
    } else {
        c = 0;
    }
    
    temp_c = c;
    /*@
      loop invariant 0 <= temp_c <= c;
      loop invariant temp_c <= a * b;
      loop invariant temp_c % 2 == c % 2;
      loop assigns temp_c;
      loop variant temp_c;
    */
    while (temp_c >= 2) {
        temp_c -= 2;
    }
    
    if (temp_c == 1) {
        is_odd = true;
    }
    
    //@ assert is_odd == (a * b % 2 != 0);
    return is_odd;
}
