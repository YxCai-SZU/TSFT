/*@
    requires \valid(s+(0..len-1));
    requires ((len) >= 3);
    ensures \result == 1;
*/
int calc_example_i(int *s, int len) {
    //@ assert ((len) >= 3);
    //@ assert len > 1;
    //@ assert \forall integer i; 0 <= i < len-2 ==> (s+1)[i] == s[i+1];
    return 1;
}

/*@
    requires \valid(s+(0..len-1));
    requires ((len) >= 2);
    ensures \result == 1;
*/
int calc_example_ii(int *s, int len) {
    //@ assert ((len) >= 2);
    //@ assert s[0] + s[len-1] == s[0] + s[len-1];
    return 1;
}

int main() {
    return 0;
}
