#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    requires a <= b && c <= d;
    ensures \result == ((b) * (d)) || \result == ((b) * (c)) || 
            \result == ((a) * (d)) || \result == ((a) * (c));
    assigns \nothing;
*/
long func(long a, long b, long c, long d) {
    long max_val;
    long temp_val;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert ((a) * (c)) <= 100000000;
    //@ assert ((a) * (d)) <= 100000000;
    //@ assert ((b) * (c)) <= 100000000;
    //@ assert ((b) * (d)) <= 100000000;
    
    max_val = a * c;
    
    temp_val = a * d;
    //@ assert temp_val == ((a) * (d));
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    temp_val = b * c;
    //@ assert temp_val == ((b) * (c));
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    temp_val = b * d;
    //@ assert temp_val == ((b) * (d));
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert max_val == ((b) * (d)) || max_val == ((b) * (c)) || max_val == ((a) * (d)) || max_val == ((a) * (c));
    
    return max_val;
}
