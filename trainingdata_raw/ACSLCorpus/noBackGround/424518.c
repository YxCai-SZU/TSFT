#include <stddef.h>
#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100 &&
        1 <= (a) && (a) < (b) && (b) < 20);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
    requires \valid(p + (0 .. n-1));
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, size_t a, size_t b, size_t *p) {
    size_t count[3];
    size_t i;
    size_t min_value;

    // Initialize count array
    count[0] = 0;
    count[1] = 0;
    count[2] = 0;

    i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant (0 <= (i) && (i) <= (n) &&
        (&count[0])[0] >= 0 && (&count[0])[0] <= (i) &&
        (&count[0])[1] >= 0 && (&count[0])[1] <= (i) &&
        (&count[0])[2] >= 0 && (&count[0])[2] <= (i));
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
        loop invariant (3 <= (n) && (n) <= 100 &&
        1 <= (a) && (a) < (b) && (b) < 20);
        loop invariant (\forall integer k; 0 <= k < (i) ==>
            ((p)[k] <= (a) ==> (&count[0])[0] >= 1) &&
            ((p)[k] <= (b) && (p)[k] > (a) ==> (&count[0])[1] >= 1) &&
            ((p)[k] > (b) ==> (&count[0])[2] >= 1));
        loop assigns i, count[0], count[1], count[2];
        loop variant n - i;
    */
    while (i < n) {
        size_t pi = p[i];
        if (pi <= a) {
            //@ assert pi <= a;
            count[0] = count[0] + 1;
        } else if (pi <= b) {
            //@ assert pi > a && pi <= b;
            count[1] = count[1] + 1;
        } else {
            //@ assert pi > b;
            count[2] = count[2] + 1;
        }
        i = i + 1;
    }

    // Find minimum value in count array
    min_value = count[0];
    i = 1;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant min_value >= 0 && min_value <= n;
        loop invariant \forall integer j; 0 <= j < i ==> min_value <= count[j];
        loop invariant (3 <= (n) && (n) <= 100 &&
        1 <= (a) && (a) < (b) && (b) < 20);
        loop invariant \forall integer k; 0 <= k < 3 ==> count[k] >= 0 && count[k] <= n;
        loop assigns i, min_value;
        loop variant 3 - i;
    */
    while (i < 3) {
        if (count[i] < min_value) {
            min_value = count[i];
        }
        i = i + 1;
    }

    //@ assert 0 <= min_value <= n;
    return min_value;
}
