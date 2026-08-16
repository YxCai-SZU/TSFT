#include <stddef.h>

/*@ requires (3 <= (N) <= 20);
    requires \valid(p+(0..N-1));
    requires (\forall integer j; 0 <= j < (N) ==> 1 <= (p)[j] <= (N) &&
      \forall integer j; 0 <= j < (N)-1 ==> (p)[j] < (p)[j+1]);
    assigns \nothing;
    ensures 0 <= \result <= N-2;
*/
int func(size_t N, int *p) {
    int count = 0;
    size_t i = 1;
    
    /*@ loop invariant 1 <= i <= N-1;
        loop invariant 0 <= count <= i-1;
        loop invariant (\forall integer j; 0 <= j < (N) ==> 1 <= (p)[j] <= (N) &&
      \forall integer j; 0 <= j < (N)-1 ==> (p)[j] < (p)[j+1]);
        loop invariant (3 <= (N) <= 20);
        loop assigns i, count;
        loop variant N-i;
    */
    while (i < N - 1) {
        //@ assert p[i-1] < p[i] && p[i] < p[i+1] ==> count+1 <= i;
        //@ assert p[i-1] > p[i] && p[i] > p[i+1] ==> count+1 <= i;
        
        if ((p[i - 1] < p[i] && p[i] < p[i + 1]) ||
            (p[i - 1] > p[i] && p[i] > p[i + 1])) {
            count += 1;
        }
        i += 1;
    }
    
    //@ assert 0 <= count <= N-2;
    return count;
}
