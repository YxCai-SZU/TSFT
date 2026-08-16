#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= n <= 100;
    requires \valid(a + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *a) {
    int count = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= (size_t)n;
        loop invariant 0 <= count <= (int)index;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < (int)index ==> a[i] >= 1 && a[i] <= 100;
        loop invariant ((n) >= 1 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
        loop assigns count, index;
        loop variant n - (int)index;
    */
    while (index < (size_t)n) {
        //@ assert 0 <= index < (size_t)n;
        
        if ((int)index + 1 == a[index]) {
            //@ assert a[index] >= 1 && a[index] <= 100;
            count += 1;
        }
        index += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}
