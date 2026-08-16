#include <stdbool.h>

/*@ requires (2 <= (n) <= 1000000);
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) <= 1000000000));
    ensures 0 <= \result <= n;
    assigns \nothing;
 */
int func(int n, int *a) {
    int count = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) <= 1000000000));
        loop invariant (2 <= (n) <= 1000000);
        loop assigns count, index;
        loop variant n - index;
     */
    while (index < n) {
        int element = a[index];
        //@ assert (1 <= (element) <= 1000000000);
        
        if (element & 1) {
            count++;
            //@ assert 0 <= count <= index+1;
        }
        index++;
    }
    //@ assert index == n;
    //@ assert 0 <= count <= n;
    return count;
}
