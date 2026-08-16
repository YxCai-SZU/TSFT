/*@
    requires \valid(a) && \valid(b) && \valid(c);
    requires ((*a) + (*b) == (*c));
    ensures *a <= *c - *b;
    assigns \nothing;
*/
void calc_example_1(int* a, int* b, int* c) {
    //@ assert ((*a) + (*b) == (*c));
    //@ assert *a <= *c - *b;
}

/*@
    requires \valid(x) && \valid(y);
    requires ((*x) < (*y)) && ((*x) + 1 == (*y));
    ensures ((*x) < (*y));
    assigns \nothing;
*/
void example2(int* x, int* y) {
    //@ assert ((*x) < (*y));
    //@ assert ((*x) + 1 == (*y));
    //@ assert ((*x) < (*y));
}

int main() {
    int a = 5;
    int b = 3;
    int c = 8;
    int x = 2;
    int y = 3;
    
    calc_example_1(&a, &b, &c);
    example2(&x, &y);
    
    return 0;
}
