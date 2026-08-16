#include <stdbool.h>
#include <stddef.h>

/*@ requires N >= 3 && N <= 20;
    requires \valid(p + (0 .. N-1));
    requires \forall integer j; 0 <= j < N ==> p[j] >= 1 && p[j] <= N;
    requires \forall integer j; 0 <= j < N - 1 ==> p[j] != p[j + 1];
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t N, const int *p) {
    int count = 0;
    size_t i = 1;
    
    /*@ loop invariant 1 <= i <= N - 1;
        loop invariant count >= 0;
        loop invariant count <= (int)(i - 1);
        loop invariant \forall integer j; 0 <= j < N ==> p[j] >= 1 && p[j] <= N;
        loop invariant \forall integer j; 0 <= j < N - 1 ==> p[j] != p[j + 1];
        loop assigns count, i;
        loop variant N - i;
    */
    while (i < N - 1) {
        //@ assert p[i-1] != p[i];
        //@ assert p[i] != p[i+1];
        
        if (p[i - 1] < p[i] && p[i] < p[i + 1]) {
            count += 1;
        }
        if (p[i - 1] > p[i] && p[i] > p[i + 1]) {
            count += 1;
        }
        i += 1;
        
        //@ assert count <= (int)(i - 1);
    }
    
    //@ assert count <= (int)(N - 2);
    return count;
}
