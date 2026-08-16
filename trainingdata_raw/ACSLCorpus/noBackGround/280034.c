#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(x + (0 .. 4));
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 0 <= (x)[i] <= 123 &&
        (x)[0] < (x)[1] && (x)[1] < (x)[2] && (x)[2] < (x)[3] && (x)[3] < (x)[4]);
    requires 0 <= k <= 123;
    assigns \nothing;
    ensures 0 <= \result <= 5;
*/
int func(int *x, int k) {
    int ans = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= 5;
        loop invariant 0 <= ans <= (int)index;
        loop invariant ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 0 <= (x)[i] <= 123 &&
        (x)[0] < (x)[1] && (x)[1] < (x)[2] && (x)[2] < (x)[3] && (x)[3] < (x)[4]);
        loop invariant 0 <= k <= 123;
        loop assigns ans, index;
        loop variant 5 - index;
    */
    while (index < 5) {
        int a = x[index];
        
        //@ assert 0 <= a <= 123;
        
        if (a < k) {
            ans += 1;
        }
        
        index += 1;
        
        //@ assert index <= 5;
    }
    
    return ans;
}
