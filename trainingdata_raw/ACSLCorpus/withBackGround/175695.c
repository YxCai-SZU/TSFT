#include <stdbool.h>

/*@
    predicate is_three_digit(integer n) = 100 <= n && n <= 999;

    logic integer hundreds_digit(integer n) = n / 100;
    logic integer ones_digit(integer n) = n % 10;

    lemma digit_division:
        \forall integer n;
            is_three_digit(n) ==> hundreds_digit(n) == ones_digit(n) ==>
                (n / 100) == (n % 10);
*/

/*@
    requires is_three_digit(n);
    ensures \result == (hundreds_digit(n) == ones_digit(n));
    ensures \result == ((n / 100) == (n % 10));
*/
bool func(int n)
{
    unsigned int n_unsigned;
    unsigned int a0;
    unsigned int a1;
    unsigned int a2;
    bool result;

    //@ assert is_three_digit(n);
    
    if (n < 0) {
        n_unsigned = (unsigned int)(-n);
    } else {
        n_unsigned = (unsigned int)n;
    }

    a0 = n_unsigned / 100;
    a1 = (n_unsigned / 10) % 10;
    a2 = n_unsigned % 10;

    //@ assert a0 == n_unsigned / 100;
    //@ assert a1 == (n_unsigned / 10) % 10;
    //@ assert a2 == n_unsigned % 10;

    result = (a0 == a2);
    return result;
}
