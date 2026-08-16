#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_below(unsigned int *arr, integer len, unsigned int threshold) =
      \forall integer i; 0 <= i < len ==> arr[i] < threshold;
*/

/*@
  requires \valid_read(arr + (0 .. len-1));
  assigns \nothing;
  ensures \result == true <==> all_below(arr, len, threshold);
*/
bool func(unsigned int *arr, size_t len, unsigned int threshold) {
    size_t index = 0;
    /*@
      loop invariant 0 <= index <= len;
      loop invariant \forall integer i; 0 <= i < index ==> arr[i] < threshold;
      loop assigns index;
      loop variant len - index;
    */
    while (index < len) {
        //@ assert 0 <= index < len;
        if (arr[index] >= threshold) {
            return false;
        }
        index = index + 1;
    }
    return true;
}

/*@ lemma all_below_empty: \forall unsigned int t; all_below((unsigned int*)0, 0, t); */

#ifdef TESTING
#include <assert.h>
int main() {
    unsigned int test1[] = {1, 2, 3, 4, 5};
    assert(func(test1, 5, 6) == true);
    
    unsigned int test2[] = {1, 2, 3, 4, 6};
    assert(func(test2, 5, 6) == false);
    
    return 0;
}
#endif
