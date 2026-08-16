#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (a < b && b < c);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool is_valid;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    is_valid = false;
    
    if (a < b && b < c) {
        is_valid = true;
    }
    
    return is_valid;
}

int main()
{
    return 0;
}
