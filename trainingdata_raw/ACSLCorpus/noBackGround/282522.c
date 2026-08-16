#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(seq1+(0..len-1)) && \valid(seq2+(0..len-1));
    requires (\forall integer i; 0 <= i < (len) ==> (seq1)[i] == (seq2)[i]);
    ensures \result == 1;
    assigns \nothing;
*/
int test_seq(int **seq1, int **seq2, size_t len) {
    int result;
    //@ assert (\forall integer i; 0 <= i < (len) ==> (seq1)[i] == (seq2)[i]);
    result = 1;
    return result;
}

/*@
    requires \valid(set1+(0..len-1)) && \valid(set2+(0..len-1));
    requires (\forall integer i; 0 <= i < (len) ==> (set1)[i] == (set2)[i]);
    ensures \result == 1;
    assigns \nothing;
*/
int test_set(int **set1, int **set2, size_t len) {
    int result;
    //@ assert (\forall integer i; 0 <= i < (len) ==> (set1)[i] == (set2)[i]);
    result = 1;
    return result;
}

/*@
    requires \valid(map1+(0..len-1)) && \valid(map2+(0..len-1));
    requires (\forall integer i; 0 <= i < (len) ==> (map1)[i] == (map2)[i]);
    ensures \result == 1;
    assigns \nothing;
*/
int test_map(int **map1, int **map2, size_t len) {
    int result;
    //@ assert (\forall integer i; 0 <= i < (len) ==> (map1)[i] == (map2)[i]);
    result = 1;
    return result;
}

/*@
    requires \valid(ms1+(0..len-1)) && \valid(ms2+(0..len-1));
    requires (\forall integer i; 0 <= i < (len) ==> (ms1)[i] == (ms2)[i]);
    ensures \result == 1;
    assigns \nothing;
*/
int test_multiset(int **ms1, int **ms2, size_t len) {
    int result;
    //@ assert (\forall integer i; 0 <= i < (len) ==> (ms1)[i] == (ms2)[i]);
    result = 1;
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
