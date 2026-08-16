#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9);
    requires (1 <= (g) <= 9);
    requires (1 <= (b) <= 9);
    ensures \result == ((100 * (r) + 10 * (g) + (b)) % 4 == 0);
*/
bool func(unsigned int r, unsigned int g, unsigned int b) {
    // Variable declarations at top of scope
    unsigned int value;
    bool result;

    //@ assert (1 <= (r) <= 9);
    //@ assert (1 <= (g) <= 9);
    //@ assert (1 <= (b) <= 9);

    value = 100 * r + 10 * g + b;
    result = (value % 4 == 0);
    
    return result;
}
