/*@
    requires len >= 0;
    requires \valid_read(s1+(0..len-1));
    requires \valid_read(s2+(0..len-1));
    requires \forall integer i; 0 <= i < len ==> s1[i] == s2[i];
    ensures (\forall integer i; 0 <= i < (len) ==> (s1)[i] == (s2)[i]);
*/
void seqs_ext_equal(int *s1, int *s2, int len) {
    //@ assert (\forall integer i; 0 <= i < (len) ==> (s1)[i] == (s2)[i]);
}

int main() {
    return 0;
}
