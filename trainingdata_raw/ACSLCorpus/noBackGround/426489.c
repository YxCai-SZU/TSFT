#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures 1 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *p) {
    int ans = 1;
    int min_val = p[0];
    int index = 1;
    
    /*@
        loop invariant 1 <= index <= n;
        loop invariant 1 <= ans <= index;
        loop invariant 1 <= min_val <= n;
        loop invariant \forall integer i; 0 <= i < index ==> 1 <= p[i] <= n;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop assigns ans, min_val, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (p[index] <= min_val) {
            ans += 1;
            min_val = p[index];
        }
        //@ assert 1 <= ans <= index + 1;
        //@ assert 1 <= min_val <= n;
        index += 1;
    }
    return ans;
}
