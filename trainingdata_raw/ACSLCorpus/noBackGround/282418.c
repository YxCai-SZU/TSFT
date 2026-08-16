#include <stdbool.h>
#include <stdint.h>

/*@ requires N > 0 && N <= 100;
    requires \valid(a + (0 .. N-1));
    requires (\forall integer i; (0 <= (i) < ((N))) ==> (1 <= ((a)[i]) <= 100));
    assigns \nothing;
    ensures -1 <= \result <= (int)N;
*/
int func(int N, int *a) {
    int count = 0;
    int num = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= N;
        loop invariant 0 <= count <= index;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> (1 <= (a[i]) <= 100);
        loop invariant (\forall integer i; (0 <= (i) < ((N))) ==> (1 <= ((a)[i]) <= 100));
        loop assigns count, num, index;
        loop variant N - index;
    */
    while (index < N) {
        num = index + 1;
        //@ assert num == index + 1;
        
        if ((num & 1) == 1 && (a[index] & 1) == 1) {
            //@ assert (num & 1) == 1 && (a[index] & 1) == 1;
            count += 1;
        }
        index += 1;
    }
    
    //@ assert index == N;
    //@ assert 0 <= count <= N;
    
    if (count == 0) {
        return -1;
    } else {
        return count;
    }
}
