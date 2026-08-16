#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_numbers(integer n, uint64_t *numbers) =
        n >= 1 && n <= 100 &&
        \forall integer i; 0 <= i < n ==> numbers[i] >= 1 && numbers[i] <= 100;

    predicate loop_invariant(integer n, integer i, uint64_t ans, uint64_t sum, uint64_t x, uint64_t *numbers) =
        0 <= i && i <= n &&
        1 <= ans && ans <= i + 1 &&
        sum >= 0 && sum <= i * 100 &&
        \forall integer j; 0 <= j < i ==> numbers[j] >= 1 && numbers[j] <= 100;
*/

/*@
    requires n >= 1 && n <= 100;
    requires x >= 1 && x <= 10000;
    requires \valid(numbers + (0 .. n-1));
    requires valid_numbers(n, numbers);
    assigns \nothing;
    ensures \result >= 1 && \result <= n + 1;
*/
uint64_t func(uint64_t n, uint64_t x, uint64_t numbers[]) {
    uint64_t ans;
    uint64_t sum;
    uint64_t i;
    uint64_t a;

    ans = 1;
    sum = 0;
    i = 0;

    /*@
        loop invariant loop_invariant(n, i, ans, sum, x, numbers);
        loop assigns i, ans, sum, a;
        loop variant n - i;
    */
    while (i < n) {
        a = numbers[i];
        sum = sum + a;

        //@ assert sum >= 0 && sum <= (i + 1) * 100;
        if (sum <= x) {
            ans = ans + 1;
        }
        //@ assert 1 <= ans && ans <= i + 2;
        i = i + 1;
    }
    //@ assert ans >= 1 && ans <= n + 1;
    return ans;
}
