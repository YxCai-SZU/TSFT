#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= a <= 500 && 1 <= b <= 500 && 1 <= c <= 1000;
*/

/*@
    requires valid_range(a, b, c);
    ensures \result == (a + b >= c);
*/
bool func(int a, int b, int c) {
    bool result = true;
    int sum = a;
    
    sum += b;
    
    //@ assert sum == a + b;
    
    if (sum < c) {
        result = false;
    }
    
    //@ assert result == (a + b >= c);
    
    return result;
}
