#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0;
    requires \valid(v + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (v)[i] > 0);
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> 
        ((v)[i] % 2 == 0 ==> ((v)[i] % 3 == 0 || (v)[i] % 5 == 0)));
*/
bool func(size_t n, int *v) {
    size_t i = 0;
    bool ok = true;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (v)[i] > 0);
        loop invariant n > 0;
        loop invariant ok == true <==> 
          \forall integer j; 0 <= j < i ==> 
            (v[j] % 2 == 0 ==> (v[j] % 3 == 0 || v[j] % 5 == 0));
        loop assigns i, ok;
        loop variant n - i;
    */
    while (i < n) {
        int value = v[i];
        if (value % 2 == 0) {
            if (value % 3 != 0 && value % 5 != 0) {
                ok = false;
            }
        }
        i++;
    }
    
    //@ assert ok == true <==> (\forall integer i; 0 <= i < (n) ==>          ((v)[i] % 2 == 0 ==> ((v)[i] % 3 == 0 || (v)[i] % 5 == 0)));
    return ok;
}
