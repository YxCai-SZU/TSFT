#include <stdbool.h>
#include <stddef.h>

/*@ requires (\valid((s) + (0 .. (len)-1)) && \valid((t) + (0 .. (len)-1)) &&
      (((len)) > 0 && ((len)) <= 10000 &&
      \forall integer i; 0 <= i < ((len)) ==> 0 <= ((s))[i] && ((s))[i] <= 10000) && (((len)) > 0 && ((len)) <= 10000 &&
      \forall integer i; 0 <= i < ((len)) ==> 0 <= ((t))[i] && ((t))[i] <= 10000));
    requires len > 0 && len <= 10000;
    ensures \result <= len;
    assigns \nothing;
*/
size_t min_operations(int* s, int* t, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant (\valid((s) + (0 .. (len)-1)) && \valid((t) + (0 .. (len)-1)) &&
      (((len)) > 0 && ((len)) <= 10000 &&
      \forall integer i; 0 <= i < ((len)) ==> 0 <= ((s))[i] && ((s))[i] <= 10000) && (((len)) > 0 && ((len)) <= 10000 &&
      \forall integer i; 0 <= i < ((len)) ==> 0 <= ((t))[i] && ((t))[i] <= 10000));
        loop invariant count <= len;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (s[i] != t[i]) {
            //@ assert count + 1 <= len;
            count++;
        }
        i++;
    }
    //@ assert count <= len;
    return count;
}
