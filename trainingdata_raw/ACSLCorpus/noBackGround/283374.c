#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 20 &&
      1 <= (a) && (a) <= 50 &&
      1 <= (b) && (b) <= 50);
    ensures \result <= b;
    ensures \result >= a * n || \result == b;
    assigns \nothing;
*/
size_t func(size_t n, size_t a, size_t b) {
    // Variable declarations at scope top
    size_t x;
    
    //@ assert (1 <= (n) && (n) <= 20 &&       1 <= (a) && (a) <= 50 &&       1 <= (b) && (b) <= 50);
    
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    
    //@ assert a * n <= 50 * 20;
    
    x = a * n;
    
    if (x < b) {
        //@ assert x >= a * n;
        return x;
    } else {
        //@ assert b <= b;
        return b;
    }
}
