#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    requires \valid(a + (0..4));
    requires \forall integer i; 0 <= i < 5 ==> (a[i] == i+1 || a[i] == 0);
    requires \exists integer i; 0 <= i < 5 && a[i] == 0;
    ensures \result > 0 && \result <= 5;
    ensures a[\result-1] == 0;
*/
unsigned long func(int64_t *a) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] != 0;
        loop invariant \exists integer j; i <= j < 5 && a[j] == 0;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (a[i] == 0) {
            //@ assert a[i] == 0;
            return (unsigned long)i + 1;
        }
        //@ assert a[i] != 0;
        i++;
    }
    return 0;
}
