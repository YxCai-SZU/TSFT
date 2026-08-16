#include <stddef.h>
#include <stdint.h>

/*@
    requires 1 <= n && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 100;
    ensures 0 <= \result && \result <= n;
    assigns \nothing;
*/
int func(size_t n, const int *a) {
    size_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index && index <= n;
        loop invariant 0 <= count && count <= index;
        loop invariant (1 <= (n) && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
        loop invariant index > 0 ==>
            \forall integer j; 0 <= j < index ==>
                (j + 1 < n && a[j] == j + 1) ==> count > 0;
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n) {
        if (index + 1 < n && a[index] == (int)(index + 1)) {
            count++;
        }
        index++;
        
        //@ assert index > 0 ==> \forall integer j; 0 <= j < index ==> (j + 1 < n && a[j] == j + 1) ==> count > 0;
    }
    
    return (int)count;
}
