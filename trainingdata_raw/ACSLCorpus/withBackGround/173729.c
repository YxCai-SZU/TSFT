/*@
    predicate seq_len_positive(integer len) = len > 0;
    predicate seq_len_safe(integer len) = len < 0x80000000;
    predicate seq_len_nonneg(integer len) = len >= 0;
    predicate seq_len_max(integer len) = len <= 0x7FFFFFFF;
*/

/*@
    lemma func_1: \forall integer len; seq_len_positive(len) && seq_len_safe(len) ==> seq_len_nonneg(len);
    lemma func_2: \forall integer len; seq_len_positive(len) && seq_len_safe(len) ==> seq_len_max(len);
    lemma func_3: \forall integer len; seq_len_positive(len) && seq_len_safe(len) ==> seq_len_positive(len);
*/

int main() {
    //@ assert seq_len_positive(5) && seq_len_safe(5) ==> seq_len_positive(5);
    return 0;
}
