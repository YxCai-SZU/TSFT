#include <stddef.h>

/*@ requires ((N) >= 2 && (N) <= 100 &&
    \valid((B) + (0 .. (N)-2)) &&
    \forall integer j; 0 <= j < (N)-1 ==> (B)[j] >= 0 && (B)[j] <= 100000);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t N, int *B) {
    int ans;
    size_t i;
    
    //@ assert N >= 2 && N <= 100;
    //@ assert \valid(B + (0 .. N-2));
    //@ assert \forall integer j; 0 <= j < N-1 ==> B[j] >= 0 && B[j] <= 100000;
    
    ans = B[0] + B[N-2];
    i = 1;
    
    /*@ loop invariant 1 <= i <= N-1;
        loop invariant ans >= ((B[0]) + (B[N-2]) + ((i) - 1) * 0);
        loop invariant ans <= ((B[0]) + (B[N-2]) + (i) * (100000));
        loop invariant i > 1 ==> ans >= 0;
        loop invariant B[0] >= 0 && B[N-2] >= 0;
        loop invariant B[0] <= 100000 && B[N-2] <= 100000;
        loop assigns ans, i;
        loop variant N - i;
    */
    while (i < N-1) {
        int add_value;
        
        //@ assert 0 <= i-1 < N-1;
        //@ assert 0 <= i < N-1;
        
        if (B[i-1] < B[i]) {
            add_value = B[i-1];
        } else {
            add_value = B[i];
        }
        
        //@ assert add_value >= 0 && add_value <= 100000;
        ans += add_value;
        i += 1;
        
        //@ assert ans >= ((B[0]) + (B[N-2]) + ((i) - 1) * 0);
    }
    
    //@ assert ans >= 0;
    return ans;
}
