#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((len1) >= 0 && \valid((vec1) + (0 .. (len1)-1)));
    requires ((len2) >= 0 && \valid((vec2) + (0 .. (len2)-1)));
    assigns \nothing;
    ensures \result <= len1;
    ensures \result <= len2;
*/
size_t min_unique_vec_length(const int *vec1, size_t len1, const int *vec2, size_t len2) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant i <= len1;
        loop invariant i <= len2;
        loop invariant count <= i;
        loop assigns i, count;
        loop variant len1 - i;
    */
    while (i < len1 && i < len2) {
        //@ assert i < len1 && i < len2;
        if (vec1[i] == vec2[i]) {
            count = count + 1;
        }
        i = i + 1;
    }
    
    return count;
}
