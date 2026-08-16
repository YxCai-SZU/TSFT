/*@
    predicate bounds(integer x, integer y, integer z) =
        0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10;
    
    logic integer mul_bounds(integer x, integer y) = x * y;
    
    lemma mul_non_overflow:
        \forall integer x, y;
        bounds(x, y, 0) ==> 0 <= mul_bounds(x, y) <= 100;
*/

#include <stdbool.h>


bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at top
    bool result;
    
    //@ assert 0 <= x <= 10;
    //@ assert 0 <= y <= 10;
    //@ assert 0 <= z <= 10;
    
    //@ assert 0 <= x * y <= 100;
    //@ assert 0 <= x * y <= 10 * 10;
    
    result = (x * y >= z);
    
    //@ assert result == (x * y >= z);
    return result;
}

int main()
{
    return 0;
}
