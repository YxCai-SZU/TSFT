#include <stdbool.h>

/*@ predicate is_valid_range(int *arr, integer len) =
    len >= 3 &&
    \forall integer i; 0 <= i < 3 ==> 1 <= arr[i] <= 13;
*/

/*@ logic integer sum(integer a, integer b) = a + b; */

/*@ lemma diff_equivalence:
    \forall integer a, b, c;
    (a + b == c) || (a + c == b) || (b + c == a) ==>
    (a + b - c == 0) || (a + c - b == 0) || (b + c - a == 0);
*/


bool func(int *numbers) {
    int a;
    int b;
    int c;
    bool is_pythagorean_triplet;
    int diff1;
    int diff2;
    int diff3;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    is_pythagorean_triplet = false;
    diff1 = a + b - c;
    diff2 = a + c - b;
    diff3 = b + c - a;

    //@ assert diff1 == sum(a, b) - c;
    //@ assert diff2 == sum(a, c) - b;
    //@ assert diff3 == sum(b, c) - a;

    if (diff1 == 0) {
        is_pythagorean_triplet = true;
    } else if (diff2 == 0) {
        is_pythagorean_triplet = true;
    } else if (diff3 == 0) {
        is_pythagorean_triplet = true;
    }

    //@ assert is_pythagorean_triplet == (diff1 == 0 || diff2 == 0 || diff3 == 0);
    return is_pythagorean_triplet;
}
