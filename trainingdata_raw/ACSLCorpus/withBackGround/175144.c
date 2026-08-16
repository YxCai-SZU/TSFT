#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer compute_change(integer n) =
        n % 1000 == 0 ? 0 : 1000 - (n % 1000);

    lemma change_properties:
        \forall integer n;
            is_valid_n(n) ==>
            (
                compute_change(n) < 1000 &&
                (compute_change(n) == 0 ==> n % 1000 == 0) &&
                (compute_change(n) > 0 ==> 
                    n % 1000 != 0 &&
                    n + compute_change(n) == ((n + compute_change(n)) / 1000) * 1000)
            );
*/

/*@
    requires is_valid_n(n);
    ensures \result < 1000;
    ensures \result == 0 ==> n % 1000 == 0;
    ensures \result > 0 ==> n % 1000 != 0 && n + \result == ((n + \result) / 1000) * 1000;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t change;
    size_t num;
    size_t remain;

    num = n / 1000;
    remain = n % 1000;

    if (remain == 0)
    {
        change = 0;
        //@ assert change == 0 ==> n % 1000 == 0;
    }
    else
    {
        //@ assert n % 1000 != 0;
        //@ assert n + 1000 - remain == ((n + 1000 - remain) / 1000) * 1000;
        change = 1000 - remain;
    }

    //@ assert change < 1000;
    return change;
}
