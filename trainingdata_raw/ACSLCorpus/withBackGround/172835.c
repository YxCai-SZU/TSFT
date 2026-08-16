#include <stdbool.h>

/*@
    predicate valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer money_calc(integer k) = k * 500;

    lemma money_bound: \forall integer k; 1 <= k <= 100 ==> money_calc(k) <= 50000;
*/

/*@
    requires valid_params(k, x);
    ensures \result == (money_calc(k) >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at scope top
    unsigned int money;
    bool result;

    //@ assert 500 <= 500;
    //@ assert money_calc(k) <= 50000;

    money = k * 500;

    if (money < x) {
        //@ assert money < x;
        result = false;
    } else {
        //@ assert money >= x;
        result = true;
    }

    return result;
}
