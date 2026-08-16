#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int ans;
    int result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert a - b * 2 <= 98;

    ans = a - b * 2;
    
    if (ans < 0) {
        result = 0;
    } else {
        result = ans;
    }

    //@ assert result >= 0;
    //@ assert result == a - b * 2 || result == 0;
    
    return result;
}
