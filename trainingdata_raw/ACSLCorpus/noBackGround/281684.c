#include <stddef.h>
#include <stdbool.h>

/*@
  requires \valid(list1 + (0..len1-1));
  requires \valid(list2 + (0..len2-1));
  requires \valid(list3 + (0..len3-1));
  assigns \nothing;
  ensures \result >= len1;
  ensures \result >= len2;
  ensures \result >= len3;
  ensures ((\result) >= (len1) && (\result) >= (len2) && (\result) >= (len3) &&
    ((\result) == (len1) || (\result) == (len2) || (\result) == (len3)));
*/
size_t longest_list_length(const int* list1, size_t len1,
                           const int* list2, size_t len2,
                           const int* list3, size_t len3) {
    size_t max_len;
    size_t len1_local = len1;
    size_t len2_local = len2;
    size_t len3_local = len3;
    
    max_len = len1_local;
    
    //@ assert max_len >= len1_local;
    
    if (len2_local > max_len) {
        max_len = len2_local;
    }
    
    //@ assert max_len >= len1_local && max_len >= len2_local;
    
    if (len3_local > max_len) {
        max_len = len3_local;
    }
    
    //@ assert max_len >= len1_local && max_len >= len2_local && max_len >= len3_local;
    //@ assert ((max_len) >= (len1_local) && (max_len) >= (len2_local) && (max_len) >= (len3_local) &&     ((max_len) == (len1_local) || (max_len) == (len2_local) || (max_len) == (len3_local)));
    
    return max_len;
}
