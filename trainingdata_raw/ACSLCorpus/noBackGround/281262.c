#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 20);
    requires \valid(v + (0..n-1)) && \valid(c + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] && (v)[i] <= 50);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (c)[i] && (c)[i] <= 50);
    ensures \result >= 0;
*/
int func(int n, int *v, int *c) {
    int sum = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ((sum) >= 0 && (sum) <= (i) * 50);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (v)[k] - (c)[k] <= 50);
        loop assigns sum, i;
    */
    while (i < n) {
        //@ assert 1 <= v[i] && v[i] <= 50;
        //@ assert 1 <= c[i] && c[i] <= 50;
        
        if (v[i] - c[i] > 0) {
            sum += v[i] - c[i];
        }
        i++;
    }
    return sum;
}
