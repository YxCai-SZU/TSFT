#include <stdint.h>

/*@
    predicate a_in_range(integer a) = -1000 <= a <= 1000;
    
    logic integer func_spec(integer a) = a * a * a + a * a + a + 1;
*/

/*@
    requires a_in_range(a);
    ensures \result == func_spec(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert -1000 <= a && a <= 1000;
    
    //@ assert -1000000000 <= a * a && a * a <= 1000000;
    
    //@ assert -1000000000000 <= a * a * a && a * a * a <= 1000000000000;
    
    result = a * a * a + a * a + a + 1;
    
    //@ assert result == func_spec(a);
    
    return result;
}

int main()
{
    return 0;
}
