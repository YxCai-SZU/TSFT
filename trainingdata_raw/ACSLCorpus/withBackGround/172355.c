#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(int64_t *arr, size_t len, size_t N) =
        len == N &&
        N >= 1 && N <= 200000 &&
        \forall size_t i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= (int64_t)N &&
        \forall size_t i; 0 <= i < len - 1 ==> arr[i] != arr[i + 1];

    logic integer max(integer a, integer b) = a > b ? a : b;
*/

/*@
    requires N >= 1 && N <= 200000;
    requires \valid(P + (0 .. N-1));
    requires valid_array(P, N, N);
    assigns \nothing;
    ensures 1 <= \result <= N;
*/
int32_t func(size_t N, const int64_t *P) {
    int32_t ans = 1;
    int32_t c = 1;
    size_t i = 1;
    
    //@ assert 1 <= i <= N;
    //@ assert 1 <= c <= (int32_t)i;
    //@ assert 1 <= ans <= (int32_t)i;
    
    /*@
        loop invariant 1 <= i <= N;
        loop invariant 1 <= c <= (int32_t)i;
        loop invariant 1 <= ans <= (int32_t)i;
        loop invariant \forall size_t j; 0 <= j < i ==> P[j] >= 1 && P[j] <= (int64_t)N;
        loop invariant \forall size_t j; 0 <= j < i - 1 ==> P[j] != P[j + 1];
        loop invariant i <= N;
        loop assigns i, c, ans;
        loop variant N - i;
    */
    while (i < N) {
        //@ assert 0 <= i - 1 < N;
        //@ assert 0 <= i < N;
        
        if (P[i] <= P[i - 1]) {
            c = c + 1;
            //@ assert c >= 2;
        } else {
            //@ assert ans >= 1;
            //@ assert c >= 1;
            ans = ans > c ? ans : c;
            c = 1;
        }
        i = i + 1;
        
        //@ assert 1 <= i <= N;
        //@ assert 1 <= c <= (int32_t)i;
        //@ assert 1 <= ans <= (int32_t)i;
    }
    
    //@ assert i == N;
    //@ assert c >= 1;
    //@ assert ans >= 1;
    ans = ans > c ? ans : c;
    
    //@ assert 1 <= ans <= N;
    return ans;
}
