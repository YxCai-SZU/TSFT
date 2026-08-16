#include <stdbool.h>

/*@
    predicate a_less_b_plus_one(integer a, integer b) = a < b + 1;
    predicate a_plus_one_less_b_plus_one(integer a, integer b) = a + 1 < b + 1;
*/

/*@
    lemma calc_example_i: 
        \forall integer a, b; 
        a < b ==> a_plus_one_less_b_plus_one(a, b);
*/

/*@
    requires \true;
    assigns \nothing;
*/
int main() {
    int a = 0;
    int b = 1;
    
    //@ assert a < b;
    
    //@ assert a_less_b_plus_one(a, b);
    
    //@ assert a_plus_one_less_b_plus_one(a, b);
    
    return 0;
}
