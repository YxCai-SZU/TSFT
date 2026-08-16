#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    ensures \result == (a <= b);
    ensures ((\result) == ((a) <= (b)));
*/
bool func(int a, int b)
{
    int c;
    bool is_le;
    
    c = a - b;
    is_le = (c <= 0);
    
    //@ assert is_le == (a <= b);
    
    return is_le;
}
