#include <stdbool.h>

/*@
    predicate in_range(integer x) = 400 <= x && x < 2000;
    predicate result_range(integer r) = 0 <= r && r <= 8;
*/

/*@
    requires in_range(x);
    ensures result_range(\result);
    assigns \nothing;
*/
int func(int x)
{
    int result = 8;
    
    //@ assert result_range(result);
    
    if (x >= 2000) {
        result -= 1;
    }
    //@ assert result_range(result);
    
    if (x >= 1600) {
        result -= 1;
    }
    //@ assert result_range(result);
    
    if (x >= 1200) {
        result -= 1;
    }
    //@ assert result_range(result);
    
    if (x >= 1000) {
        result -= 1;
    }
    //@ assert result_range(result);
    
    if (x >= 800) {
        result -= 1;
    }
    //@ assert result_range(result);
    
    if (x >= 600) {
        result -= 1;
    }
    //@ assert result_range(result);
    
    if (x >= 400) {
        result -= 1;
    }
    //@ assert result_range(result);
    
    if (x >= 200) {
        result -= 1;
    }
    //@ assert result_range(result);
    
    return result;
}
