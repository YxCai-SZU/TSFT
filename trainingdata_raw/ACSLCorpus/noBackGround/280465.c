#include <stddef.h>
#include <stdint.h>

/*@
    requires \valid(list1 + (0..len1-1));
    requires \valid(list2 + (0..len2-1));
    requires \valid(list3 + (0..len3-1));
    requires len1 >= 0 && len2 >= 0 && len3 >= 0;
    requires \valid(result_len);
    assigns *result_len;
    ensures ((*result_len) >= (len1) && (*result_len) >= (len2) && (*result_len) >= (len3) &&
        ((*result_len) == (len1) || (*result_len) == (len2) || (*result_len) == (len3)));
    ensures \result == list1 || \result == list2 || \result == list3;
*/
int* max_length_list(int* list1, size_t len1,
                     int* list2, size_t len2,
                     int* list3, size_t len3,
                     size_t* result_len) {
    int* ret;
    
    //@ assert len1 >= 0 && len2 >= 0 && len3 >= 0;
    
    if (len1 >= len2 && len1 >= len3) {
        //@ assert len1 >= len2 && len1 >= len3;
        ret = list1;
        *result_len = len1;
    } else if (len2 >= len1 && len2 >= len3) {
        //@ assert len2 >= len1 && len2 >= len3;
        ret = list2;
        *result_len = len2;
    } else {
        //@ assert len3 >= len1 && len3 >= len2;
        ret = list3;
        *result_len = len3;
    }
    
    //@ assert ((*result_len) >= (len1) && (*result_len) >= (len2) && (*result_len) >= (len3) &&         ((*result_len) == (len1) || (*result_len) == (len2) || (*result_len) == (len3)));
    return ret;
}
