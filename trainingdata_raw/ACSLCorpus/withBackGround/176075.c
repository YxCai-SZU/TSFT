/*@
predicate seq_equal{L}(int *a, int *b, integer len) =
    \forall integer i; 0 <= i < len ==> a[i] == b[i];

predicate set_equal{L}(int *a, int *b, integer len) =
    \forall integer i; 0 <= i < len ==> (\exists integer j; 0 <= j < len && a[i] == b[j]) &&
    \forall integer j; 0 <= j < len ==> (\exists integer i; 0 <= i < len && a[i] == b[j]);

predicate map_equal{L}(int *keys_a, int *vals_a, int *keys_b, int *vals_b, integer len) =
    \forall integer i; 0 <= i < len ==> 
        (\exists integer j; 0 <= j < len && keys_a[i] == keys_b[j] && vals_a[i] == vals_b[j]) &&
    \forall integer j; 0 <= j < len ==> 
        (\exists integer i; 0 <= i < len && keys_a[i] == keys_b[j] && vals_a[i] == vals_b[j]);

lemma two_equal_lemma:
    \forall int *a, int *b, integer len;
        seq_equal(a, b, len) ==> \forall integer i; 0 <= i < len ==> a[i] == b[i];

lemma two_equal_set_lemma:
    \forall int *a, int *b, integer len;
        set_equal(a, b, len) ==> \forall integer i; 0 <= i < len ==> (\exists integer j; 0 <= j < len && a[i] == b[j]);

lemma two_equal_map_lemma:
    \forall int *keys_a, int *vals_a, int *keys_b, int *vals_b, integer len;
        map_equal(keys_a, vals_a, keys_b, vals_b, len) ==>
        \forall integer i; 0 <= i < len ==> 
            (\exists integer j; 0 <= j < len && keys_a[i] == keys_b[j] && vals_a[i] == vals_b[j]);
*/

/*@
requires \valid(a+(0..len-1)) && \valid(b+(0..len-1));
requires seq_equal(a, b, len);
ensures \forall integer i; 0 <= i < len ==> a[i] == b[i];
*/
void two_equal(int *a, int *b, int len) {
    //@ assert seq_equal(a, b, len);
    //@ assert \forall integer i; 0 <= i < len ==> a[i] == b[i];
}

/*@
requires \valid(a+(0..len-1)) && \valid(b+(0..len-1));
requires set_equal(a, b, len);
ensures \forall integer i; 0 <= i < len ==> (\exists integer j; 0 <= j < len && a[i] == b[j]);
*/
void two_equal_set(int *a, int *b, int len) {
    //@ assert set_equal(a, b, len);
    //@ assert \forall integer i; 0 <= i < len ==> (\exists integer j; 0 <= j < len && a[i] == b[j]);
}

/*@
requires \valid(keys_a+(0..len-1)) && \valid(vals_a+(0..len-1));
requires \valid(keys_b+(0..len-1)) && \valid(vals_b+(0..len-1));
requires map_equal(keys_a, vals_a, keys_b, vals_b, len);
ensures \forall integer i; 0 <= i < len ==> 
    (\exists integer j; 0 <= j < len && keys_a[i] == keys_b[j] && vals_a[i] == vals_b[j]);
*/
void two_equal_map(int *keys_a, int *vals_a, int *keys_b, int *vals_b, int len) {
    //@ assert map_equal(keys_a, vals_a, keys_b, vals_b, len);
    //@ assert \forall integer i; 0 <= i < len ==> (\exists integer j; 0 <= j < len && keys_a[i] == keys_b[j] && vals_a[i] == vals_b[j]);
}

int main() {
    return 0;
}
