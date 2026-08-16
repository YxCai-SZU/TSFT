#include <stdbool.h>

/*@
    predicate is_mod4(integer x) = x % 4 == 0;
*/

/*@
    requires 1 <= r <= 9;
    requires 1 <= g <= 9;
    requires 1 <= b <= 9;
    ensures \result == ((g * 10 + b) % 4 == 0) || 
                      ((r * 10 + g) % 4 == 0) || 
                      ((b * 10 + r) % 4 == 0);
*/
bool func(int r, int g, int b) {
    int a;
    int b_val;
    int c;
    
    a = r * 10 + g;
    b_val = g * 10 + b;
    c = b * 10 + r;
    
    //@ assert a == r * 10 + g;
    //@ assert b_val == g * 10 + b;
    //@ assert c == b * 10 + r;
    
    return (a % 4 == 0) || (b_val % 4 == 0) || (c % 4 == 0);
}
