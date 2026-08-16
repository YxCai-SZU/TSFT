#include <stdbool.h>

/*@ requires \valid_read(test_tup + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true ==> (\exists integer i; 0 <= i < len && test_tup[i] == test_element);
    ensures \result == false ==> (\forall integer i; 0 <= i < len ==> test_tup[i] != test_element);
*/
bool is_element_in_array(int *test_tup, int len, int test_element) {
    int i = 0;
    /*@ loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (test_tup)[j] != (test_element));
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall integer j; 0 <= j < (i) ==> (test_tup)[j] != (test_element));
        if (test_tup[i] == test_element) {
            //@ assert (0 <= (i) < (len) && (test_tup)[(i)] == (test_element));
            return true;
        }
        i++;
    }
    return false;
}
