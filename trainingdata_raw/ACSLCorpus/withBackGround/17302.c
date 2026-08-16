#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    predicate distinct(integer a, integer b, integer c) =
        a != b && b != c && a != c;

    predicate contains_c(integer a, integer b, integer c) =
        (a < c && b > c) || (a > c && b < c);
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    requires distinct(a, b, c);
    ensures \result == 1 <==> contains_c(a, b, c);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool interval_contains;
    bool case1;
    bool case2;
    bool result;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    //@ assert distinct(a, b, c);

    interval_contains = (a <= c && c <= b);
    //@ assert interval_contains == (a <= c && c <= b);

    case1 = (a < c && b > c);
    //@ assert case1 == (a < c && b > c);

    case2 = (a > c && b < c);
    //@ assert case2 == (a > c && b < c);

    result = case1 || case2;
    //@ assert result == (case1 || case2);

    // Final verification property
    //@ assert result == 1 <==> contains_c(a, b, c);

    return result;
}
