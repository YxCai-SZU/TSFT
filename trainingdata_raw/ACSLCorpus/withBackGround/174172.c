#include <stddef.h>

/*@
    predicate nestedseqs_ext_equal{L}(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];
    
    lemma nestedseqs_ext_equal_lemma:
        \forall int *s1, *s2, integer len;
        nestedseqs_ext_equal(s1, s2, len) ==>
        (\forall integer i; 0 <= i < len ==> s1[i] == s2[i]);
*/

struct NestedSeq {
    int **seq;
    size_t outer_len;
    size_t *inner_lens;
};

/*@
    predicate valid_nestedseq(struct NestedSeq ns) =
        ns.seq != NULL &&
        ns.inner_lens != NULL &&
        \forall integer i; 0 <= i < ns.outer_len ==> 
            ns.seq[i] != NULL;
    
    predicate nestedseqs_ext_equal_struct{L}(struct NestedSeq ns1, struct NestedSeq ns2) =
        ns1.outer_len == ns2.outer_len &&
        \forall integer i; 0 <= i < ns1.outer_len ==>
            ns1.inner_lens[i] == ns2.inner_lens[i] &&
            nestedseqs_ext_equal(ns1.seq[i], ns2.seq[i], ns1.inner_lens[i]);
    
    lemma nestedseqs_ext_equal_struct_lemma:
        \forall struct NestedSeq ns1, ns2;
        nestedseqs_ext_equal_struct(ns1, ns2) ==>
        ns1.outer_len == ns2.outer_len &&
        (\forall integer i; 0 <= i < ns1.outer_len ==>
            ns1.inner_lens[i] == ns2.inner_lens[i] &&
            (\forall integer j; 0 <= j < ns1.inner_lens[i] ==> 
                ns1.seq[i][j] == ns2.seq[i][j]));
*/

int main() {
    struct NestedSeq ns1;
    struct NestedSeq ns2;
    
    //@ assert \true;
    
    return 0;
}
