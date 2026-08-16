#include <stdbool.h>

/*@
    requires 1 <= a <= 1000000000;
    requires 1 <= b <= 1000000000;
    requires 1 <= c <= 1000000000;
    ensures \result == (b - a == c || a - b == c || (a == b && c == 0));
*/
bool func(long long a, long long b, long long c)
{
    long long diff;
    bool result;

    //@ assert 1 <= a <= 1000000000;
    //@ assert 1 <= b <= 1000000000;
    //@ assert 1 <= c <= 1000000000;

    if (a > b) {
        diff = a - b;
    } else {
        diff = b - a;
    }

    //@ assert ((diff) == ((a) > (b) ? (a) - (b) : (b) - (a)));

    if (diff == c) {
        //@ assert diff == c;
        result = true;
    } else if (a == b && c == 0) {
        //@ assert a == b && c == 0;
        result = true;
    } else {
        //@ assert diff != c && !(a == b && c == 0);
        result = false;
    }

    //@ assert result == (b - a == c || a - b == c || (a == b && c == 0));
    return result;
}
