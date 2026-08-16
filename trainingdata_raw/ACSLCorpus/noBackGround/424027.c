#include <stdbool.h>
#include <stddef.h>

/*@ requires 2 <= n <= 100;
    requires \valid(aa+(0..n-1));
    requires \valid(bb+(0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (aa)[i] && (aa)[i] <= 100);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (bb)[i] && (bb)[i] <= 100);
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (aa)[i] != (aa)[j]);
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (bb)[i] != (bb)[j]);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int *aa, int *bb) {
    int ans = 0;
    int i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (aa)[i] && (aa)[i] <= 100);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (bb)[i] && (bb)[i] <= 100);
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (aa)[i] != (aa)[j]);
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (bb)[i] != (bb)[j]);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (aa[i] == bb[i]) {
            ans = ans + 1;
        }
        i = i + 1;
    }
    return ans;
}
