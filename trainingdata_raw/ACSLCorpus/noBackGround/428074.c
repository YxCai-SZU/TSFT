#include <stddef.h>
#include <stdint.h>

/*@
    requires ((N) > 0 && (N) <= 100000 &&
        \forall size_t i; 0 <= i < (N) ==> 1 <= (Hs)[i] <= 1000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(size_t N, const int64_t* Hs) {
    int64_t max_h = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= N;
        loop invariant ((N) > 0 && (N) <= 100000 &&
        \forall size_t i; 0 <= i < (N) ==> 1 <= (Hs)[i] <= 1000000000);
        loop invariant \forall size_t j; 0 <= j < i ==> max_h >= Hs[j];
        loop assigns i, max_h;
        loop variant N - i;
    */
    while (i < N) {
        //@ assert 0 <= i < N && 1 <= Hs[i] <= 1000000000;
        max_h = max_h > Hs[i] ? max_h : Hs[i];
        i++;
    }

    int64_t max_value = 0;
    int64_t current = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= N - 1;
        loop invariant ((N) > 0 && (N) <= 100000 &&
        \forall size_t i; 0 <= i < (N) ==> 1 <= (Hs)[i] <= 1000000000);
        loop invariant current >= 0;
        loop invariant current <= (int64_t)i;
        loop invariant max_value >= 0;
        loop assigns i, current, max_value;
        loop variant N - 1 - i;
    */
    while (i < N - 1) {
        //@ assert 0 <= i < N - 1 && 1 <= Hs[i] <= 1000000000;
        if (max_h <= Hs[i]) {
            current++;
        } else {
            //@ assert current >= 0;
            max_value = max_value > current ? max_value : current;
            current = 0;
        }
        i++;
    }

    //@ assert current >= 0;
    max_value = max_value > current ? max_value : current;
    return max_value;
}
