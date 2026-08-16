/*@
    requires \valid(s+(0..len-1));
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] >= (s)[j]);
    ensures (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] >= (s)[j]);
*/
void reverse_sorted(int *s, int len) {
    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] >= (s)[j]);
}

/*@
    requires \valid(s+(0..len-1));
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] >= (s)[j]);
    ensures (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] >= (s)[j]);
*/
void reverse_sorted_calc(int *s, int len) {
    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] >= (s)[j]);
    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] >= (s)[j]);
}

int main() {
    return 0;
}
