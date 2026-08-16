#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) + (b) + (c));
    ensures \result == ((a) + (b) + (c)) || 
            \result == ((b) + (c)) || 
            \result == ((a) + (c)) || 
            \result == ((a) + (b));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max = a;
    int ans;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    if (max == a) {
        ans = b + c;
    } else if (max == b) {
        ans = a + c;
    } else {
        ans = a + b;
    }

    //@ assert ans >= 0;
    //@ assert ans <= a + b + c;
    //@ assert ans == a + b + c || ans == b + c || ans == a + c || ans == a + b;

    return ans;
}
