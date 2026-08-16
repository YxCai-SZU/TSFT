#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 20 && 1 <= (m) && (m) <= 20);
    ensures \result == ((n) * (m) == 1 ? 0 : (n) * (m) - 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at top of scope
    int product;
    int result;

    // Precondition verification
    //@ assert (1 <= (n) && (n) <= 20 && 1 <= (m) && (m) <= 20);
    
    // Arithmetic bounds verification
    //@ assert n * m <= 400;

    product = n * m;
    result = 0;

    if (product == 1) {
        result = 0;
    } else {
        result = product - 1;
    }

    // Postcondition verification
    //@ assert result == ((n) * (m) == 1 ? 0 : (n) * (m) - 1);
    
    return result;
}
