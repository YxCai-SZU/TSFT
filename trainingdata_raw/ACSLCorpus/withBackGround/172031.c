#include <stdbool.h>

/*@ predicate is_valid_range(int* arr, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < len ==> 0 <= arr[i] && arr[i] <= 123;
*/

/*@ predicate element_not_found(int* arr, integer len, integer k, integer idx) =
    \forall integer j; 0 <= j < idx ==> arr[j] != k;
*/

/*@ lemma k_in_range: \forall integer k; k >= 0 && k <= 123 ==> (k >= 0 && k <= 123); */

/*@
    requires \valid(x + (0..4));
    requires is_valid_range(x, 5);
    requires k >= 0 && k <= 123;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> \exists integer i; 0 <= i < 5 && x[i] == k;
    ensures \result == 0 ==> \forall integer i; 0 <= i < 5 ==> x[i] != k;
    assigns \nothing;
*/
int func(int* x, int k) {
    int index = 0;
    bool found = false;
    unsigned int i = 0;

    /*@
        loop invariant 0 <= i <= 5;
        loop invariant index == 0;
        loop invariant found == false;
        loop invariant element_not_found(x, 5, k, i);
        loop invariant is_valid_range(x, 5);
        loop invariant k >= 0 && k <= 123;
        loop assigns i, found, index;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == k) {
            found = true;
            index = i;
            break;
        }
        i++;
    }

    if (found) {
        //@ assert \exists integer j; 0 <= j < 5 && x[j] == k;
        return 1;
    } else {
        //@ assert \forall integer j; 0 <= j < 5 ==> x[j] != k;
        return 0;
    }
}

/*@ assigns \nothing; */
int main() {
    return 0;
}
