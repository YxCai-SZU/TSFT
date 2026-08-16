#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == 3 * r * r;
    ensures ((\result) == 3 * (r) * (r));
*/
int64_t func(int64_t r)
{
    int64_t area;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 300 * 100;
    
    area = 3 * r * r;
    
    //@ assert area == 3 * r * r;
    return area;
}
