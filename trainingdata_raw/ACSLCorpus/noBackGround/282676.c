#include <stdbool.h>

/*@
    requires (100 <= (a) && (a) <= 999);
    ensures \result == (((a) / 100) == ((a) % 10));
    assigns \nothing;
*/
bool func(unsigned int a)
{
    bool result = false;
    unsigned int a_mut = a;
    unsigned int hundreds = 0;
    unsigned int tens = 0;
    unsigned int ones = 0;

    //@ assert (100 <= (a) && (a) <= 999);
    /*@
        loop invariant 100 <= a && a <= 999;
        loop invariant a_mut >= 0;
        loop invariant hundreds >= 0;
        loop invariant a == a_mut + hundreds * 100;
        loop assigns a_mut, hundreds;
        loop variant a_mut;
    */
    while (a_mut >= 100)
    {
        a_mut -= 100;
        hundreds += 1;
    }

    //@ assert a == a_mut + hundreds * 100;
    /*@
        loop invariant 100 <= a && a <= 999;
        loop invariant a_mut >= 0;
        loop invariant hundreds >= 0;
        loop invariant tens >= 0;
        loop invariant a == a_mut + hundreds * 100 + tens * 10;
        loop assigns a_mut, tens;
        loop variant a_mut;
    */
    while (a_mut >= 10)
    {
        a_mut -= 10;
        tens += 1;
    }
    ones = a_mut;

    //@ assert a == hundreds * 100 + tens * 10 + ones;
    if (hundreds == ones)
    {
        result = true;
    }

    //@ assert result == (hundreds == ones);
    return result;
}
