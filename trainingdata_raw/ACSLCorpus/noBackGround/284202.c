#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10 && 1 <= (b) <= 10 && 1 <= (c) <= 10);
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    int ans;
    int ans2;
    bool result;
    
    ans = b - a;
    ans2 = c - b;
    
    //@ assert ans == b - a;
    //@ assert ans2 == c - b;
    
    result = (ans == ans2);
    //@ assert result == (b - a == c - b);
    
    return result;
}
