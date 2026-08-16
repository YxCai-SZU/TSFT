#include <limits.h>
#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (a == b + c || a + b == c || a + c == b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int aa;
    int bb;
    int cc;
    int temp;

    aa = a;
    bb = b;
    cc = c;

    // Sorting the three integers
    if (aa > bb)
    {
        temp = aa;
        aa = bb;
        bb = temp;
    }
    //@ assert aa <= bb;
    if (bb > cc)
    {
        temp = bb;
        bb = cc;
        cc = temp;
    }
    //@ assert bb <= cc;
    if (aa > bb)
    {
        temp = aa;
        aa = bb;
        bb = temp;
    }
    //@ assert ((aa) <= (bb) && (bb) <= (cc));

    // Ensuring no overflow/underflow for the addition operations
    //@ assert aa <= INT_MAX - bb;
    //@ assert aa <= INT_MAX - cc;
    //@ assert bb <= INT_MAX - cc;

    //@ assert aa >= INT_MIN - bb;
    //@ assert aa >= INT_MIN - cc;
    //@ assert bb >= INT_MIN - cc;

    // The only possible combination left is aa + bb == cc
    //@ assert aa + bb == cc ==> (a == b + c || a + b == c || a + c == b);
    return aa + bb == cc;
}
