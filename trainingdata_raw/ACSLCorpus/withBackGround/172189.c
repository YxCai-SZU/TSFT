#include <stddef.h>
#include <limits.h>

/*@ predicate valid_range(integer v) = 1 <= v <= 100; */

/*@ predicate valid_vector(int *v, integer len) =
      len == 3 &&
      valid_range(v[0]) &&
      valid_range(v[1]) &&
      valid_range(v[2]); */

/*@ lemma vector_length_lemma: \forall int *v, integer len;
      valid_vector(v, len) ==> len == 3; */

/*@ lemma element_range_lemma: \forall int *v, integer len, integer k;
      valid_vector(v, len) && 0 <= k < len ==> valid_range(v[k]); */

/*@ requires \valid(v + (0 .. 2));
    requires valid_vector(v, 3);
    ensures 1 <= \result <= 3;
    assigns \nothing;
 */
int func(int *v) {
    int min;
    int count;
    size_t index;
    
    min = v[0];
    count = 1;
    index = 1;
    
    /*@ loop invariant 0 <= index <= 3;
        loop invariant 1 <= count <= index;
        loop invariant index > 0 ==> \forall integer k; 0 <= k < index ==> valid_range(v[k]);
        loop invariant valid_vector(v, 3);
        loop invariant valid_range(min);
        loop invariant 1 <= count <= 3;
        loop invariant v != \null && \valid(v + (0 .. 2));
        loop assigns min, count, index;
        loop variant 3 - index;
     */
    while (index < 3) {
        //@ assert valid_range(v[index]);
        
        if (min == v[index]) {
            count += 1;
            //@ assert count >= 2 && count <= 3;
        } else if (min > v[index]) {
            min = v[index];
            count = 1;
            //@ assert count == 1;
        }
        
        index += 1;
        //@ assert index <= 3;
    }
    
    //@ assert count >= 1 && count <= 3;
    return count;
}

int main() {
    return 0;
}
