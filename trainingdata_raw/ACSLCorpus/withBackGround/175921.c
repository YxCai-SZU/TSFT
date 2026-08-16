#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_array(unsigned long *arr, size_t len) =
        len > 0 &&
        \forall size_t i; 0 <= i < len ==> arr[i] > 0;

    predicate count_condition(unsigned long *arr, size_t len, size_t k, size_t cnt) =
        cnt <= len &&
        \forall size_t i; 0 <= i < len ==> (arr[i] >= k ==> cnt > 0);
*/

/*@
    requires k > 0;
    requires \valid(h + (0 .. len-1));
    requires valid_array(h, len);
    assigns \nothing;
    ensures count_condition(h, len, k, \result);
*/
size_t func(size_t k, unsigned long *h, size_t len) {
    size_t count = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= len;
        loop invariant count <= index;
        loop invariant \forall size_t i; 0 <= i < index ==> (h[i] >= k ==> count > 0);
        loop invariant valid_array(h, len);
        loop invariant k > 0;
        loop assigns count, index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert 0 <= index < len;
        if (h[index] >= k) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
