#include <stdbool.h>
#include <stddef.h>

/*@ requires (3 <= (N) <= 20);
    requires \valid(vec + (0 .. N-1));
    requires (\forall integer i; 0 <= i < (N) ==> 1 <= (vec)[i] <= (N) &&
    \forall integer i; 0 <= i < (N)-1 ==> (vec)[i] != (vec)[i+1]);
    assigns \nothing;
    ensures 0 <= \result <= N-2;
*/
int func(size_t N, const int *vec) {
    int count = 0;
    size_t a = 1;
    
    /*@ loop invariant 1 <= a <= N-1;
        loop invariant 0 <= count <= (int)(a-1);
        loop invariant (\forall integer i; 0 <= i < (N) ==> 1 <= (vec)[i] <= (N) &&
    \forall integer i; 0 <= i < (N)-1 ==> (vec)[i] != (vec)[i+1]);
        loop assigns count, a;
        loop variant N-1-a;
    */
    while (a < N - 1) {
        //@ assert 0 <= a-1 < N && 0 <= a < N && 0 <= a+1 < N;
        
        if ((vec[a - 1] < vec[a] && vec[a] < vec[a + 1]) ||
            (vec[a - 1] > vec[a] && vec[a] > vec[a + 1])) {
            //@ assert count >= 0;
            count = count + 1;
        }
        
        a += 1;
    }
    
    //@ assert 0 <= count <= (int)(N-2);
    return count;
}
