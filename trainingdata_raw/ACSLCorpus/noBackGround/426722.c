#include <stdbool.h>

/*@
    requires 1 <= a && a <= 9;
    requires 1 <= b && b <= 9;
    requires 1 <= c && c <= 9;
    ensures \result == true <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
 */
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    bool result;
    
    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;
    
    if ((a < b && b < c) || (a > b && b > c)) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
