#include <stdint.h>

/*@
    requires (0 <= (r) <= 4500 &&
        0 <= (g) <= 4500 &&
        (r) < (g));
    ensures \result == ((g) * 2 - (r)) && (0 <= (\result) <= 9000);
*/
int64_t func(int64_t r, int64_t g)
{
    // Variable declarations at scope top
    int64_t performance;

    //@ assert 0 <= r <= 4500;
    //@ assert 0 <= g <= 4500;
    //@ assert r < g;
    //@ assert g * 2 - r <= 9000;
    
    performance = g * 2 - r;
    
    //@ assert performance == ((g) * 2 - (r));
    //@ assert (0 <= (performance) <= 9000);
    
    return performance;
}
