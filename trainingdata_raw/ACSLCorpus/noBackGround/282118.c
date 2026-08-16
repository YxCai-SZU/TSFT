#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000000);
    requires (1 <= (m) <= 10000);
    requires \valid(a + (0..m-1));
    requires (\forall integer i; 0 <= i < (m) ==> 1 <= (a)[i] <= 10000);
    assigns \nothing;
    ensures \result >= -1;
    ensures \result <= n;
*/
int func(int n, int m, int* a) {
    int ret;
    int i;
    
    ret = n;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant ret >= -1;
        loop invariant ret <= n;
        loop invariant (\forall integer i; 0 <= i < (m) ==> 1 <= (a)[i] <= 10000);
        loop invariant (1 <= (n) <= 1000000);
        loop invariant (1 <= (m) <= 10000);
        loop invariant i <= m;
        loop assigns ret, i;
        loop variant m - i;
    */
    while (i < m) {
        int value;
        
        value = a[i];
        
        if (ret >= value) {
            //@ assert ret >= value;
            //@ assert ret - value >= -1;
            ret = ret - value;
        } else {
            ret = -1;
        }
        
        i = i + 1;
    }
    
    return ret;
}
