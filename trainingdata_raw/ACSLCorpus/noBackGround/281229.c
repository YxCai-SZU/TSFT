#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (6 * (r));
    assigns \nothing;
*/
int func(int r)
{
    int n;
    int perimeter;
    
    n = 6;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 6 * 1 <= 6 * r && 6 * r <= 6 * 100;
    
    perimeter = n * r;
    
    //@ assert perimeter == r * 6;
    
    return perimeter;
}
