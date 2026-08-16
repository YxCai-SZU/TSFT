#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == true <==> (n % 100) * 21 / 100 == n / 100;
    assigns \nothing;
*/
bool func(unsigned int n)
{
    // Variable declarations at scope top
    unsigned int x;
    unsigned int y;
    bool result;

    //@ assert 1 <= n && n <= 100000;
    
    //@ assert 0 <= n % 100 && n % 100 <= 100;
    //@ assert (n % 100) * 21 <= 2100;
    //@ assert (n % 100) * 21 / 100 <= 21;

    x = (n % 100) * 21 / 100;
    y = n / 100;

    if (x == y) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
