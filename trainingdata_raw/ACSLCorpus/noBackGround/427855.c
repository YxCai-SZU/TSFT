#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == (n >= 30 && (n % 10 == 0 || n % 10 == 5 || n % 10 == 3));
    assigns \nothing;
*/
bool func(int n)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= n <= 100;
    //@ assert n >= 0;
    //@ assert 0 <= n % 10 <= 9;
    //@ assert 0 <= n / 10 <= 10;

    if (n < 30) {
        result = false;
    } else {
        result = (n % 10 == 0) || (n % 10 == 5) || (n % 10 == 3);
    }

    return result;
}
