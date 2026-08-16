#include <stdbool.h>

/*@
    predicate is_possible(integer a, integer b, integer c) =
        (a < c && c < b) || (a > c && c > b);
 */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> is_possible(a, b, c);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool is_possible_var = false;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;

    if (a < c && c < b) {
        is_possible_var = true;
    } else if (a > c && c > b) {
        is_possible_var = true;
    }

    //@ assert is_possible_var == true <==> is_possible(a, b, c);

    return is_possible_var;
}
