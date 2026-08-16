#include <stdbool.h>
/*@
    requires (1 <= (N) && (N) <= 100);
    requires \valid_read(input2 + (0 .. N-1));
    requires (\forall integer i; 0 <= i < (N) ==> 1 <= (input2)[i] && (input2)[i] <= 1000000000);
    ensures 0 <= \result <= N;
*/
int func(int N, int *input2) {
    int count;
    int a;
    int i;
    
    count = 0;
    a = 1;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= N;
        loop invariant 0 <= count <= i;
        loop invariant (\forall integer i; 0 <= i < (N) ==> 1 <= (input2)[i] && (input2)[i] <= 1000000000);
        loop invariant a == 1;
        loop invariant (\forall integer k; 0 <= k < (i) ==> ((input2)[k] == (a) + k ==> (count) > 0));
        loop invariant count <= i;
        loop assigns i, count;
        loop variant N - i;
    */
    while (i < N) {
        int value;
        value = input2[i];
        
        //@ assert 0 <= i < N;
        //@ assert 1 <= value <= 1000000000;
        
        if (value == a + i) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}
