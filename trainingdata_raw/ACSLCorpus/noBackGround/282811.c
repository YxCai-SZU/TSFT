#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    requires (1 <= (d) <= 100);
    ensures \result == (((a) * (c)) <= ((b) * (d)) || ((a) * (d)) <= ((b) * (c)));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int product1;
    int product2;
    int product3;
    int product4;
    bool result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);

    //@ assert ((a) * (c)) <= 10000;
    product1 = a * c;

    //@ assert ((b) * (d)) <= 10000;
    product2 = b * d;

    //@ assert ((a) * (d)) <= 10000;
    product3 = a * d;

    //@ assert ((b) * (c)) <= 10000;
    product4 = b * c;

    result = (product1 <= product2) || (product3 <= product4);
    return result;
}
