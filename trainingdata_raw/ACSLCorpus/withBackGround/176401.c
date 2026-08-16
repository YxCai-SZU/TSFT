#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c) =
        1 <= a <= 500 &&
        1 <= b <= 500 &&
        1 <= c <= 1000;

    logic integer absolute(integer x) = (x < 0) ? -x : x;

    lemma abs_nonnegative:
        \forall integer x; absolute(x) >= 0;

    lemma abs_bound:
        \forall integer a, b; 
            1 <= a <= 500 && 1 <= b <= 500 ==> 
            absolute(a + b) <= 1000;
*/

/*@
    requires is_valid_range(a, b, c);
    ensures \result == ((a + b) >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    int sum;
    int abs_sum;

    //@ assert is_valid_range(a, b, c);
    
    sum = a + b;
    
    //@ assert sum == a + b;
    
    if (sum < 0) {
        abs_sum = -sum;
    } else {
        abs_sum = sum;
    }
    
    //@ assert abs_sum == absolute(sum);
    //@ assert abs_sum >= 0;
    //@ assert abs_sum <= 1000;
    
    return (sum >= 0 && abs_sum >= c) || (sum < 0 && abs_sum >= c);
}
