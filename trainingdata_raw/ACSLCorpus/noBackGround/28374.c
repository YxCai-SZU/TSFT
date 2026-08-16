#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == 1 <==> ((n) % 10 == 9 || ((n) / 10) % 10 == 9);
    assigns \nothing;
*/
bool func(int n) {
    int a;
    int b;
    bool result;

    a = n / 10;
    b = n - a * 10;

    if (a == 9 || b == 9) {
        //@ assert a == 9 || b == 9;
        result = true;
    } else {
        //@ assert a != 9 && b != 9;
        result = false;
    }

    return result;
}
