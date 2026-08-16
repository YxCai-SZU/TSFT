#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == true <==> (a * 100 + b) <= 10000;
    assigns \nothing;
*/
bool check_bounds(unsigned int a, unsigned int b)
{
    unsigned int product;
    bool result;

    product = a * 100;

    //@ assert product == ((a) * 100);
    //@ assert 100 <= product <= 10000;

    result = (product + b) <= 10000;
    return result;
}
