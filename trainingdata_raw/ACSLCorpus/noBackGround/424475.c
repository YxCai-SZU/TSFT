#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 5000 &&
        1 <= (b) && (b) <= 5000 &&
        1 <= (c) && (c) <= 100000);
    ensures \result <==> (a + b >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int ab;
    bool result;

    // Variable declarations at top
    ab = a + b;
    result = false;

    //@ assert ab == ((a) + (b));

    if (ab >= c)
    {
        //@ assert ab >= c;
        result = true;
    }
    else
    {
        //@ assert ab < c;
        result = false;
    }

    return result;
}
