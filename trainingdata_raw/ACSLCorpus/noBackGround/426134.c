#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(list1 + (0 .. len-1));
    requires \valid_read(list2 + (0 .. len-1));
    requires len >= 0;
    requires (\forall integer i; 0 <= i < (len) ==> (list1)[i] == (list2)[i]);
    ensures (\forall integer i; 0 <= i < (len) ==> (list1)[i] == (list2)[i]);
*/
void nontrivial_list_example(int *list1, int *list2, size_t len) {
    //@ assert (\forall integer i; 0 <= i < (len) ==> (list1)[i] == (list2)[i]);
}
