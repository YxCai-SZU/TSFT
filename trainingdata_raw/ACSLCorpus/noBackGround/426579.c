#include <stdbool.h>

/*@
    requires (\valid((a)) && \valid((a)+1) && \valid((a)+2) &&
        (a)[0] >= 0 && (a)[0] <= 100 &&
        (a)[1] >= 0 && (a)[1] <= 100 &&
        (a)[2] >= 0 && (a)[2] <= 100);
    ensures \result <==> ((((a[0])) + ((a[1]))) == (a[2]) || (((a[1])) + ((a[2]))) == (a[0]) || (((a[2])) + ((a[0]))) == (a[1]));
    assigns \nothing;
*/
bool func(unsigned long long *a)
{
    bool result = false;
    unsigned long long a0 = a[0];
    unsigned long long a1 = a[1];
    unsigned long long a2 = a[2];

    //@ assert a0 + a1 <= 200;
    //@ assert a1 + a2 <= 200;
    //@ assert a2 + a0 <= 200;
    //@ assert a0 + a1 >= 0;
    //@ assert a1 + a2 >= 0;
    //@ assert a2 + a0 >= 0;

    if (a0 + a1 == a2) {
        result = true;
    } else if (a1 + a2 == a0) {
        result = true;
    } else if (a2 + a0 == a1) {
        result = true;
    }
    return result;
}
