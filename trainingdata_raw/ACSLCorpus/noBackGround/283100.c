#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (c) <= 100 &&
        1 <= (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) >= 1);
    ensures \result >= -1 * (int)c;
    ensures \result <= (int)a;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    int32_t ans = 0;
    uint32_t remaining_k = k;
    uint32_t a_cards_to_use;
    uint32_t b_cards_to_use;
    uint32_t c_cards_to_use;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (c) <= 100 &&         1 <= (k) <= (a) + (b) + (c) &&         (a) + (b) + (c) >= 1);

    // Use all the A cards we have or K cards we have, which is smaller?
    if (a < remaining_k) {
        a_cards_to_use = a;
    } else {
        a_cards_to_use = remaining_k;
    }
    ans += (int32_t)a_cards_to_use;
    remaining_k -= a_cards_to_use;

    //@ assert ans >= -1 * (int32_t)c && ans <= (int32_t)a;

    // If there are still K cards left, we need to use some B cards to cancel them out
    if (remaining_k < b) {
        b_cards_to_use = remaining_k;
    } else {
        b_cards_to_use = b;
    }
    remaining_k -= b_cards_to_use;

    //@ assert ans >= -1 * (int32_t)c && ans <= (int32_t)a;

    // If there are still K cards left, we need to use some C cards to cancel them out
    if (remaining_k < c) {
        c_cards_to_use = remaining_k;
    } else {
        c_cards_to_use = c;
    }
    ans -= (int32_t)c_cards_to_use;

    //@ assert ans >= -1 * (int32_t)c;
    //@ assert ans <= (int32_t)a;

    return ans;
}
