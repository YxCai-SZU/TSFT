#include <stdint.h>

/*@
    predicate valid_x(integer x) = 0 <= x <= 1000000000;

    logic integer five_hundreds(integer x) = x / 500;
    logic integer remainder_after_500(integer x) = x % 500;
    logic integer fives(integer x) = (x % 500) / 5;
    logic integer expected_result(integer x) = 
        (x / 500) * 1000 + ((x % 500) / 5) * 5;

    lemma loop1_invariant_maintained:
        \forall integer x, temp_x, fh;
        valid_x(x) && 0 <= temp_x <= x && fh <= five_hundreds(x) &&
        temp_x == x - fh * 500 ==>
        (temp_x >= 500 ==> 
            (0 <= temp_x - 500 <= x && fh + 1 <= five_hundreds(x) &&
            temp_x - 500 == x - (fh + 1) * 500));

    lemma loop2_invariant_maintained:
        \forall integer x, temp_x, fh, f;
        valid_x(x) && 0 <= temp_x <= x && 
        f <= (x - fh * 500) / 5 &&
        temp_x == x - fh * 500 - f * 5 ==>
        (temp_x >= 5 ==> 
            (0 <= temp_x - 5 <= x && f + 1 <= (x - fh * 500) / 5 &&
            temp_x - 5 == x - fh * 500 - (f + 1) * 5));

    lemma final_result_correct:
        \forall integer x, fh, f;
        valid_x(x) && fh == five_hundreds(x) && f == fives(x) ==>
        fh * 1000 + f * 5 == expected_result(x);
*/

/*@
    requires valid_x(x);
    ensures \result == expected_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t result = 0;
    uint64_t temp_x = x;
    uint64_t five_hundreds = 0;
    uint64_t five = 0;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant five_hundreds <= five_hundreds(x);
        loop invariant temp_x == x - five_hundreds * 500;
        loop invariant valid_x(x);
        loop assigns temp_x, five_hundreds;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        five_hundreds += 1;
        //@ assert temp_x == x - five_hundreds * 500;
    }
    result += five_hundreds * 1000;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant five <= (x - five_hundreds * 500) / 5;
        loop invariant temp_x == x - five_hundreds * 500 - five * 5;
        loop invariant valid_x(x);
        loop assigns temp_x, five;
        loop variant temp_x;
    */
    while (temp_x >= 5) {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        five += 1;
        //@ assert temp_x == x - five_hundreds * 500 - five * 5;
    }
    result += five * 5;

    //@ assert result == expected_result(x);
    return result;
}

int main() {
    return 0;
}
