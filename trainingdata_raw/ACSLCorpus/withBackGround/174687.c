/*@
    predicate is_convertor(integer x, integer k, integer result) =
        result == x;

    predicate is_divisor(integer x, integer k, integer result) =
        (k >= x ==> result == k - x) &&
        (k < x ==> result == 0);

    predicate is_incrementor(integer x, integer k, integer result) =
        result == k + x;
*/

/*@
    lemma test_sub:
        \forall integer x, k;
            is_convertor(5, k, x) ==> x == 5;
*/

/*@
    lemma test_divisor:
        \forall integer k, result;
            (k >= 5 && is_divisor(5, k, result) ==> result == k - 5) &&
            (k < 5 && is_divisor(5, k, result) ==> result == 0);
*/

/*@
    lemma test_incrementor:
        \forall integer k, result;
            is_incrementor(5, k, result) ==> result == k + 5;
*/

/*@
    lemma compare_increments:
        \forall integer k, result_f, result_g;
            (k >= 0 ==> 
                (is_incrementor(5, k, result_f) &&
                 is_divisor(5, k, result_g) ==>
                 result_f > result_g));
*/

/*@
    lemma assert_x_greater_than_y:
        \forall integer x, y, k, result_x, result_y;
            x > y &&
            is_convertor(x, k, result_x) &&
            is_convertor(y, k, result_y) ==>
            result_x > result_y;
*/

/*@
    requires \true;
    assigns \nothing;
*/
int main() {
    //@ assert \true;
    return 0;
}
