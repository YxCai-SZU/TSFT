#include <stdint.h>

/*@
  requires (1 <= (r) <= 100);
  ensures \result == (2 * (3) * (r));
  assigns \nothing;
*/
int64_t func(int64_t r) {
    int64_t pi;
    int64_t circumference;
    
    pi = 3;
    
    //@ assert pi == 3;
    
    //@ assert 2 * pi == 6;
    //@ assert 6 * 100 <= 9223372036854775807;
    //@ assert 6 * 1 >= -9223372036854775808;
    
    circumference = 2 * pi * r;
    
    //@ assert circumference == (2 * (pi) * (r));
    
    return circumference;
}
