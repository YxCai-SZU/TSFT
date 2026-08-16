#include <stddef.h>
#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        (n) == (n) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (ls)[i] && (ls)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *ls) {
    int d = 0;
    int cnt = 1;
    int index = 0;
    
    /*@
        loop invariant (0 <= (index) <= (n) &&
        1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        (n) == (n) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (ls)[i] && (ls)[i] <= 100 &&
        (d) <= (index) * 100 &&
        (d) >= 0 &&
        (cnt) >= 1 &&
        (cnt) <= (index) + 1);
        loop assigns d, cnt, index;
        loop variant n - index;
    */
    while (index < n) {
        int l = ls[index];
        d += l;
        
        //@ assert d >= 0;
        
        if (d > x) {
            break;
        }
        cnt += 1;
        index += 1;
    }
    return cnt;
}
