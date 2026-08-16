#include <stddef.h>

/*@
    requires \valid(s + (0..len-1)) && \valid(t + (0..len-1));
    requires ((len) == (len));
    requires ((len) > 0);
    requires (\forall integer i; 0 <= i < (len) ==> (1 <= ((s)[i]) && ((s)[i]) <= 100));
    requires (\forall integer i; 0 <= i < (len) ==> (1 <= ((t)[i]) && ((t)[i]) <= 100));
    
    assigns \nothing;
    
    ensures \result <= len;
*/
size_t min_operations(int* s, int* t, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant ((len) == (len));
        loop invariant ((len) > 0);
        loop invariant (\forall integer i; 0 <= i < (len) ==> (1 <= ((s)[i]) && ((s)[i]) <= 100));
        loop invariant (\forall integer i; 0 <= i < (len) ==> (1 <= ((t)[i]) && ((t)[i]) <= 100));
        loop invariant (\forall integer k; 0 <= k < (i) ==> ((s)[k] != (t)[k] ==> (count) > 0));
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (s[i] != t[i]) {
            //@ assert s[i] != t[i];
            count++;
        }
        i++;
    }
    
    //@ assert count <= len;
    return count;
}
