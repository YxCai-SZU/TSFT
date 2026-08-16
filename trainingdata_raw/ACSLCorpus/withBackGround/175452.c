#include <stddef.h>

/*@
    predicate valid_params(integer n, integer x, unsigned int *numbers) =
        1 <= n && n <= 100 &&
        1 <= x && x <= 10000 &&
        \valid(numbers + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= numbers[i] && numbers[i] <= 100;
*/

/*@
    requires valid_params(n, x, numbers);
    ensures \result >= 0 && \result <= n + 1;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int x, unsigned int *numbers) {
    unsigned int count = 0;
    unsigned int sum = 0;
    unsigned int i = 0;

    /*@
        loop invariant 0 <= i && i <= n;
        loop invariant 0 <= count && count <= i;
        loop invariant sum <= i * 100;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= numbers[j] && numbers[j] <= 100;
        loop invariant i > 0 ==> (sum <= x || count < i);
        loop assigns i, count, sum;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i && i < n;
        sum += numbers[i];
        count += 1;
        
        if (sum > x) {
            break;
        }
        
        i += 1;
    }

    //@ assert count >= 0 && count <= n + 1;
    return count;
}
