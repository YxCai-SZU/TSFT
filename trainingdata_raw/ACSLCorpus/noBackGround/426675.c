#include <stdbool.h>
#include <stddef.h>

/*@ requires (2 <= (n) <= 100000);
    requires (\valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= (n));
    requires n == len;
    ensures -1 <= \result < (int)n;
    assigns \nothing;
 */
int func(size_t n, int *numbers, size_t len) {
    size_t ans = 1;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 1 <= ans <= n;
        loop invariant (\valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= (n));
        loop invariant (2 <= (n) <= 100000);
        loop invariant index > 0 ==> 1 <= ans <= n;
        loop assigns ans, index;
        loop variant n - index;
     */
    while (index < n) {
        //@ assert 1 <= ans <= n;
        if (numbers[ans - 1] == 2) {
            //@ assert ans - 1 >= 0;
            //@ assert ans - 1 < n;
            return (int)(ans - 1);
        }
        //@ assert 1 <= numbers[ans - 1] <= n;
        ans = (size_t)numbers[ans - 1];
        index++;
    }
    return -1;
}
