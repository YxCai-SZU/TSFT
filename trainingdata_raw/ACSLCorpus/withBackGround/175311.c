#include <stdbool.h>

/*@
    predicate valid_angle(integer a) = 0 <= a <= 100;
    predicate valid_triangle(integer a, integer b, integer c) = 
        valid_angle(a) && valid_angle(b) && valid_angle(c);
*/

/*@
    logic integer angle_sum(integer a, integer b, integer c) = a + b + c;
*/

/*@
    lemma sum_bounds:
        \forall integer a, b, c;
        valid_triangle(a, b, c) ==> 
            0 <= angle_sum(a, b, c) <= 300;
*/

/*@
    requires valid_triangle(a, b, c);
    ensures \result == (angle_sum(a, b, c) == 180);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int sum;
    
    //@ assert valid_angle(a);
    //@ assert valid_angle(b);
    //@ assert valid_angle(c);
    
    sum = a + b + c;
    
    //@ assert sum == angle_sum(a, b, c);
    //@ assert 0 <= sum <= 300;
    
    return sum == 180;
}
