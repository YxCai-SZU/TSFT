#include <stdbool.h>

/*@
    predicate can_distribute(integer a, integer b, integer c) =
        a + b == c || b + c == a || c + a == b;
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result <==> can_distribute(a, b, c);
*/
bool can_distribute_evenly(unsigned long long a, unsigned long long b, unsigned long long c) {
    bool is_evenly_distributable;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    is_evenly_distributable = (a + b == c) || (b + c == a) || (c + a == b);
    
    //@ assert is_evenly_distributable <==> can_distribute(a, b, c);
    
    return is_evenly_distributable;
}
