/*@
    requires \valid_read(A + (0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) - 1 ==> (A)[i] < (A)[i + 1]);
    ensures \result == 0 <==> !(\forall integer i; 0 <= i < (len) - 1 ==> (A)[i] < (A)[i + 1]);
 */
int is_strictly_increasing(int *A, int len) {
    int i;
    
    if (len <= 1) {
        return 1;
    }
    
    i = 1;
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i - 1 ==> A[j] < A[j + 1];
        loop assigns i;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert 0 <= i - 1 < len;
        if (A[i] <= A[i - 1]) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}

/*@
    assigns \nothing;
 */
int main() {
    return 0;
}
