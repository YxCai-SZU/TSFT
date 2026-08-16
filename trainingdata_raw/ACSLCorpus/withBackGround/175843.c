#include <stdbool.h>

/*@
    predicate distinct(integer a, integer b, integer c) =
        a != b && a != c && b != c;

    predicate is_between(integer a, integer b, integer c) =
        (a <= c && c <= b) || (a >= c && c >= b);
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires distinct(a, b, c);
    ensures \result == true <==> is_between(a, b, c);
*/
bool func(int a, int b, int c)
{
    int max_ab;
    int min_ab;
    bool condition;

    //@ ghost int original_a = a;
    //@ ghost int original_b = b;
    //@ ghost int original_c = c;

    if (a > b)
    {
        max_ab = a;
        min_ab = b;
    }
    else
    {
        max_ab = b;
        min_ab = a;
    }

    condition = (min_ab <= c && c <= max_ab);

    //@ assert condition == ((original_a <= original_c && original_c <= original_b) || (original_a >= original_c && original_c >= original_b));

    return condition;
}
