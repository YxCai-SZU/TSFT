struct ExtEqualStruct {
    int a;
    int b;
};

/*@
requires \valid(f1) && \valid(f2);
requires ((f1->a) == (f2->a) && (f1->b) == (f2->b));
ensures f1->a == f2->a && f1->b == f2->b;
*/
void proof_struct(struct ExtEqualStruct* f1, struct ExtEqualStruct* f2) {
    //@ assert ((f1->a) == (f2->a) && (f1->b) == (f2->b));
}

int main() {
    struct ExtEqualStruct s1 = {0, 0};
    struct ExtEqualStruct s2 = {0, 0};
    //@ assert ((s1.a) == (s2.a) && (s1.b) == (s2.b));
    proof_struct(&s1, &s2);
    return 0;
}
