#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 2 && n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires ((n) >= 2 && (n) <= 100000 &&
      \forall integer i; 0 <= i < (n) ==> 
        (a)[i] >= 1 && (a)[i] <= (n) && (a)[i] != i + 1);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(size_t n, const size_t *a) {
    size_t cnt = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant cnt <= index;
        loop invariant \forall integer i; 0 <= i < index ==> 
                        a[i] >= 1 && a[i] <= n && a[i] != i + 1;
        loop invariant index > 0 ==> cnt < n;
        loop invariant n >= 2 && n <= 100000;
        loop assigns cnt, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert index < n;
        //@ assert a[index] >= 1 && a[index] <= n && a[index] != index + 1;
        
        if (a[index] == index + 1) {
            cnt = cnt + 1;
        }
        index = index + 1;
    }
    
    int ans;
    if (cnt > 2) {
        ans = (int)cnt - 1;
    } else {
        ans = (int)cnt;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= (int)n;
    
    return ans;
}
