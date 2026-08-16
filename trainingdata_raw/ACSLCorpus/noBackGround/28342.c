#include <stdbool.h>

/*@
    requires (1 <= (a) <= 13) && (1 <= (b) <= 13) && (1 <= (c) <= 13);
    ensures \result == (a + b + c <= 21);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= a && a <= 13;
    //@ assert 1 <= b && b <= 13;
    //@ assert 1 <= c && c <= 13;
    //@ assert a + b <= 26;
    //@ assert a + b + c <= 39;

    if (a + b + c <= 21) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
