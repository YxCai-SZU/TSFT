#include <stdbool.h>
#include <stdint.h>

/*@ requires (1 <= (N) <= 200000);
    requires \valid(a + (0 .. N-1));
    requires \forall integer i; 0 <= i < N ==> (1 <= (a[i]) <= 1000000000);
    ensures 0 <= \result <= N;
    assigns \nothing;
*/
int func(int N, const int* a) {
    int count = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= N;
        loop invariant 0 <= count <= index;
        loop invariant \forall integer i; 0 <= i < N ==> (1 <= (a[i]) <= 1000000000);
        loop invariant (1 <= (N) <= 200000);
        loop assigns count, index;
        loop variant N - index;
    */
    while (index < N) {
        int ai = a[index];
        
        //@ assert (1 <= (ai) <= 1000000000);
        
        if ((ai & 1) == 1 && (index & 1) == 0) {
            //@ assert (((ai) & 1) == 1) && (((index) & 1) == 0);
            count += 1;
        }
        
        index += 1;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}
