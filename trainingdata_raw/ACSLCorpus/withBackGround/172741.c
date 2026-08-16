/*@
    predicate non_empty_seq{L}(int *a, integer len) = len > 0;
    predicate valid_length{L}(int *a, integer len) = len >= 0;
    predicate valid_range{L}(int *a, integer len) = 0 <= len;

    lemma sequence_inequality{L}:
        \forall int *a, integer len_a, int *b, integer len_b;
        non_empty_seq(a, len_a) && non_empty_seq(b, len_b) ==>
        (\forall integer i; 0 <= i < len_a + len_b ==> 
            (i < len_a ? a[i] : b[i - len_a]) == 
            (i < len_a ? a[i] : b[i - len_a]));

    lemma sequence_length{L}:
        \forall int *a, integer len_a;
        non_empty_seq(a, len_a) ==> valid_length(a, len_a);

    lemma range_valid{L}:
        \forall int *a, integer len_a;
        non_empty_seq(a, len_a) ==> valid_range(a, len_a);

    lemma array_range{L}:
        \forall int *a, integer len_a;
        non_empty_seq(a, len_a) ==> valid_range(a, len_a);
*/

/*@
    requires \valid(a + (0..len_a-1)) && \valid(b + (0..len_b-1));
    requires len_a > 0 && len_b > 0;
    ensures \true;
    assigns \nothing;
*/
void prove_sequence_inequality(int *a, int len_a, int *b, int len_b) {
    //@ assert non_empty_seq(a, len_a);
    //@ assert non_empty_seq(b, len_b);
}

/*@
    requires \valid(a + (0..len_a-1));
    requires len_a > 0;
    ensures \true;
    assigns \nothing;
*/
void prove_sequence_length(int *a, int len_a) {
    //@ assert non_empty_seq(a, len_a);
}

/*@
    requires \valid(a + (0..len_a-1));
    requires len_a > 0;
    ensures \true;
    assigns \nothing;
*/
void prove_range_valid(int *a, int len_a) {
    //@ assert non_empty_seq(a, len_a);
}

/*@
    requires \valid(a + (0..len_a-1));
    requires len_a > 0;
    ensures \true;
    assigns \nothing;
*/
void prove_array_range(int *a, int len_a) {
    //@ assert non_empty_seq(a, len_a);
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
