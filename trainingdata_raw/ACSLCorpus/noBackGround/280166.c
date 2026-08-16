/*@
    requires s1_len == s2_len + 1;
    ensures s1_len > s2_len;
*/
void calc_example_9(int s1_len, int s2_len) {
    //@ assert s1_len == s2_len + 1;
    //@ assert s1_len > s2_len;
}

/*@
    requires l1_len == l2_len + 2;
    ensures l1_len > l2_len;
*/
void calc_example_10(int l1_len, int l2_len) {
    //@ assert l1_len == l2_len + 2;
    //@ assert l1_len > l2_len;
}

int main() {
    int s1_len;
    int s2_len;
    int l1_len;
    int l2_len;
    
    return 0;
}
