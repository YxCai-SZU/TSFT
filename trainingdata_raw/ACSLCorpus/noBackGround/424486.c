#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a * c < b * d) || (a * c <= b * d && c <= b));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int product1;
    int product2;
    bool result = false;

    //@ assert (1 <= (a) <= 10000) && (1 <= (c) <= 10000);
    //@ assert ((a) * (c)) <= 10000 * 10000;
    product1 = a * c;

    //@ assert (1 <= (b) <= 10000) && (1 <= (d) <= 10000);
    //@ assert ((b) * (d)) <= 10000 * 10000;
    product2 = b * d;

    if (product1 < product2)
    {
        result = true;
    }
    else if (product1 == product2)
    {
        result = (c <= b);
    }

    //@ assert product1 == a * c;
    //@ assert product2 == b * d;
    //@ assert result == ((a * c < b * d) || (a * c <= b * d && c <= b));

    return result;
}
