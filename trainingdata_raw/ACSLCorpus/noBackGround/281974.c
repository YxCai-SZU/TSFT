#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 7 &&
        1 <= (b) && (b) <= 7 &&
        1 <= (c) && (c) <= 7 &&
        1 <= (k) && (k) <= 7);
    ensures \result == true <==> ((((a)) + ((b)) + ((c))) >= (k));
*/
bool func(long a, long b, long c, long k)
{
    long k_remaining;
    long a_cards;
    long b_cards;
    long c_cards;

    k_remaining = k;

    //@ assert k_remaining == k;

    if (k_remaining < a)
    {
        a_cards = k_remaining;
    }
    else
    {
        a_cards = a;
    }
    k_remaining = k_remaining - a_cards;

    //@ assert a_cards >= 0 && a_cards <= a;

    if (k_remaining < b)
    {
        b_cards = k_remaining;
    }
    else
    {
        b_cards = b;
    }
    k_remaining = k_remaining - b_cards;

    //@ assert b_cards >= 0 && b_cards <= b;

    if (k_remaining < c)
    {
        c_cards = k_remaining;
    }
    else
    {
        c_cards = c;
    }
    k_remaining = k_remaining - c_cards;

    //@ assert c_cards >= 0 && c_cards <= c;

    //@ assert k_remaining <= 0 <==> ((((a)) + ((b)) + ((c))) >= (k));

    return k_remaining <= 0;
}
