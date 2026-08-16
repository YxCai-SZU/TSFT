#include <stdbool.h>

/*@
    requires ((money) >= 0 && (money) <= 100000);
    ensures \result == (money >= 1050);
    assigns \nothing;
*/
bool func(int money)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert money >= 0 && money <= 100000;

    result = (money >= 1050);
    return result;
}
