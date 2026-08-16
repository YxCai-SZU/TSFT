#include <stdbool.h>

/*@
    requires (0 < (a) <= 10);
    requires (0 < (b) <= 10);
    requires (0 < (c) <= 10);
    ensures \result == true <==> (a * b) * c <= 1000;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int ab;
    unsigned int abc;

    //@ assert 0 < a && a <= 10;
    //@ assert 0 < b && b <= 10;
    //@ assert 0 < c && c <= 10;

    ab = a * b;
    //@ assert ab <= 100;

    abc = ab * c;
    //@ assert abc <= 1000;

    result = abc <= 1000;
    return result;
}
