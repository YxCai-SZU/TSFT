/*@
    predicate is_leap_year(integer year) =
        (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
*/

/*@
    predicate is_palindromic_sequence(int *seq, integer len) =
        \forall integer i; 0 <= i < len/2 ==> seq[i] == seq[len - 1 - i];
*/

/*@
    lemma leap_year_examples:
        is_leap_year(2020) &&
        !is_leap_year(1900) &&
        is_leap_year(2000);
*/

#include <stdbool.h>
#include <stddef.h>

/*@
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == true <==> is_palindromic_sequence(seq, len);
*/
bool is_palindromic_sequence(int *seq, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len/2;
        loop invariant \forall integer j; 0 <= j < i ==> seq[j] == seq[len - 1 - j];
        loop assigns i;
        loop variant len/2 - i;
    */
    while (i < len / 2) {
        //@ assert i < len/2;
        if (seq[i] != seq[len - 1 - i]) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    //@ assert is_leap_year(2020);
    //@ assert !is_leap_year(1900);
    //@ assert is_leap_year(2000);
    
    return 0;
}
