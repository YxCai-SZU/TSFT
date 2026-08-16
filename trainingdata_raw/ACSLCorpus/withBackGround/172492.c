#include <stdbool.h>

/*@
    predicate is_even_sum(integer a, integer b, bool result) =
        result == ((a + b) % 2 == 0);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ((a + b) % 2 == 0);
    ensures is_even_sum(a, b, \result);
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int c;
    bool is_even;
    unsigned int temp_c;

    c = a + b;
    temp_c = c;

    /*@
        loop invariant 0 <= temp_c <= a + b;
        loop invariant temp_c % 2 == c % 2;
        loop assigns temp_c;
    */
    while (temp_c >= 2)
    {
        //@ assert temp_c % 2 == c % 2;
        temp_c -= 2;
    }

    //@ assert temp_c % 2 == c % 2;
    is_even = (temp_c == 0);
    //@ assert is_even == (c % 2 == 0);
    return is_even;
}
