#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int c_result;
    int ans;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    result = a - b;
    c_result = result - c;
    
    if (c_result > 0) {
        ans = c_result;
    } else {
        ans = 0;
    }
    
    //@ assert ans == (((a) - (b) - (c) > 0) ? (a) - (b) - (c) : 0);
    //@ assert ans >= 0;
    //@ assert ans <= a;
    
    return ans;
}
