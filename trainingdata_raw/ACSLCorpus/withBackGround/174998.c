#include <stdbool.h>

/*@
    predicate is_palindrome_candidate(integer n) =
        100 <= n && n <= 999;

    logic integer digit_hundred(integer n) = n / 100;
    logic integer digit_units(integer n) = n % 10;

    lemma digit_lemma:
        \forall integer n;
            is_palindrome_candidate(n) ==>
            digit_hundred(n) == (n / 100) &&
            digit_units(n) == (n % 10);
*/

/*@
    requires is_palindrome_candidate(n);
    ensures \result == (digit_hundred(n) == digit_units(n));
    assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int a0;
    unsigned int a1;
    unsigned int a2;
    bool result;

    a0 = n / 100;
    a1 = (n / 10) % 10;
    a2 = n % 10;

    //@ assert a0 == digit_hundred(n);
    //@ assert a1 == (n / 10) % 10;
    //@ assert a2 == digit_units(n);

    result = (a0 == a2);
    return result;
}
