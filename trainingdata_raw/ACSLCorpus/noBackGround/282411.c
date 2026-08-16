#include <stddef.h>
#include <limits.h>

/*@
    requires \valid(lens + (0..outer_len-1));
    requires \forall size_t i; 0 <= i < outer_len ==> lens[i] > 0;
    requires \valid(lst + (0..outer_len-1));
    requires \forall size_t i; 0 <= i < outer_len ==> 
                \valid(lst[i] + (0..lens[i]-1));
    ensures \result >= 0;
    ensures \forall size_t i; 0 <= i < outer_len ==> \result <= lens[i];
*/
size_t find_min_length(int **lst, size_t outer_len, size_t *lens) {
    size_t min_length = (size_t)-1;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= outer_len;
        loop invariant \forall size_t j; 0 <= j < i ==> min_length <= lens[j];
        loop invariant i == 0 ==> min_length == (size_t)-1;
        loop invariant i > 0 ==> min_length <= lens[0];
        loop assigns i, min_length;
        loop variant outer_len - i;
    */
    while (i < outer_len) {
        size_t vec_len = lens[i];
        
        if (vec_len < min_length) {
            min_length = vec_len;
        }
        
        i++;
    }
    
    if (min_length == (size_t)-1) {
        return 0;
    } else {
        return min_length;
    }
}

int main() {
    return 0;
}
