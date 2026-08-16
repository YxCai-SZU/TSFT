#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result <==> ((a) <= (x) && (a) + (b) >= (x));
*/
bool is_possible_x_cats(int a, int b, int x)
{
    bool result;
    //@ assert 0 <= a <= 100 && 0 <= b <= 100 && 0 <= x <= 100;
    
    if (a <= x && (a + b >= x)) {
        //@ assert ((a) <= (x) && (a) + (b) >= (x));
        result = true;
    } else {
        //@ assert !((a) <= (x) && (a) + (b) >= (x));
        result = false;
    }
    
    return result;
}
