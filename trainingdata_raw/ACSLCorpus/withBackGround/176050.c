#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer compute_c(integer a, integer b) = a * 3 + b;
    logic integer compute_c2(integer a, integer b) = (a * 3 + b) / 2;
    logic integer compute_sum(integer a, integer b) = a + b;
    
    lemma multiplication_bound: \forall integer a; a_in_range(a) ==> a * 3 <= 300;
    lemma addition_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> a * 3 + b <= 400;
    lemma division_definition: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> 
        compute_c2(a, b) == compute_c(a, b) / 2;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ((a * 3 + b) / 2 >= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int c;
    unsigned int c2;
    bool result;
    
    //@ assert a * 3 <= 300;
    //@ assert a * 3 + b <= 400;
    
    c = a * 3 + b;
    c2 = c / 2;
    
    //@ assert c2 == (a * 3 + b) / 2;
    
    result = (c2 >= a + b);
    return result;
}
