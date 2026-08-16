#include <stdint.h>

/*@
    requires ((((a)) >= 0) && (((b)) >= 0) && (((c)) >= 0) &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= k;
    ensures \result == ((k) <= (a) ? (k) : ((k) <= (a) + (b) ? (a) : (a) - ((k) - (a) - (b))));
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t result = 0;
    int32_t remaining_cards = k;

    //@ assert ((result) >= 0);
    //@ assert ((remaining_cards) >= 0);

    if (a >= remaining_cards)
    {
        result += remaining_cards;
        //@ assert result == ((k) <= (a) ? (k) : ((k) <= (a) + (b) ? (a) : (a) - ((k) - (a) - (b))));
        return result;
    }
    else
    {
        remaining_cards -= a;
        result += a;
    }

    //@ assert ((remaining_cards) >= 0);
    //@ assert result == a;

    if (b >= remaining_cards)
    {
        //@ assert result == ((k) <= (a) ? (k) : ((k) <= (a) + (b) ? (a) : (a) - ((k) - (a) - (b))));
        return result;
    }
    else
    {
        remaining_cards -= b;
    }

    //@ assert ((result) >= 0);
    //@ assert ((remaining_cards) >= 0);
    result -= remaining_cards;

    //@ assert result == ((k) <= (a) ? (k) : ((k) <= (a) + (b) ? (a) : (a) - ((k) - (a) - (b))));
    return result;
}
