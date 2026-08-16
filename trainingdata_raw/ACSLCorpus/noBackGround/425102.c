#include <stddef.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (i) <= (n));
    ensures \result == ((n) - (i) + 1);
    ensures 1 <= \result <= n;
    assigns \nothing;
*/
size_t input_tuple(size_t n, size_t i) {
    size_t j;
    
    //@ assert (1 <= (n) <= 100 && 1 <= (i) <= (n));
    j = n - i + 1;
    
    //@ assert j == ((n) - (i) + 1);
    //@ assert 1 <= j <= n;
    
    return j;
}
