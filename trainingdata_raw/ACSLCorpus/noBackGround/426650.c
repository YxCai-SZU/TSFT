struct MyStruct {
    int *s;
    int len;
};

/*@
    requires \valid(s1) && \valid(s2);
    requires len >= 0;
    requires \valid(s1->s+(0..len-1)) && \valid(s2->s+(0..len-1));
    requires \forall integer i; 0 <= i < len ==> s1->s[i] == s2->s[i];
    ensures \result == 1;
    assigns \nothing;
*/
int my_struct_equal(struct MyStruct *s1, struct MyStruct *s2, int len) {
    //@ assert \forall integer i; 0 <= i < len ==> s1->s[i] == s2->s[i];
    return 1;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
