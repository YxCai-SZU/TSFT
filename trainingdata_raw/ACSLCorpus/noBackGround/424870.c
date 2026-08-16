#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == ((10 * (g) + (b)) % 4 == 0);
*/
bool func(unsigned int r, unsigned int g, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int computed;
    bool result;

    //@ assert (1 <= (g) <= 9) && (1 <= (b) <= 9);
    computed = 10 * g + b;
    //@ assert computed == (10 * (g) + (b));
    
    //@ assert computed <= 99;
    if (computed % 4 == 0) {
        //@ assert computed % 4 == 0;
        result = true;
    } else {
        //@ assert computed % 4 != 0;
        result = false;
    }
    
    //@ assert result == (computed % 4 == 0);
    return result;
}
