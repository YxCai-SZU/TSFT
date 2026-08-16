#include <stdbool.h>

/*@
    requires (1 <= (x) <= 10);
    ensures \result == ((x) * (x) * (x) + (x) * (x) + (x) + 1);
    assigns \nothing;
*/
int func(int x)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert 1 <= x && x <= 10;
    
    //@ assert 1 <= x * x && x * x <= 100;
    
    //@ assert 1 <= x * x * x && x * x * x <= 1000;
    
    result = x * x * x;
    result += x * x;
    result += x;
    result += 1;
    
    //@ assert result == ((x) * (x) * (x) + (x) * (x) + (x) + 1);
    
    return result;
}
