#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (k) <= 100);
    ensures ((\result) == ((a) % (k) == 0));
*/
bool can_distribute_equally(unsigned int k, unsigned int a)
{
    bool result;
    
    //@ assert 1 <= a <= 100 && 1 <= k <= 100;
    result = (a % k == 0);
    //@ assert result == (a % k == 0);
    
    return result;
}
