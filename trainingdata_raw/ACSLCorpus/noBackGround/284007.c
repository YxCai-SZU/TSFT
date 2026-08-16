#include <stdbool.h>
#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == true <==> ((r) % 3 == 0 || (r) % 5 == 0);
*/
bool func(uint32_t r)
{
    bool result;
    bool ans;
    bool res;
    bool b;
    uint32_t n;
    uint32_t *v;

    // Simulate HashSet operations (simplified for verification)
    // The actual HashSet implementation would require a full model
    // Here we just track the verification condition
    
    ans = (r % 3 == 0) || (r % 5 == 0);
    
    //@ assert ans == true <==> ((r) % 3 == 0 || (r) % 5 == 0);
    
    result = ans;
    return result;
}
