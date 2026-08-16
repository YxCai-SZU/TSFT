/*@
predicate non_negative(integer a) = a >= 0;

lemma no_negative_square_integers: \forall integer a; non_negative(a) ==> a * a >= 0;
lemma non_negative_square_integers: \forall integer a; non_negative(a) ==> a * a >= 0;
lemma square_of_zero_is_zero: \forall integer a; a == 0 ==> a * a == 0;
lemma square_of_one_is_one: \forall integer a; a == 1 ==> a * a == 1;
*/

#include <stdbool.h>

/*@
requires a >= 0;
ensures \result >= 0;
assigns \nothing;
*/
int no_negative_square_integers_func(int a) {
    //@ assert a >= 0;
    int result = a * a;
    //@ assert result >= 0;
    return result;
}

/*@
requires a >= 0;
ensures \result >= 0;
assigns \nothing;
*/
int non_negative_square_integers_func(int a) {
    //@ assert a >= 0;
    int result = a * a;
    //@ assert result >= 0;
    return result;
}

/*@
requires a == 0;
ensures \result == 0;
assigns \nothing;
*/
int square_of_zero_is_zero_func(int a) {
    //@ assert a == 0;
    int result = a * a;
    //@ assert result == 0;
    return result;
}

/*@
requires a == 1;
ensures \result == 1;
assigns \nothing;
*/
int square_of_one_is_one_func(int a) {
    //@ assert a == 1;
    int result = a * a;
    //@ assert result == 1;
    return result;
}

int main() {
    return 0;
}
