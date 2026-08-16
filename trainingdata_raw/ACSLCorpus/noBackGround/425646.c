#include <stdbool.h>

/*@
    requires 0 <= a <= 100 && 0 <= b <= 100;
    ensures \result == (a > b || a == b || a < b);
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top
    bool result;
    
    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    
    //@ assert a >= b || b >= a;
    
    result = a > b || a == b || a < b;
    return result;
}

int main()
{
    return 0;
}
