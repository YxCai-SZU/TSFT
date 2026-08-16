#include <stdbool.h>
/*@
    requires (3 <= (n) <= 100 && 1 <= (a) < (b) < 20);
    requires \valid(p + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= 20);
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int a, int b, int *p) {
    int count = 0;
    int max_count = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant 0 <= max_count <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= 20);
        loop invariant (3 <= (n) <= 100 && 1 <= (a) < (b) < 20);
        loop assigns i, count, max_count;
        loop variant n - i;
    */
    while (i < n) {
        int pi = p[i];
        
        if (pi < a) {
            //@ assert pi >= 1 && pi <= 20;
            count++;
        } else if (pi < b) {
            //@ assert pi >= a && pi < b;
            if (count > max_count) {
                max_count = count;
            }
            count = 0;
        } else {
            //@ assert pi >= b && pi <= 20;
            if (count > max_count) {
                max_count = count;
            }
            count = 1;
        }
        i++;
    }

    if (count > max_count) {
        max_count = count;
    }

    //@ assert max_count >= 0;
    //@ assert max_count <= n;
    return max_count;
}
