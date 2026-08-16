#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 10000;

    logic integer sum_three(integer a, integer b, integer c) = a + b + c;

    lemma condition_lemma:
        \forall integer a, b, c, d;
        (is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d)) ==>
        ((a > b + c) || (b > a + c) || (c > a + b) || (d >= a + b + c)) ==
        ((a > b + c) || (b > a + c) || (c > a + b) || (d >= a + b + c));
*/


bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result = false;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    //@ assert is_valid_range(d);

    if (a > b + c || b > a + c || c > a + b)
    {
        result = true;
    }

    //@ assert result == ((a > b + c) || (b > a + c) || (c > a + b));

    if (d >= a + b + c)
    {
        result = true;
    }

    //@ assert result == ((a > b + c) || (b > a + c) || (c > a + b) || (d >= a + b + c));

    return result;
}
