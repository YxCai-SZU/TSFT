#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int product1;
    int product2;
    int result;
    
    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    
    // Verify no overflow in multiplication
    //@ assert ((a) * (b)) <= 10000 * 10000;
    //@ assert ((c) * (d)) <= 10000 * 10000;
    
    product1 = a * b;
    product2 = c * d;
    
    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }
    
    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    //@ assert result >= ((a) * (b));
    //@ assert result >= ((c) * (d));
    
    return result;
}
