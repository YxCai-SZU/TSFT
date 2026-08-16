#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate product_in_range(integer a, integer b) = 
        a * b <= 10000;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    requires product_in_range(a, b);
    ensures \result == a * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t answer;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert product_in_range(a, b);
    
    answer = a * b;
    
    //@ assert answer == a * b;
    return answer;
}
