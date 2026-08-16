#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;
    
    logic integer compute_n(integer x) = x / 100;
    logic integer compute_no(integer x) = compute_n(x) * 100;
    
    lemma no_relation: \forall integer x; is_valid_range(x) ==> compute_no(x) <= x + 99;
*/

/*@
    requires is_valid_range(x);
    ensures \result == (x / 100 * 100 >= x);
    assigns \nothing;
*/
bool func(unsigned int x) {
    unsigned int n;
    unsigned int no;
    
    //@ assert is_valid_range(x);
    
    n = x / 100;
    //@ assert n == compute_n(x);
    
    no = n * 100;
    //@ assert no == compute_no(x);
    
    if (no >= x) {
        //@ assert no >= x;
        return true;
    } else {
        //@ assert !(no >= x);
        return false;
    }
}
