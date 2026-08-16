#include <stdbool.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 10;

    logic integer compute_num(integer a) = a * 50;

    lemma num_range: \forall integer a; is_valid_a(a) ==> 0 <= compute_num(a) <= 500;
*/

/*@
    requires is_valid_a(a);
    ensures \result == (int)(a * 50) || \result == -1;
    assigns \nothing;
*/
int func(unsigned int a) {
    unsigned int num;
    bool is_divisible;
    unsigned int i;

    //@ assert is_valid_a(a);
    num = a * 50;
    is_divisible = false;
    i = 1;

    /*@
        loop invariant 1 <= i <= 1000;
        loop invariant num == a * 50;
        loop invariant is_divisible == false || is_divisible == true;
        loop invariant is_valid_a(a);
        loop assigns i, is_divisible;
        loop variant 1000 - i;
    */
    while (i < 1000) {
        if (num % i == 0) {
            is_divisible = true;
            break;
        }
        i = i + 1;
    }

    if (is_divisible) {
        //@ assert num == a * 50;
        return (int)num;
    } else {
        return -1;
    }
}
