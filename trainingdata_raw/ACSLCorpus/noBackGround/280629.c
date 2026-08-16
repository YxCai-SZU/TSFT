/*@
    requires \valid(s+(0..len-1));
    requires len >= 3;
    ensures \forall integer k; 0 <= k < len-2 ==> s[1+k] == s[k+1];
*/
void calc_example_i_common_c(int *s, int len) {
    /*@
        loop invariant 0 <= i <= len-2;
        loop invariant \forall integer k; 0 <= k < i ==> s[1+k] == s[k+1];
        loop assigns i;
    */
    for (int i = 0; i < len-2; i++) {
        //@ assert s[1+i] == s[i+1];
    }
}

int main() {
    return 0;
}
