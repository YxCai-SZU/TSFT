#include <stdbool.h>
#include <stddef.h>

/*@
    predicate x_valid(int *x, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> (x[i] == 0 || x[i] == 1);

    predicate a_valid(int *a, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> (1 <= a[i] && a[i] <= 10);

    logic integer ans_bound(integer i) = i * 10;
*/

/*@
    requires \valid(x + (0..4)) && \valid(a + (0..4));
    requires x_valid(x, 5);
    requires a_valid(a, 5);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int *x, int *a) {
    int ans = 0;
    size_t index = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant 0 <= index <= 5;
        loop invariant ans >= 0;
        loop invariant x_valid(x, 5);
        loop invariant a_valid(a, 5);
        loop invariant 0 <= ans <= ans_bound(i);
        loop assigns ans, index, i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert x_valid(x, 5);
        
        if (index < 5 && x[index] == 1) {
            //@ assert 1 <= a[i] && a[i] <= 10;
            ans += a[i];
            index++;
        }
        i++;
    }
    
    //@ assert ans >= 0;
    return ans;
}
