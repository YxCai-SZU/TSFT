#include <stdbool.h>

/*@ predicate vec_tuple_ext_equal{L}(int *vec1_a, int *vec2_a, int *vec1_b, int *vec2_b, integer len) =
       (\forall integer i; 0 <= i < len ==> \at(vec1_a[i], L) == \at(vec1_b[i], L)) &&
       (\forall integer i; 0 <= i < len ==> \at(vec2_a[i], L) == \at(vec2_b[i], L));
*/

/*@ lemma vec_tuple_equal:
       \forall int *vec1_a, *vec2_a, *vec1_b, *vec2_b, integer len;
       vec_tuple_ext_equal(vec1_a, vec2_a, vec1_b, vec2_b, len) ==>
       (\forall integer i; 0 <= i < len ==> vec1_a[i] == vec1_b[i]) &&
       (\forall integer i; 0 <= i < len ==> vec2_a[i] == vec2_b[i]);
*/

int main() {
    int vec1_a[10];
    int vec2_a[10];
    int vec1_b[10];
    int vec2_b[10];
    int i;
    
    //@ ghost int len = 10;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> vec1_a[j] == vec1_b[j];
        loop invariant \forall integer j; 0 <= j < i ==> vec2_a[j] == vec2_b[j];
        loop assigns i, vec1_a[0..len-1], vec2_a[0..len-1];
    */
    for (i = 0; i < 10; i++) {
        vec1_a[i] = vec1_b[i];
        vec2_a[i] = vec2_b[i];
    }
    
    //@ assert vec_tuple_ext_equal(&vec1_a[0], &vec2_a[0], &vec1_b[0], &vec2_b[0], 10);
    
    return 0;
}
