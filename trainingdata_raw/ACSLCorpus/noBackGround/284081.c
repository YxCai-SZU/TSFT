#include <stdbool.h>

/*@
    requires (3 <= (N) <= 20);
    requires \valid(p+(0..N-1));
    requires (\forall integer i; 0 <= i < (N) ==> 1 <= (p)[i] <= (N));
    requires (\forall integer i, j; 0 <= i < j < (N) ==> (p)[i] != (p)[j]);
    ensures 0 <= \result <= N-2;
*/
int func(int N, int *p)
{
    int count = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= N-1;
        loop invariant 0 <= count <= i-1;
        loop invariant (\forall integer i; 0 <= i < (N) ==> 1 <= (p)[i] <= (N));
        loop invariant (\forall integer i, j; 0 <= i < j < (N) ==> (p)[i] != (p)[j]);
        loop invariant (3 <= (N) <= 20);
        loop assigns i, count;
    */
    while (i < N - 1) {
        //@ assert 0 <= i-1 < N;
        
        if (p[i] < p[i-1] && p[i] < p[i+1]) {
            count += 1;
        }
        
        //@ assert 0 <= i < N;
        
        if (p[i] > p[i-1] && p[i] > p[i+1]) {
            count += 1;
        }
        
        i += 1;
    }
    
    //@ assert 0 <= count <= N-2;
    return count;
}
