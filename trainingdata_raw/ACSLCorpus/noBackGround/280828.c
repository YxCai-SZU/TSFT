#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= x && x <= 100;
    ensures \result <==> ((x) >= (a) && (x) <= (a) + (b));
 */
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= x && x <= 100;

    if (x < a) {
        //@ assert x < a;
        result = false;
        return result;
    }

    if (x > a + b) {
        //@ assert x > a + b;
        result = false;
        return result;
    }

    //@ assert ((x) >= (a) && (x) <= (a) + (b));
    result = true;
    return result;
}
