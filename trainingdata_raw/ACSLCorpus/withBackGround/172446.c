#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 != 0;
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result <==> (a + b == c || b + c == a || c + a == b);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    result = (a + b == c) || (b + c == a) || (c + a == b);
    return result;
}

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result <==> (a + b == c || b + c == a || c + a == b);
*/
bool is_possible_to_have_x_cats(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    result = (a + b == c) || (b + c == a) || (c + a == b);
    return result;
}
