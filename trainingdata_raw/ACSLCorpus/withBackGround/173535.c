#include <stdbool.h>

/*@
    predicate is_remaining_amount(integer n, integer three_digit_number, integer remaining_amount) =
        remaining_amount == n - (three_digit_number * 500);
*/

/*@
    lemma remaining_amount_calculation:
        \forall integer n, integer three_digit_number, integer remaining_amount;
            three_digit_number == n / 500 && is_remaining_amount(n, three_digit_number, remaining_amount) ==>
            remaining_amount == n % 500;
*/

/*@
    requires 1 <= n && n <= 10000;
    requires 0 <= a && a <= 1000;
    ensures \result == ((n % 500) <= a);
*/
bool func(unsigned int n, unsigned int a)
{
    unsigned int three_digit_number;
    unsigned int remaining_amount;
    bool result;

    three_digit_number = n / 500;
    remaining_amount = n - (three_digit_number * 500);

    //@ assert is_remaining_amount(n, three_digit_number, remaining_amount);
    //@ assert remaining_amount == n % 500;

    result = remaining_amount <= a;
    return result;
}
