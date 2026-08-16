#include <stdint.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] <= 1000000000);
    ensures \result >= 0;
    ensures \result <= ((n) * 1000000000);
    assigns \nothing;
*/
int64_t func(size_t n, uint64_t* a) {
    uint64_t before = 0;
    int64_t ans = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant before <= 1000000000;
        loop invariant ans >= 0;
        loop invariant ans <= ((index) * 1000000000);
        loop invariant \forall integer i; 0 <= i < index ==> a[i] <= 1000000000;
        loop invariant n > 0 && n <= 200000;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < n ==> a[i] <= 1000000000;
        loop assigns before, ans, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        //@ assert \valid(a + index);
        
        if (before <= a[index]) {
            //@ assert a[index] - before <= 1000000000;
            ans += (int64_t)(a[index] - before);
        } else {
            //@ assert before - a[index] <= 1000000000;
            ans += (int64_t)(before - a[index]);
        }
        
        before = a[index];
        index++;
        
        //@ assert ans >= 0;
        //@ assert ans <= ((index) * 1000000000);
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= ((n) * 1000000000);
    return ans;
}
