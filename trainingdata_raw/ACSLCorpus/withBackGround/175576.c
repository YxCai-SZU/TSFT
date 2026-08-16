/*@
    predicate sequence_length_prop_requires(integer seq_len) =
        seq_len >= 5 && seq_len < 10;

    predicate sequence_length_prop_ensures(integer seq_len) =
        seq_len <= 10;

    lemma sequence_length_prop:
        \forall integer seq_len; sequence_length_prop_requires(seq_len) ==> sequence_length_prop_ensures(seq_len);
*/

/*@
    lemma custom_relation: 5 == 5;
*/

/*@
    lemma custom_lessthan_relation: 5 < 10;
*/

/*@
    lemma custom_greaterthan_relation: 10 > 5;
*/

/*@
    lemma custom_equal_greaterthan_relation: 5 <= 5;
*/

/*@
    lemma custom_equal_lessthan_relation: 5 <= 10;
*/

int main() {
    return 0;
}
