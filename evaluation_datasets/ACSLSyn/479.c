#include <stdbool.h>

/* ACSL predicates for the first function */
/*@
    predicate is_even_divisible(integer sum) = (sum % 4) == 0;
    predicate is_a_even(integer a) = (a % 2) == 0;
*/

bool date_validation(int a, int b, int c) {
    int sum;
    bool is_even_divisible_val;
    bool is_a_even_val;
    bool result;
    
    sum = b * 10 + c;
    is_even_divisible_val = ((unsigned int)sum % 4) == 0;
    is_a_even_val = ((unsigned int)a % 2) == 0;
    
    if (is_even_divisible_val || is_a_even_val) {
        //@ assert is_even_divisible_val || is_a_even_val;
        result = true;
    } else {
        //@ assert !is_even_divisible_val && !is_a_even_val;
        result = false;
    }
    
    return result;
}

/* ACSL predicates for the second function */
/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        0 <= m && m <= n;

    predicate func_post(integer n, integer m, bool result) =
        result == (n == m);
*/

bool id_match(unsigned int n, unsigned int m)
{
    //@ assert n == m ==> n == m;
    return n == m;
}

bool id_match_int(int n, int m)
{
    //@ assert n == m ==> n == m;
    return n == m;
}

bool id_match_checked(unsigned int n, unsigned int m)
{
    //@ assert n <= 100;
    //@ assert m <= n;
    //@ assert 1 <= n;
    //@ assert 0 <= m;
    return n == m;
}

/* Synthesized function: Date-based Access Control
 * Scenario: A system grants access based on a date code (day/month) and user ID matching.
 * The date validation ensures the day (b*10 + c) is divisible by 4 or the month (a) is even.
 * The ID matching checks if the user's ID (n) matches the required access level (m).
 * Access is granted only if both conditions are satisfied.
 */
bool access_control(int a, int b, int c, unsigned int n, unsigned int m) {
    bool date_ok = date_validation(a, b, c);
    bool id_ok = id_match(n, m);
    
    bool granted = date_ok && id_ok;
    
    return granted;
}
