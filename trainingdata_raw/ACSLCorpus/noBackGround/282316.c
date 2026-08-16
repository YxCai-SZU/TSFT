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
    // Variable declarations at scope top
    int product1;
    int product2;
    int result;
    
    // Precondition assertions
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    // Safe multiplication bounds
    //@ assert ((a) * (b)) <= INT_MAX;
    //@ assert ((c) * (d)) <= INT_MAX;
    
    product1 = a * b;
    product2 = c * d;
    
    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }
    
    // Postcondition verification
    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    //@ assert result >= ((a) * (b));
    //@ assert result >= ((c) * (d));
    
    return result;
}
