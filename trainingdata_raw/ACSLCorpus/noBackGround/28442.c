#include <limits.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100);
    ensures \result == (a + b) * b;
    assigns \nothing;
*/
int compute_example(int a, int b) {
    // Variable declarations at scope top
    int result;

    //@ assert (0 <= (a) <= 100 && 0 <= (b) <= 100);
    
    // Main computation
    result = (a + b) * b;
    
    //@ assert result == a * b + b * b;
    return result;
}
