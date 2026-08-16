#include <stdbool.h>

/*@
    predicate seq_eq(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    predicate set_eq(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    predicate map_eq(int *k1, int *v1, int *k2, int *v2, integer len) =
        \forall integer i; 0 <= i < len ==> k1[i] == k2[i] && v1[i] == v2[i];
*/

struct SimilarData {
    int *seq1;
    int seq1_len;
    int *set1;
    int set1_len;
    int *map1_keys;
    int *map1_vals;
    int map1_len;
};

/*@
    predicate similar_data_eq(struct SimilarData s1, struct SimilarData s2) =
        s1.seq1_len == s2.seq1_len &&
        s1.set1_len == s2.set1_len &&
        s1.map1_len == s2.map1_len &&
        seq_eq(s1.seq1, s2.seq1, s1.seq1_len) &&
        set_eq(s1.set1, s2.set1, s1.set1_len) &&
        map_eq(s1.map1_keys, s1.map1_vals, s2.map1_keys, s2.map1_vals, s1.map1_len);
*/

/*@
    lemma similar_data_equality:
        \forall struct SimilarData s1, s2;
            similar_data_eq(s1, s2) ==> s1.seq1_len == s2.seq1_len;
*/

struct NestedSimilarData {
    struct SimilarData *seq1;
    int seq1_len;
    struct SimilarData *set1;
    int set1_len;
    struct SimilarData *map1_vals;
    int *map1_keys;
    int map1_len;
};

/*@
    predicate nested_seq_eq(struct SimilarData *s1, struct SimilarData *s2, integer len) =
        \forall integer i; 0 <= i < len ==> similar_data_eq(s1[i], s2[i]);

    predicate nested_set_eq(struct SimilarData *s1, struct SimilarData *s2, integer len) =
        \forall integer i; 0 <= i < len ==> similar_data_eq(s1[i], s2[i]);

    predicate nested_map_eq(int *keys, struct SimilarData *v1, struct SimilarData *v2, integer len) =
        \forall integer i; 0 <= i < len ==> similar_data_eq(v1[i], v2[i]);
*/

/*@
    predicate nested_similar_data_eq(struct NestedSimilarData s1, struct NestedSimilarData s2) =
        s1.seq1_len == s2.seq1_len &&
        s1.set1_len == s2.set1_len &&
        s1.map1_len == s2.map1_len &&
        nested_seq_eq(s1.seq1, s2.seq1, s1.seq1_len) &&
        nested_set_eq(s1.set1, s2.set1, s1.set1_len) &&
        nested_map_eq(s1.map1_keys, s1.map1_vals, s2.map1_vals, s1.map1_len);
*/

/*@
    lemma nested_similar_data_equality:
        \forall struct NestedSimilarData s1, s2;
            nested_similar_data_eq(s1, s2) ==> s1.seq1_len == s2.seq1_len;
*/

/*@
    lemma nested_similar_data_equality_deep:
        \forall struct NestedSimilarData s1, s2;
            nested_similar_data_eq(s1, s2) ==> s1.set1_len == s2.set1_len;
*/

int main() {
    return 0;
}
