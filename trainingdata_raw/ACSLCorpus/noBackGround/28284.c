#include <stdbool.h>

/*@
    requires 0 <= a <= 50;
    requires 0 <= b <= 50;
    requires 0 <= x <= 50;
    ensures \result <==> ((x) <= (a) && (a) <= (x) + (b));
*/
bool is_possible_to_have_x_cats(int a, int b, int x)
{
    bool result;
    //@ assert ((x) <= (a) && (a) <= (x) + (b)) <==> (x <= a && a <= x + b);
    
    if (x <= a && a <= x + b) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
