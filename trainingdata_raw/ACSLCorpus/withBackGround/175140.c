/*@
predicate precondition_intermediate_example_2(integer x, integer y) = x == y - 2;
predicate postcondition_intermediate_example_2(integer x, integer y) = x <= y;
lemma intermediate_example_2: \forall integer x, y; precondition_intermediate_example_2(x, y) ==> postcondition_intermediate_example_2(x, y);
*/

/*@
predicate precondition_strong_chain(integer x) = x < 5;
predicate postcondition_strong_chain(integer x) = x + 1 < 6;
lemma strong_chain: \forall integer x; precondition_strong_chain(x) ==> postcondition_strong_chain(x);
*/

/*@
predicate precondition_weak_chain(integer x) = x > 5;
predicate postcondition_weak_chain(integer x) = x - 1 > 4;
lemma weak_chain: \forall integer x; precondition_weak_chain(x) ==> postcondition_weak_chain(x);
*/

/*@
predicate precondition_equal_chain(integer x) = x == 5;
predicate postcondition_equal_chain(integer x) = x + 1 == 6;
lemma equal_chain: \forall integer x; precondition_equal_chain(x) ==> postcondition_equal_chain(x);
*/

/*@
predicate precondition_decreasing_chain(integer x) = x > 5;
predicate postcondition_decreasing_chain(integer x) = x - 1 > 4;
lemma decreasing_chain: \forall integer x; precondition_decreasing_chain(x) ==> postcondition_decreasing_chain(x);
*/

/*@
predicate precondition_increasing_chain(integer x) = x < 5;
predicate postcondition_increasing_chain(integer x) = x + 1 < 6;
lemma increasing_chain: \forall integer x; precondition_increasing_chain(x) ==> postcondition_increasing_chain(x);
*/

/*@
predicate precondition_same_value_chain(integer x) = x == 5;
predicate postcondition_same_value_chain(integer x) = x == 5;
lemma same_value_chain: \forall integer x; precondition_same_value_chain(x) ==> postcondition_same_value_chain(x);
*/

/*@
predicate precondition_two_element_chain(integer x) = x < 6;
predicate postcondition_two_element_chain(integer x) = x + 1 < 7;
lemma two_element_chain: \forall integer x; precondition_two_element_chain(x) ==> postcondition_two_element_chain(x);
*/

/*@
predicate precondition_three_element_chain(integer x) = x < 7;
predicate postcondition_three_element_chain(integer x) = x + 2 < 9;
lemma three_element_chain: \forall integer x; precondition_three_element_chain(x) ==> postcondition_three_element_chain(x);
*/

/*@
predicate precondition_four_element_chain(integer x) = x < 8;
predicate postcondition_four_element_chain(integer x) = x + 3 < 11;
lemma four_element_chain: \forall integer x; precondition_four_element_chain(x) ==> postcondition_four_element_chain(x);
*/

/*@
predicate precondition_five_element_chain(integer x) = x < 9;
predicate postcondition_five_element_chain(integer x) = x + 4 < 13;
lemma five_element_chain: \forall integer x; precondition_five_element_chain(x) ==> postcondition_five_element_chain(x);
*/

/*@
predicate precondition_six_element_chain(integer x) = x < 10;
predicate postcondition_six_element_chain(integer x) = x + 5 < 15;
lemma six_element_chain: \forall integer x; precondition_six_element_chain(x) ==> postcondition_six_element_chain(x);
*/

/*@
predicate precondition_seven_element_chain(integer x) = x < 11;
predicate postcondition_seven_element_chain(integer x) = x + 6 < 17;
lemma seven_element_chain: \forall integer x; precondition_seven_element_chain(x) ==> postcondition_seven_element_chain(x);
*/

/*@
predicate precondition_eight_element_chain(integer x) = x < 12;
predicate postcondition_eight_element_chain(integer x) = x + 7 < 19;
lemma eight_element_chain: \forall integer x; precondition_eight_element_chain(x) ==> postcondition_eight_element_chain(x);
*/

/*@
predicate precondition_nine_element_chain(integer x) = x < 13;
predicate postcondition_nine_element_chain(integer x) = x + 8 < 21;
lemma nine_element_chain: \forall integer x; precondition_nine_element_chain(x) ==> postcondition_nine_element_chain(x);
*/

/*@
predicate precondition_ten_element_chain(integer x) = x < 14;
predicate postcondition_ten_element_chain(integer x) = x + 9 < 23;
lemma ten_element_chain: \forall integer x; precondition_ten_element_chain(x) ==> postcondition_ten_element_chain(x);
*/

/*@
predicate precondition_eleven_element_chain(integer x) = x < 15;
predicate postcondition_eleven_element_chain(integer x) = x + 10 < 25;
lemma eleven_element_chain: \forall integer x; precondition_eleven_element_chain(x) ==> postcondition_eleven_element_chain(x);
*/

int main() {
    return 0;
}
