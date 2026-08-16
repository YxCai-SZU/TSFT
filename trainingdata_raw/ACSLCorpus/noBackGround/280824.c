#include <stdbool.h>

/*@
    requires 1 <= X && X <= 100000;
    ensures \result == true <==> (((X) % 100) * 21 >= (X));
    assigns \nothing;
*/
bool func(int X)
{
    bool ans;
    //@ assert 1 <= X && X <= 100000;
    
    if ((X % 100) * 21 >= X) {
        ans = true;
    } else {
        ans = false;
    }
    
    //@ assert ans == true <==> (((X) % 100) * 21 >= (X));
    return ans;
}
