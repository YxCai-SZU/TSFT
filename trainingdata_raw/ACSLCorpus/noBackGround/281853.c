#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures 1 <= \result <= 10000 * 10000;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top
    int product1;
    int product2;
    int result;
    
    // Precondition verification
    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert 1 <= ((a) * (b)) <= 10000 * 10000;
    
    product1 = a * b;
    
    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert 1 <= ((c) * (d)) <= 10000 * 10000;
    
    product2 = c * d;
    
    // Manual max implementation
    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }
    
    // Final verification
    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    //@ assert 1 <= result <= 10000 * 10000;
    
    return result;
}
