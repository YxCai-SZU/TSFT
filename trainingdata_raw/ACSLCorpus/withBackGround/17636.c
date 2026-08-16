#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;

    lemma proof_main:
        is_even(2) &&
        !is_even(3) &&
        (is_even(2) || !is_even(2) || is_even(3) || !is_even(3));
*/

int main() {
    //@ assert is_even(2);
    //@ assert !is_even(3);
    //@ assert is_even(2) || !is_even(2) || is_even(3) || !is_even(3);
    
    return 0;
}
