#include <stdbool.h>

/*@ predicate is_valid_params(integer a, integer b, integer c, integer d, integer e, integer k) =
    a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 && k >= 0 &&
    a <= 123 && b <= 123 && c <= 123 && d <= 123 && e <= 123 && k <= 123 &&
    a < b && b < c && c < d && d < e;
*/

/*@ lemma subtraction_bound: 
    \forall integer a, integer e, integer k; 
    a >= 0 && e >= 0 && k >= 0 && a <= 123 && e <= 123 && k <= 123 ==> 
    (e - a <= k) == (e - a <= k);
*/

/*@ requires is_valid_params(a, b, c, d, e, k);
    ensures \result == true <==> (e - a <= k);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k) {
    // Variable declarations at the top
    bool result;
    
    //@ assert a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 && k >= 0;
    //@ assert a <= 123 && b <= 123 && c <= 123 && d <= 123 && e <= 123 && k <= 123;
    //@ assert a < b && b < c && c < d && d < e;
    
    result = (e - a) <= k;
    
    //@ assert result == true <==> (e - a <= k);
    return result;
}
