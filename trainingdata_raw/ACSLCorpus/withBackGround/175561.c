#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    
    predicate valid_input(integer a, integer b, integer c, integer d) =
        in_range(a) && in_range(b) && in_range(c) && in_range(d) &&
        a <= b && c <= d;
    
    logic integer product(integer x, integer y) = x * y;
    
    predicate is_possible_product(integer val, integer a, integer b, integer c, integer d) =
        val == product(a, c) || val == product(a, d) ||
        val == product(b, c) || val == product(b, d);
*/

/*@
    requires valid_input(a, b, c, d);
    ensures is_possible_product(\result, a, b, c, d);
*/
long long func(long long a, long long b, long long c, long long d) {
    long long x[4];
    long long max_value;
    int i;
    
    //@ assert -1000000000000000000LL <= a * c <= 1000000000000000000LL;
    x[0] = a * c;
    
    //@ assert -1000000000000000000LL <= a * d <= 1000000000000000000LL;
    x[1] = a * d;
    
    //@ assert -1000000000000000000LL <= b * c <= 1000000000000000000LL;
    x[2] = b * c;
    
    //@ assert -1000000000000000000LL <= b * d <= 1000000000000000000LL;
    x[3] = b * d;
    
    max_value = x[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_value == x[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_value >= x[j];
        loop invariant \forall integer k; 0 <= k < 4 ==> 
            is_possible_product(x[k], a, b, c, d);
        loop assigns i, max_value;
    */
    while (i < 4) {
        if (x[i] > max_value) {
            max_value = x[i];
        }
        i++;
    }
    
    //@ assert is_possible_product(max_value, a, b, c, d);
    return max_value;
}
