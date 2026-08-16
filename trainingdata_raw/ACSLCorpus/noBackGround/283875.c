#include <stddef.h>

/*@
  requires \valid_read(list1 + (0 .. len1-1));
  requires \valid_read(list2 + (0 .. len2-1));
  requires \valid_read(list3 + (0 .. len3-1));
  assigns \nothing;
  ensures \result >= len1;
  ensures \result >= len2;
  ensures \result >= len3;
  ensures \result == len1 || \result == len2 || \result == len3;
*/
size_t longest_list_length(const int *list1, size_t len1,
                           const int *list2, size_t len2,
                           const int *list3, size_t len3) {
    size_t ret;
    //@ assert ((len1) >= (len1) && (len1) >= (len2) && (len1) >= (len3) &&       ((len1) == (len1) || (len1) == (len2) || (len1) == (len3))) || ((len2) >= (len1) && (len2) >= (len2) && (len2) >= (len3) &&       ((len2) == (len1) || (len2) == (len2) || (len2) == (len3))) || ((len3) >= (len1) && (len3) >= (len2) && (len3) >= (len3) &&       ((len3) == (len1) || (len3) == (len2) || (len3) == (len3)));
    if (len1 >= len2 && len1 >= len3) {
        //@ assert len1 >= len2;
        //@ assert len1 >= len3;
        ret = len1;
    } else if (len2 >= len1 && len2 >= len3) {
        //@ assert len2 >= len1;
        //@ assert len2 >= len3;
        ret = len2;
    } else {
        //@ assert len3 >= len1;
        //@ assert len3 >= len2;
        ret = len3;
    }
    //@ assert ((ret) >= (len1) && (ret) >= (len2) && (ret) >= (len3) &&       ((ret) == (len1) || (ret) == (len2) || (ret) == (len3)));
    return ret;
}
