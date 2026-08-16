#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_params(integer N, integer A, integer B, size_t len) =
        3 <= N && N <= 100 &&
        1 <= A && A <= 1000 &&
        1 <= B && B <= 1000 &&
        len == (size_t)N;

    predicate valid_array(integer N, int *arr, size_t len) =
        len == (size_t)N &&
        \forall integer j; 0 <= j < N ==> 1 <= arr[j] && arr[j] <= 1000;

    logic integer ans_bound(integer i) = i * 1000;
*/

/*@
    requires valid_params(N, A, B, len);
    requires valid_array(N, input_numbers, len);
    requires \valid_read(input_numbers + (0 .. len-1));
    assigns \nothing;
    ensures 0 <= \result;
    ensures \result <= N * 1000;
*/
size_t func(size_t N, size_t A, size_t B, int *input_numbers, size_t len) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= N;
        loop invariant ans <= ans_bound(i);
        loop invariant valid_params(N, A, B, len);
        loop invariant valid_array(N, input_numbers, len);
        loop assigns ans, i;
        loop variant N - i;
    */
    while (i < N) {
        //@ assert 0 <= i < N;
        size_t number = (size_t)input_numbers[i];
        size_t train = (A < number) ? A : number;
        ans += train;
        i++;
    }
    
    size_t taxi = (B < (ans * 2)) ? B : (ans * 2);
    return taxi;
}
