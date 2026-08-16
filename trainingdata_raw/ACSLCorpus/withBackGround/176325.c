#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;
    
    logic integer division_result(integer x) = x / 100;
    
    logic integer multiplication_result(integer n) = n * 100;
    
    lemma division_multiple_bound: 
        \forall integer x; is_valid_range(x) ==> 
            division_result(x) * 100 <= x;
*/

/*@
    requires is_valid_range(x);
    ensures \result == ( (x / 100) * 100 <= x );
    assigns \nothing;
*/
bool func(unsigned int x) {
    unsigned int n;
    unsigned int sub;
    
    //@ assert is_valid_range(x);
    
    n = x / 100;
    
    //@ assert n == division_result(x);
    
    //@ assert multiplication_result(n) <= x;
    
    sub = n * 100;
    
    if (sub <= x) {
        return true;
    } else {
        return false;
    }
}
