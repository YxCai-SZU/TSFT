/*@
predicate seq_equal{L}(int *a, int *b, integer len) =
    \forall integer i; 0 <= i < len ==> a[i] == b[i];

lemma seqs_ext_equal:
    \forall int *s1, *s2, integer len;
        (\forall integer i; 0 <= i < len ==> s1[i] == s2[i]) ==>
        seq_equal(s1, s2, len);
*/

typedef struct {
    int *a;
    int len;
} Bar;

/*@
predicate bar_equal{L}(Bar b1, Bar b2) =
    b1.len == b2.len && seq_equal(b1.a, b2.a, b1.len);

lemma ext_equal_struct:
    \forall Bar b1, b2; bar_equal(b1, b2) ==> b1.len == b2.len;
*/

int main() {
    int s1_arr[3] = {1, 2, 3};
    int s2_arr[3] = {1, 2, 3};
    Bar b1 = {s1_arr, 3};
    Bar b2 = {s2_arr, 3};
    
    //@ assert bar_equal(b1, b2);
    
    return 0;
}
