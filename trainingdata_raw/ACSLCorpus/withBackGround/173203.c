/*@
    predicate is_valid_seq_char{L}(char *s, integer len) =
        len >= 0 && \valid(s + (0 .. len-1));

    predicate is_valid_seq_int{L}(int *v, integer len) =
        len >= 0 && \valid(v + (0 .. len-1));

    predicate is_valid_seq_pair{L}(int *keys, char *vals, integer len) =
        len >= 0 && \valid(keys + (0 .. len-1)) && \valid(vals + (0 .. len-1));

    logic integer seq_char_len{L}(char *s, integer len) = len;

    logic integer seq_int_len{L}(int *v, integer len) = len;

    logic integer seq_pair_len{L}(int *keys, char *vals, integer len) = len;

    lemma calc_example_string_length:
        \forall char *s1, *s2; \forall integer len1, len2;
        is_valid_seq_char(s1, len1) && is_valid_seq_char(s2, len2) &&
        seq_char_len(s1, len1) == 3 && seq_char_len(s2, len2) == 4 ==>
        seq_char_len(s1, len1) + seq_char_len(s2, len2) == 7;

    lemma calc_example_vector_length:
        \forall int *v1, *v2; \forall integer len1, len2;
        is_valid_seq_int(v1, len1) && is_valid_seq_int(v2, len2) &&
        seq_int_len(v1, len1) == 2 && seq_int_len(v2, len2) == 5 ==>
        seq_int_len(v1, len1) + seq_int_len(v2, len2) == 7;

    lemma calc_example_set_length:
        \forall char *s1, *s2; \forall integer len1, len2;
        is_valid_seq_char(s1, len1) && is_valid_seq_char(s2, len2) &&
        seq_char_len(s1, len1) == 3 && seq_char_len(s2, len2) == 4 ==>
        seq_char_len(s1, len1) + seq_char_len(s2, len2) == 7;

    lemma calc_example_map_length:
        \forall int *keys1, *keys2; \forall char *vals1, *vals2;
        \forall integer len1, len2;
        is_valid_seq_pair(keys1, vals1, len1) &&
        is_valid_seq_pair(keys2, vals2, len2) &&
        seq_pair_len(keys1, vals1, len1) == 2 &&
        seq_pair_len(keys2, vals2, len2) == 5 ==>
        seq_pair_len(keys1, vals1, len1) + seq_pair_len(keys2, vals2, len2) == 7;

    lemma calc_example_combined_length:
        \forall char *s1, *s2; \forall int *v;
        \forall integer len1, len2, len3;
        is_valid_seq_char(s1, len1) && is_valid_seq_char(s2, len2) &&
        is_valid_seq_int(v, len3) &&
        seq_char_len(s1, len1) == 3 && seq_char_len(s2, len2) == 4 &&
        seq_int_len(v, len3) == 5 ==>
        seq_char_len(s1, len1) + seq_char_len(s2, len2) + seq_int_len(v, len3) == 12;
*/

int main() {
    return 0;
}
