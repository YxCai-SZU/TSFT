#include <stdbool.h>

/*@
    requires (1 <= (v0) <= 100 &&
        1 <= (v1) <= 20 &&
        1 <= (v2) <= 2000);
    ensures \result >= 0;
    ensures \result <= v1 * v2;
    assigns \nothing;
*/
int func(int v0, int v1, int v2)
{
    //@ assert v1 <= 20;
    //@ assert v2 <= 2000;
    //@ assert v1 * v2 <= 40000;

    int x = v1 * v2;
    int ans;
    
    if (x < v0) {
        ans = x;
    } else {
        ans = v0;
    }
    
    return ans;
}
