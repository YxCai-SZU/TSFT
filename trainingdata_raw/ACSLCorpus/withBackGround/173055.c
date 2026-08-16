#include <stdbool.h>

/*@
    predicate is_valid_range(integer N) = 1 <= N <= 1000000;
    predicate outer_invariant(integer N, integer i, integer ans) =
        is_valid_range(N) &&
        1 <= i <= N + 1 &&
        ans >= 0 &&
        ans <= i - 1;
    predicate inner_invariant(integer N, integer i, integer temp, integer ans) =
        is_valid_range(N) &&
        1 <= i <= N + 1 &&
        0 <= temp <= i &&
        temp % 3 == i % 3 &&
        ans <= i - 1;
    logic integer outer_decreases(integer N, integer i) = N - i + 1;
    logic integer inner_decreases(integer temp) = temp;
*/

/*@
    requires is_valid_range(N);
    ensures \result >= 0 && \result <= N;
    assigns \nothing;
*/
long func(long N) {
    long ans = 0;
    long i = 1;
    
    /*@
        loop invariant outer_invariant(N, i, ans);
        loop assigns ans, i;
        loop variant outer_decreases(N, i);
    */
    while (i <= N) {
        bool divisible = false;
        long temp = i;
        
        /*@
            loop invariant inner_invariant(N, i, temp, ans);
            loop assigns temp;
            loop variant inner_decreases(temp);
        */
        while (temp >= 3) {
            //@ assert temp % 3 == i % 3;
            temp -= 3;
        }
        
        if (temp == 0) {
            divisible = true;
        }
        
        if (divisible) {
            //@ assert ans <= i - 1;
            ans += 1;
        }
        
        //@ assert ans <= i;
        i += 1;
    }
    
    //@ assert ans <= N;
    return ans;
}
