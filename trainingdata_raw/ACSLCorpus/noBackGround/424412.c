#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (k) <= 100 && 1 <= (n) <= 100000);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(size_t k, size_t n) {
    int result;
    size_t a;
    size_t i;
    
    //@ assert (1 <= (k) <= 100 && 1 <= (n) <= 100000);
    
    a = 7 % k;
    i = 1;
    
    /*@ loop invariant (1 <= (k) <= 100 && 1 <= (n) <= 100000 &&
      0 <= (a) < (k) && 1 <= (i) <= (n));
        loop assigns a, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert (1 <= (k) <= 100 && 1 <= (n) <= 100000 &&       0 <= (a) < (k) && 1 <= (i) <= (n));
        a = (a * 10 + 7) % k;
        i = i + 1;
        //@ assert (1 <= (k) <= 100 && 1 <= (n) <= 100000 &&       0 <= (a) < (k) && 1 <= (i) <= (n));
    }
    
    if (a == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
