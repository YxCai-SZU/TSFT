#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(a + (0..4));
    requires ((5) == 5 &&
      (\forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] <= 123) &&
      (a)[0] < (a)[1] && (a)[1] < (a)[2] && (a)[2] < (a)[3] && (a)[3] < (a)[4]);
    requires 0 <= k <= 123;
    assigns \nothing;
    ensures ((\result) == ((a)[4] - (a)[0] <= (k)));
*/
bool func(int* a, int k) {
    int array[5];
    size_t i = 0;

    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> array[j] == a[j];
        loop assigns i, array[0..4];
        loop variant 5 - i;
    */
    while (i < 5) {
        array[i] = a[i];
        i++;
    }

    int first = array[0];
    int last = array[4];

    //@ assert last - first <= 123;
    return last - first <= k;
}
