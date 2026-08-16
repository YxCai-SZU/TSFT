#include <stdbool.h>

/*@
    requires ((N) >= 1 && (N) <= 100 &&
        \valid((a) + (0 .. (N)-1)) &&
        \forall integer j; 0 <= j < (N) ==> (a)[j] >= 1 && (a)[j] <= 100);
    ensures 0 <= \result <= N;
    assigns \nothing;
*/
int func(int N, int *a) {
    int count = 0;
    int num = 0;
    int i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (N) &&
        0 <= (count) <= (i) &&
        (((N)) >= 1 && ((N)) <= 100 &&
        \valid(((a)) + (0 .. ((N))-1)) &&
        \forall integer j; 0 <= j < ((N)) ==> ((a))[j] >= 1 && ((a))[j] <= 100));
        loop assigns i, count, num;
        loop variant N - i;
    */
    while (i < N) {
        num = a[i];
        //@ assert 1 <= num <= 100;
        
        if ((num & 1) == 1 || (num & 1) == 5) {
            count += 1;
        }
        i += 1;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}
