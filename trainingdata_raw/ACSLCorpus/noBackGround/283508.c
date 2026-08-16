#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 100 &&
        1 <= (H) && (H) <= 100000);
    ensures \result >= 0 && \result <= N;
*/
int func(int N, int H)
{
    int h = 0;
    int ans = 0;
    int i = 1;

    /*@
        loop invariant 1 <= i && i <= N + 1;
        loop invariant h >= 0 && h <= (100 * (i - 1));
        loop invariant ans >= 0 && ans <= i - 1;
        loop assigns h, ans, i;
    */
    while (i <= N) {
        int old_h = h;
        int old_ans = ans;
        int old_i = i;
        
        h += 100;
        //@ assert h == old_h + 100;
        if (h <= H) {
            ans += 1;
            //@ assert ans == old_ans + 1;
        }
        i += 1;
        //@ assert i == old_i + 1;
    }
    //@ assert ans >= 0 && ans <= N;
    return ans;
}
