#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(list+(0..len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer k; 0 <= k < len ==> 
            (list[k] == element ==> \result > 0);
*/
size_t count_element(int *list, size_t len, int element) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant count <= len;
        loop invariant \forall integer k; 0 <= k < i ==> 
                (list[k] == element ==> count > 0);
        loop invariant len >= 0;
        loop assigns count, i;
        loop variant len - i;
    */
    while (i < len) {
        if (list[i] == element) {
            //@ assert list[i] == element ==> count + 1 > 0;
            count++;
        }
        i++;
    }
    
    //@ assert ((count) >= 0 && (count) <= (len));
    return count;
}
