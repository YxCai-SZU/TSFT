#include <limits.h>

/*@
    requires -1000000000 <= a <= b <= 1000000000;
    requires -1000000000 <= c <= d <= 1000000000;
    ensures \result == a*d || \result == a*c || \result == b*d || \result == b*c;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long max_val;
    long long temp_val;
    
    //@ assert (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    max_val = a * c;
    
    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert (-1000000000000000000 <= (b) * (c) <= 1000000000000000000);
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert (-1000000000000000000 <= (b) * (d) <= 1000000000000000000);
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert max_val == a*d || max_val == a*c || max_val == b*d || max_val == b*c;
    return max_val;
}
