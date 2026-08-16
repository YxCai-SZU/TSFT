#include <stdbool.h>

/*@
    predicate has_five_sorted_numbers{L}(int *s, integer len) =
        len == 5 &&
        s[0] <= s[1] &&
        s[1] <= s[2] &&
        s[2] <= s[3] &&
        s[3] <= s[4];

    lemma arithmetic_checks:
        (0 * 10 == 0) &&
        (1 * 10 == 10) &&
        (2 * 10 == 20) &&
        (3 * 10 == 30) &&
        (4 * 10 == 40) &&
        (0 * 10 + 1 == 1) &&
        (1 * 10 + 1 == 11) &&
        (2 * 10 + 1 == 21) &&
        (3 * 10 + 1 == 31) &&
        (4 * 10 + 1 == 41);
*/

/*@
    requires \valid(v + (0..4));
    requires v[0] == 0 && v[1] == 10 && v[2] == 21 && v[3] == 30 && v[4] == 40;
    requires \forall integer i; 0 <= i < 2 ==> v[i] == i * 10;
    requires \forall integer i; 2 <= i < 5 ==> v[i] == i * 10 + 1;
    ensures \result == true;
*/
bool func(int *v) {
    //@ assert 0 * 10 == 0;
    //@ assert 1 * 10 == 10;
    //@ assert 2 * 10 == 20;
    //@ assert 3 * 10 == 30;
    //@ assert 4 * 10 == 40;
    //@ assert 0 * 10 + 1 == 1;
    //@ assert 1 * 10 + 1 == 11;
    //@ assert 2 * 10 + 1 == 21;
    //@ assert 3 * 10 + 1 == 31;
    //@ assert 4 * 10 + 1 == 41;

    //@ assert v[0] == 0 && v[1] == 10 && v[2] == 21 && v[3] == 30 && v[4] == 40;
    //@ assert v[2] == 21;
    //@ assert v[3] == 30;
    //@ assert v[2] == 21 && v[3] == 30;
    //@ assert has_five_sorted_numbers(v, 5);
    return true;
}
