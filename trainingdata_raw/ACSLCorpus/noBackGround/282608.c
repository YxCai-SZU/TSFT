#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> (a)[j] >= 1 && (a)[j] <= 1000000);
    ensures \result >= 0 && \result <= n * 1000000;
    assigns \nothing;
*/
long long func(long long n, const long long *a) {
    long long ans = 0;
    long long prev_height = 0;
    long long i = 0;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
        0 <= (ans) && (ans) <= (i) * 1000000 &&
        (prev_height) >= 0 && (prev_height) <= 1000000 &&
        (((n)) >= 1 && ((n)) <= 200000 &&
        \valid(((a)) + (0 .. ((n))-1)) &&
        \forall integer j; 0 <= j < ((n)) ==> ((a))[j] >= 1 && ((a))[j] <= 1000000));
        loop assigns ans, prev_height, i;
        loop variant n - i;
    */
    while (i < n) {
        long long height = a[i];
        
        //@ assert height >= 1 && height <= 1000000;
        
        if (height < prev_height) {
            //@ assert prev_height - height >= 0;
            ans += prev_height - height;
        } else {
            prev_height = height;
        }
        
        //@ assert ans >= 0 && ans <= (i + 1) * 1000000;
        
        i++;
    }
    
    return ans;
}
