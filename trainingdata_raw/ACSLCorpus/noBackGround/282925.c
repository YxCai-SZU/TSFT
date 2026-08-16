#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10 && 1 <= (b) <= 10);
    ensures \result == true <==> a * b >= 12;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product_val;

    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= b && b <= 10;

    product_val = a * b;
    //@ assert product_val <= 100;

    if (product_val >= 12) {
        //@ assert product_val >= 12;
        result = true;
    } else {
        //@ assert product_val < 12;
        result = false;
    }

    return result;
}
