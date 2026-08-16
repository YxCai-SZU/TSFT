#include <stdbool.h>
#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 200000);
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
uint32_t func(uint32_t n, int32_t *a) {
    uint32_t res = 0;
    uint32_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= res <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000);
        loop invariant (\forall integer k; 0 <= k < (i) ==> 
            (((a)[k] % 2) == 1) ==> (res) >= 1);
        loop invariant (\forall integer k; 0 <= k < (i) ==> 
            (((a)[k] % 2) != 1) ==> (res) >= 0);
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        int32_t e = a[i];
        
        //@ assert 1 <= e <= 1000000;
        
        if ((e % 2) == 1) {
            res += 1;
        }
        
        //@ assert res >= 0;
        //@ assert res <= i + 1;
        
        i += 1;
    }
    
    //@ assert res <= n;
    return res;
}

int main() {
    return 0;
}
