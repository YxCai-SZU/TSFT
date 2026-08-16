#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == true <==> ((((a)) * 3) >= (b) && ((((a)) * 3) - (b)) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int d;
    bool result;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);

    if (a * 3 < b) {
        //@ assert !((((a)) * 3) >= (b) && ((((a)) * 3) - (b)) % 2 == 0);
        return false;
    }

    d = a * 3 - b;

    if (d % 2 != 0) {
        //@ assert !((((a)) * 3) >= (b) && ((((a)) * 3) - (b)) % 2 == 0);
        return false;
    }

    //@ assert ((((a)) * 3) >= (b) && ((((a)) * 3) - (b)) % 2 == 0);
    return true;
}
