#include <stddef.h>
#include <stdint.h>

/*@
    requires \valid(s+(0..len-1)) && \valid(t+(0..len-1));
    requires len <= 0xFFFFFFFF;
    assigns \nothing;
    ensures \result <= len;
    ensures \forall size_t i; 0 <= i < len ==> (s[i] != t[i] ==> \result > 0);
*/
size_t min_operations(uint32_t *s, uint32_t *t, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant \forall size_t k; 0 <= k < i ==> (s[k] != t[k] ==> count > 0);
        loop invariant \valid(s+(0..len-1)) && \valid(t+(0..len-1));
        loop invariant len <= 0xFFFFFFFF;
        loop invariant count <= len;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        if (s[i] != t[i]) {
            //@ assert s[i] != t[i] ==> count + 1 > 0;
            count++;
        }
        i++;
    }
    return count;
}
