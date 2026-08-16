#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (x) <= 200);
    ensures ((\result) == ((a) <= (x) && (a) + (b) >= (x)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at scope top
    unsigned int sum;
    bool result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (x) <= 200);
    //@ assert ((a) + (b) <= 200);

    sum = a + b;

    if (x < a || sum < x) {
        result = false;
    } else {
        //@ assert a <= x && a + b >= x;
        result = true;
    }

    //@ assert ((result) == ((a) <= (x) && (a) + (b) >= (x)));
    return result;
}
