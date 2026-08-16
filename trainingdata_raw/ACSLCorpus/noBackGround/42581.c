#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 9);
    requires (1 <= (g) && (g) <= 9);
    requires (1 <= (b) && (b) <= 9);
    ensures \result == ((g * 10 + b) % 4 == 0);
*/
bool func(unsigned int r, unsigned int g, unsigned int b)
{
    // Variable declarations at scope top
    bool result;
    unsigned int combined;

    //@ assert (1 <= (g) && (g) <= 9);
    //@ assert (1 <= (b) && (b) <= 9);
    
    combined = g * 10 + b;
    result = (combined % 4 == 0);
    
    return result;
}
