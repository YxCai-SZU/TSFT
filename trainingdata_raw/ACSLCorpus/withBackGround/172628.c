#include <stdbool.h>

/*@
    predicate is_even(integer n) = (n * 100) % 2 == 0;
    predicate condition(integer n, integer m) = 
        (is_even(n) && m >= 13) || (!is_even(n) && m >= 13);
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == 1 <==> condition(n, m);
*/
bool func(int n, int m) {
    bool is_even_bool;
    bool result;

    // Declare all variables at the top
    is_even_bool = (n * 100) % 2 == 0;
    
    if (is_even_bool) {
        if (m >= 13) {
            //@ assert is_even_bool && m >= 13;
            result = true;
        } else {
            //@ assert is_even_bool && m < 13;
            result = false;
        }
    } else {
        if (m >= 13) {
            //@ assert !is_even_bool && m >= 13;
            result = true;
        } else {
            //@ assert !is_even_bool && m < 13;
            result = false;
        }
    }
    
    return result;
}
