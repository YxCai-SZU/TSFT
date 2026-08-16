#include <stdbool.h>

/*@
    predicate is_seven(integer digit) = digit == 7;

    logic integer has_seven_digit(integer n) =
        (n % 10 == 7) ? 1 : ((n / 10) % 10 == 7) ? 1 : ((n / 100) % 10 == 7) ? 1 : 0;

    lemma mod_lemma:
        \forall integer n; 100 <= n <= 999 ==> (n / 100) % 10 == n / 100;
*/

/*@
    requires 100 <= n <= 999;
    ensures \result == (has_seven_digit(n) == 1);
    assigns \nothing;
*/
bool func(int n)
{
    int n_1;
    int n_2;
    int n_3;
    bool result;

    n_1 = n % 10;
    n_2 = (n / 10) % 10;
    n_3 = (n / 100) % 10;

    //@ assert n_3 == n / 100;

    result = false;

    if (n_1 == 7)
    {
        result = true;
    }

    if (n_2 == 7)
    {
        result = true;
    }

    if (n_3 == 7)
    {
        result = true;
    }

    //@ assert result == (n_1 == 7 || n_2 == 7 || n_3 == 7);

    return result;
}
