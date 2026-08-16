#include <stdbool.h>
#include <stddef.h>

/*@
    requires 0 <= len < 0x80000000;
    requires \valid(a + (0 .. len - 1));
    ensures \result == true ==> (\forall integer i; 0 <= i < (len) - 1 ==> (a)[i] <= (a)[i + 1]);
    ensures \result == false ==> (\exists integer i; 0 <= i < (len) - 1 && (a)[i] > (a)[i + 1]);
*/
bool is_sorted(int *a, size_t len) {
    size_t i;
    bool result;
    
    if (len < 2) {
        //@ assert (\forall integer i; 0 <= i < (len) - 1 ==> (a)[i] <= (a)[i + 1]);
        return true;
    }
    
    i = 0;
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] <= a[k + 1];
        loop assigns i, result;
        loop variant len - i;
    */
    while (i < len - 1) {
        if (a[i] > a[i + 1]) {
            //@ assert (\exists integer i; 0 <= i < (len) - 1 && (a)[i] > (a)[i + 1]);
            return false;
        }
        i++;
    }
    
    //@ assert (\forall integer i; 0 <= i < (len) - 1 ==> (a)[i] <= (a)[i + 1]);
    return true;
}

int main() {
    return 0;
}
