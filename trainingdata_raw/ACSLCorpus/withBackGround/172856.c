#include <stdbool.h>

/*@
    predicate is_three_digit(integer n) = 100 <= n && n <= 999;

    logic integer first_digit(integer n) = n / 100;
    logic integer last_digit(integer n) = n % 10;

    lemma digit_equivalence:
        \forall integer n;
            is_three_digit(n) ==> (first_digit(n) == last_digit(n)) == ((n / 100) == (n % 10));
*/

/*@
    requires is_three_digit(n);
    ensures \result == (first_digit(n) == last_digit(n));
    assigns \nothing;
*/
bool func(int n)
{
    unsigned int n_unsigned;
    unsigned int first_digit;
    unsigned int last_digit;
    bool result;

    n_unsigned = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;
    first_digit = n_unsigned / 100;
    last_digit = n_unsigned % 10;

    //@ assert first_digit == (unsigned int)(n / 100);
    //@ assert last_digit == (unsigned int)(n % 10);

    result = (first_digit == last_digit);
    return result;
}
