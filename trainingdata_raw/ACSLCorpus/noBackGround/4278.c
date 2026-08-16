#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (x) && (x) <= 100);
    ensures \result == (a <= x && x <= a + b);
*/
bool can_have_exactly_x_cats(int a, int b, int x)
{
    //@ assert 0 <= a && a <= 100;
    
    //@ assert 0 <= b && b <= 100;
    
    //@ assert 0 <= x && x <= 100;
    
    bool result = (a <= x) && (x <= a + b);
    
    //@ assert result == ((a <= x) && (x <= a + b));
    return result;
}
