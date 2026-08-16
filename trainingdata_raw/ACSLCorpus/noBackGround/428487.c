#include <stdbool.h>

/*@
    requires len > 0;
    ensures \result <= a[0];
    ensures \forall integer i; 0 <= i < len ==> \result <= a[i];
*/
int min_element(int* a, int len)
{
    int min;
    int i;
    
    //@ assert len > 0;
    min = a[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (min) <= (a)[k]);
        loop invariant (\exists integer k; 0 <= k < (i) && (min) == (a)[k]);
        loop assigns min, i;
        loop variant len - i;
    */
    while (i < len) {
        if (a[i] < min) {
            min = a[i];
        }
        i = i + 1;
    }
    return min;
}

int main() {
    return 0;
}
