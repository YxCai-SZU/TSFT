#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 100 &&
     1 <= (x) && (x) <= 10000);
    requires ((n) == (n) &&
     \forall integer i; 0 <= i < (n) ==> 1 <= (ls)[i] && (ls)[i] <= 100);
    requires \valid(ls + (0 .. n-1));
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int x, int *ls) {
    int d = 0;
    int cnt = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= (size_t)n;
        loop invariant 0 <= d <= x + 100;
        loop invariant cnt >= 0;
        loop invariant cnt <= (int)i;
        loop invariant i > 0 ==> \forall integer j; 0 <= j < i ==> 1 <= ls[j] && ls[j] <= 100;
        loop invariant \forall integer k; 0 <= k < n ==> 1 <= ls[k] && ls[k] <= 100;
        loop invariant 1 <= n && n <= 100;
        loop invariant 1 <= x && x <= 10000;
        loop invariant cnt <= n;
        loop assigns d, cnt, i;
        loop variant n - i;
    */
    while (d <= x && i < (size_t)n) {
        //@ assert 0 <= i < (size_t)n;
        d += ls[i];
        
        if (d <= x) {
            cnt += 1;
        }
        
        i += 1;
    }
    
    //@ assert cnt >= 0;
    return cnt;
}
