/*@
predicate is_eq(integer a, integer b) = a == b;
predicate is_le(integer a, integer b) = a <= b;

lemma calc_example_5: is_eq(0, 5 - 5);
lemma calc_example_6: is_eq(2, 5 - 3);
lemma calc_example_7: is_eq(3, 6 - 3);
lemma calc_example_8: is_eq(6, 6);
lemma calc_example_9: is_eq(10, 10);
lemma calc_example_10: is_le(2, 5) ==> is_le(2, 5);
lemma calc_example_11: is_le(2, 5) ==> is_le(2, 5);
*/

int main() {
    //@ assert is_eq(0, 5 - 5);
    //@ assert is_eq(2, 5 - 3);
    //@ assert is_eq(3, 6 - 3);
    //@ assert is_eq(6, 6);
    //@ assert is_eq(10, 10);
    //@ assert is_le(2, 5) ==> is_le(2, 5);
    //@ assert is_le(2, 5) ==> is_le(2, 5);
    
    return 0;
}
