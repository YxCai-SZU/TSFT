#include <stddef.h>

/*@ requires (1 <= (a) && (a) <= 100 &&
      1 <= (b) && (b) <= 100 &&
      1 <= (c) && (c) <= 100);
    ensures \result <= c;
    ensures \result <= ((a) * (b));
    ensures \result == ((a) * (b)) || \result == c;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c) {
    // Variable declarations at scope top
    size_t result;
    
    //@ assert ((a) * (b)) <= 10000;
    
    if (a * b < c) {
        result = a * b;
    } else {
        //@ assert ((a) * (b)) >= c;
        result = c;
    }
    
    return result;
}
