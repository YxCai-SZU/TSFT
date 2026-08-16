#include <stdbool.h>
#include <stddef.h>

/*@ predicate vectors_equal{L}(unsigned int *v, unsigned int *w, integer len) =
      \forall integer i; 0 <= i < len ==> v[i] == w[i];
*/

/*@ predicate valid_range{L}(unsigned int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 100;
*/

/*@ lemma same_length_equal_implies_vectors_equal:
      \forall unsigned int *v, *w, integer len;
        valid_range(v, len) && valid_range(w, len) &&
        (\forall integer i; 0 <= i < len ==> v[i] == w[i]) ==>
        vectors_equal(v, w, len);
*/

/*@ requires \valid_read(v + (0 .. len-1)) && \valid_read(w + (0 .. len-1));
    requires len >= 0;
    requires valid_range(v, len);
    requires valid_range(w, len);
    ensures \result == true <==> vectors_equal(v, w, len);
*/
bool func(const unsigned int *v, const unsigned int *w, size_t len) {
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant \forall integer i; 0 <= i < index ==> v[i] == w[i];
        loop invariant valid_range(v, len);
        loop invariant valid_range(w, len);
        loop assigns index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert 0 <= index < len;
        if (v[index] != w[index]) {
            break;
        }
        index = index + 1;
    }
    
    //@ assert index == len ==> vectors_equal(v, w, len);
    //@ assert index != len ==> !vectors_equal(v, w, len);
    return index == len;
}
