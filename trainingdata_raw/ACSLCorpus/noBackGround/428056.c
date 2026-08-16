#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int c;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    //@ assert 1 * 1 <= ((a) * (b)) <= 100 * 100;
    
    c = a * b;
    
    //@ assert c == ((a) * (b));
    
    return c;
}
