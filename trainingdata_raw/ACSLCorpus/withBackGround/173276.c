#include <stddef.h>

/*@
    predicate is_multiple_of_1000(integer n) = n % 1000 == 0;
    logic integer calculate_change(integer n) = 
        (n % 1000 == 0) ? 0 : 1000 - (n % 1000);
    
    lemma change_property:
        \forall integer n; 1 <= n <= 1000000 ==> 
        calculate_change(n) == ((n % 1000 == 0) ? 0 : 1000 - (n % 1000));
*/

/*@
    requires 1 <= n <= 1000000;
    ensures \result == calculate_change(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t change;
    
    if (n % 1000 == 0) {
        //@ assert n % 1000 == 0;
        change = 0;
    } else {
        //@ assert n % 1000 != 0;
        change = 1000 - (n % 1000);
    }
    
    //@ assert change == calculate_change(n);
    return change;
}
