#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(vec1 + (0 .. len1 - 1));
  requires \valid_read(vec2 + (0 .. len2 - 1));
  requires len1 < 0x80000000;
  requires len2 < 0x80000000;
  assigns \nothing;
  ensures \result == (len1 == len2);
*/
bool find_equal_vector_length(const int *vec1, size_t len1,
                              const int *vec2, size_t len2) {
    //@ assert len1 < 0x80000000;
    //@ assert len2 < 0x80000000;
    
    if (len1 == len2) {
        //@ assert len1 == len2;
        return true;
    } else {
        //@ assert len1 != len2;
        return false;
    }
}

/*@
  requires \valid_read(vec + (0 .. len - 1));
  requires len < 0x80000000;
  assigns \nothing;
  ensures \result == true <==> (\forall size_t i; 0 <= i < (len) - 1 ==> (vec)[i] < (vec)[i + 1]);
*/
bool is_strictly_increasing(const int *vec, size_t len) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall size_t j; 0 <= j < i - 1 ==> vec[j] < vec[j + 1];
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i && i < len;
        
        if (i > 0 && vec[i] <= vec[i - 1]) {
            //@ assert !(vec[i - 1] < vec[i]);
            return false;
        }
        
        i++;
    }
    
    //@ assert (\forall size_t i; 0 <= i < (len) - 1 ==> (vec)[i] < (vec)[i + 1]);
    return true;
}
