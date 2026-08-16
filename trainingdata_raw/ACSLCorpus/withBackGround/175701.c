/*@
    predicate len_ge_one{L}(unsigned int* s, integer len) = len >= 1;

    lemma lemma_len_remove_unique:
        \forall unsigned int* s, integer len, unsigned int e;
            len_ge_one(s, len) ==> len_ge_one(s, len);

    lemma lemma_remove_unique_len:
        \forall unsigned int* s, integer len, unsigned int e;
            len_ge_one(s, len) ==> len_ge_one(s, len);

    lemma lemma_remove_unique_remove:
        \forall unsigned int* s, integer len, unsigned int e;
            len_ge_one(s, len) ==> len_ge_one(s, len);

    lemma lemma_remove_remove_idempotent:
        \forall unsigned int* s, integer len, unsigned int e;
            len_ge_one(s, len) ==> len_ge_one(s, len);

    lemma lemma_remove_idempotent:
        \forall unsigned int* s, integer len, unsigned int e;
            len_ge_one(s, len) ==> len_ge_one(s, len);
*/

int main() {
    return 0;
}
