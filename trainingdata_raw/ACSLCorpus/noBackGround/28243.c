/*@
    requires \valid(a) && \valid(b);
    requires *a >= 1 && *b >= 1;
    ensures *a + *b >= 2;
    assigns \nothing;
*/
void proof_inequality_holds(int* a, int* b) {
    //@ assert *a >= 1 && *b >= 1;
    //@ assert *a + *b >= 2;
}

/*@
    requires \valid(x) && \valid(y);
    requires *x < *y;
    ensures *x + 2 < *y + 3;
    assigns \nothing;
*/
void calc_example_6(int* x, int* y) {
    //@ assert *x < *y;
    //@ assert *x + 2 < *y + 3;
}

int main() {
    return 0;
}
