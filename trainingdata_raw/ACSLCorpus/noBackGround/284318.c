#include <stdbool.h>
#include <stddef.h>

/*@ requires N >= 3 && N <= 200000;
    requires \valid(p + (0 .. N-1));
    requires \forall integer i; 0 <= i < N ==> 1 <= p[i] && p[i] <= N;
    requires \forall integer i, j; 0 <= i < j < N ==> p[i] != p[j];
    assigns \nothing;
    ensures \result >= 0 && \result <= N-2;
*/
int func(size_t N, const long long *p) {
    int cnt = 0;
    size_t i = 1;
    
    /*@ loop invariant 1 <= i <= N-1;
        loop invariant cnt >= 0;
        loop invariant cnt <= i-1;
        loop assigns cnt, i;
        loop variant N - i;
    */
    while (i < N - 1) {
        //@ assert i < N && i+1 < N;
        
        if ((p[i-1] < p[i] && p[i] < p[i+1]) || 
            (p[i-1] > p[i] && p[i] > p[i+1])) {
            cnt += 1;
        }
        i += 1;
    }
    return cnt;
}
