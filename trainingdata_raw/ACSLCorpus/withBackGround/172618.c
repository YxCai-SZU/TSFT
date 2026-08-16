#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/*@ predicate valid_numbers(integer n, uint32_t *numbers) =
    n >= 1 && n <= 100000 &&
    \valid_read(numbers + (0..n-1)) &&
    \forall integer k; 0 <= k < n ==> numbers[k] >= 1 && numbers[k] <= 1000000000;
*/

/*@ predicate result_correct(integer n, uint32_t *result, uint32_t *numbers) =
    \forall integer i; 0 <= i < n ==> result[i] == numbers[n - 1 - i];
*/

/*@ lemma numbers_bound_preserved:
    \forall integer n, uint32_t *numbers;
    valid_numbers(n, numbers) ==> \forall integer k; 0 <= k < n ==> numbers[k] >= 1 && numbers[k] <= 1000000000;
*/

/*@
    requires valid_numbers(n, numbers);
    requires \valid(result + (0..n-1));
    assigns result[0..n-1];
    ensures result_correct(n, result, numbers);
*/
void func(uint32_t n, uint32_t *numbers, uint32_t *result) {
    uint32_t i = n;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < n - i ==> result[j] == numbers[n - 1 - j];
        loop assigns i, result[0..n-1];
        loop variant i;
    */
    while (i > 0) {
        i--;
        //@ assert 0 <= i < n;
        result[n - 1 - i] = numbers[i];
    }
}
