#include <stdbool.h>

/*@ predicate sum_mod_three(integer a, integer b, integer c, integer s) =
      s == a + b + c && s % 3 == 0;
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result <==> (a + b + c) % 3 == 0;
    assigns \nothing;
*/
bool can_distribute_evenly(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int sum;
    bool is_possible;
    
    sum = a + b + c;
    
    //@ assert sum == a + b + c;
    
    is_possible = (sum % 3 == 0);
    return is_possible;
}
