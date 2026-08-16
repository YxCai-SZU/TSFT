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
    int max_value;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) <= 100000000;
    
    product1 = a * b;
    
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 100000000;
    
    product2 = c * d;
    
    if (product1 > product2) {
        max_value = product1;
    } else {
        max_value = product2;
    }
    
    //@ assert max_value >= ((a) * (b));
    //@ assert max_value >= ((c) * (d));
    //@ assert max_value == ((a) * (b)) || max_value == ((c) * (d));
    
    return max_value;
}
