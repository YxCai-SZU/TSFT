#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (x) && (x) <= 200);
    ensures ((\result) == true <==> ((a) <= (x) && (x) - (a) < (b) + 1));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;
    unsigned int remaining;

    // Variable declarations at top
    result = false;
    remaining = 0;

    if (x < a) {
        result = false;
        //@ assert result == false;
    } else if (x - a < b + 1) {
        result = true;
        //@ assert result == true;
    } else {
        remaining = x - a;
        //@ assert remaining == x - a;
        
        if (remaining < b + 1) {
            result = true;
            //@ assert result == true;
        } else {
            //@ assert remaining >= b + 1;
            result = false;
            //@ assert result == false;
        }
    }

    return result;
}
