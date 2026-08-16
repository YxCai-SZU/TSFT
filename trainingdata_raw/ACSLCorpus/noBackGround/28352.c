#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0..(n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
long func(long n, long *a) {
    long count = 0;
    long index = 0;
    
    /*@
        loop invariant (0 <= (index) && (index) <= (n) &&
        (count) >= 0 &&
        (count) <= (index) &&
        ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> (a)[i] >= 1 && (a)[i] <= (n)) &&
        ((index) > 0 ==> \forall integer i, j; 0 <= i < j < (index) ==> (a)[i] != (a)[j]));
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        long value = a[index];
        //@ assert value >= 1 && value <= n;
        if (value == count + 1) {
            count = value;
        }
        index += 1;
    }
    
    //@ assert count <= n;
    return n - count;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
