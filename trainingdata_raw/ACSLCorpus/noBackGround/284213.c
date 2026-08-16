#include <stdbool.h>

/*@ requires \valid(arr + (0..2));
    requires \forall integer i; 0 <= i < 3 ==> ((arr[i]) == (i) + 1 || (arr[i]) == 0);
    requires (\exists integer j; (0) <= j < (3) && (arr)[j] == 0);
    ensures \result >= 1 && \result <= 3;
    ensures arr[\result - 1] == 0;
*/
int find_value(int *arr) {
    int i = 0;
    /*@ loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < 3 ==> ((arr[j]) == (j) + 1 || (arr[j]) == 0);
        loop invariant (\forall integer j; 0 <= j < (i) ==> (arr)[j] != 0);
        loop invariant (\exists integer j; (i) <= j < (3) && (arr)[j] == 0);
        loop assigns i;
    */
    while (i < 3) {
        int e = arr[i];
        if (e == 0) {
            //@ assert arr[i] == 0;
            return i + 1;
        }
        //@ assert arr[i] != 0;
        i++;
    }
    return -1;
}
