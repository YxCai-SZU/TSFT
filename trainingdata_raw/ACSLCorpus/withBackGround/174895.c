/*@
predicate seq_len_between(integer len) = 5 <= len && len < 10;

lemma sequence_length_prop:
    \forall integer seq_len; seq_len_between(seq_len) ==> seq_len <= 10;

lemma integer_chain:
    \forall integer n; 0 <= n && n <= 100 ==> n <= 200;

lemma even_integer_chain:
    \forall integer n; 0 <= n && n <= 100 && n % 2 == 0 ==> n <= 200;
*/

int main() {
    //@ assert 5 <= 10;
    return 0;
}
