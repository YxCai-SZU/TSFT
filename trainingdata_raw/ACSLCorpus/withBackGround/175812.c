#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 &&
        k >= 1 &&
        k <= a + b + c &&
        a + b + c <= 2000000000;

    predicate result_bounds(integer result, integer k) =
        result <= k;
*/

/*@
    requires valid_input(a, b, c, k);
    ensures result_bounds(\result, k);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t total = 0;
    int32_t k_remaining = k;
    int32_t a_cards = a;
    int32_t b_cards = b;
    int32_t c_cards = c;

    // Calculate the total points for 'a' cards
    //@ assert k_remaining >= 0;
    if (k_remaining >= a_cards)
    {
        total += a_cards;
        k_remaining -= a_cards;
    }
    else
    {
        total += k_remaining;
        k_remaining = 0;
    }

    // Convert 'b' cards to 'a' cards
    //@ assert k_remaining >= 0;
    if (k_remaining >= b_cards)
    {
        k_remaining -= b_cards;
    }
    else
    {
        b_cards = k_remaining;
        k_remaining = 0;
    }

    // Calculate the total points for 'c' cards
    //@ assert k_remaining >= 0;
    if (k_remaining >= c_cards)
    {
        total -= c_cards;
        k_remaining -= c_cards;
    }
    else
    {
        total -= k_remaining;
        k_remaining = 0;
    }

    //@ assert total <= k;
    return total;
}
