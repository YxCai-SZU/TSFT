#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) >= 1);
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int k_mut;
    int counter;

    k_mut = k;
    counter = 0;

    if (k_mut < a)
    {
        counter = k_mut;
    }
    else
    {
        counter = a;
    }

    k_mut = k_mut - a;

    if (k_mut > 0 && b >= k_mut)
    {
        k_mut = k_mut - b;
    }
    else
    {
        k_mut = 0;
    }

    if (k_mut > 0 && c >= k_mut)
    {
        counter = counter - k_mut;
    }

    //@ assert counter >= -c;
    return counter;
}
