#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int *p) {
    int res = 0;
    int max = p[0];
    int min = p[0];
    int i = 1;

    //@ assert (1 <= (i) <= (n) &&         (res) >= 0 &&         (res) <= (i) &&         (((n)) > 0 && ((n)) <= 200000 &&         \valid(((p)) + (0 .. ((n))-1)) &&         \forall integer i; 0 <= i < ((n)) ==> 1 <= ((p))[i] <= ((n)) &&         \forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j]) &&         (max) >= (min) &&         \forall integer k; 0 <= k < (i) ==> (p)[k] <= (max) && (p)[k] >= (min) &&         (max) >= 1 &&         (min) <= (n));

    /*@
        loop invariant (1 <= (i) <= (n) &&
        (res) >= 0 &&
        (res) <= (i) &&
        (((n)) > 0 && ((n)) <= 200000 &&
        \valid(((p)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> 1 <= ((p))[i] <= ((n)) &&
        \forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j]) &&
        (max) >= (min) &&
        \forall integer k; 0 <= k < (i) ==> (p)[k] <= (max) && (p)[k] >= (min) &&
        (max) >= 1 &&
        (min) <= (n));
        loop invariant n - i >= 0;
        loop assigns i, res, max, min;
        loop variant n - i;
    */
    while (i < n) {
        int num = p[i];

        //@ assert num >= 1 && num <= n;
        //@ assert \forall integer k; 0 <= k < i ==> p[k] != num;

        if (num <= max && num <= min) {
            res += 1;
        }
        if (max < num) {
            max = num;
        }
        if (min > num) {
            min = num;
        }
        i += 1;

        //@ assert (1 <= (i) <= (n) &&         (res) >= 0 &&         (res) <= (i) &&         (((n)) > 0 && ((n)) <= 200000 &&         \valid(((p)) + (0 .. ((n))-1)) &&         \forall integer i; 0 <= i < ((n)) ==> 1 <= ((p))[i] <= ((n)) &&         \forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j]) &&         (max) >= (min) &&         \forall integer k; 0 <= k < (i) ==> (p)[k] <= (max) && (p)[k] >= (min) &&         (max) >= 1 &&         (min) <= (n));
    }

    //@ assert res >= 0;
    return res;
}
