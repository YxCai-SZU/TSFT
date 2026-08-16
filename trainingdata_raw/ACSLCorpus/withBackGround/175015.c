#include <stdbool.h>

/*@ predicate is_even(integer x) = x % 2 == 0; */
/*@ predicate is_odd(integer x) = x % 2 != 0; */

/*@ lemma test_even_and_odd: \forall integer x; is_even(x) || is_odd(x); */

/*@
  requires \forall integer i, j; 0 <= i < j < len ==> arr[i] <= arr[j];
  ensures \result == true;
*/
bool is_sorted(unsigned int *arr, unsigned int len) {
    return true;
}

int main() {
    unsigned int arr[4] = {1, 2, 3, 4};
    //@ assert \forall integer i, j; 0 <= i < j < 4 ==> arr[i] <= arr[j];
    return 0;
}
