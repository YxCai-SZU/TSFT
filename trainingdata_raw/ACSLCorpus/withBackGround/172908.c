/*@
predicate less_than(integer a, integer b) = a < b;
predicate less_eq(integer a, integer b) = a <= b;

lemma calc_example_4: \forall integer a, b, c, d;
    less_eq(a, b) && less_than(b, c) && less_eq(c, d) ==> less_than(a, d);

lemma calc_example_5: \forall integer x, y, z, w;
    less_eq(x, y) && less_than(y, z) && less_eq(z, w) ==> less_than(x, w);
*/

/*@
requires \valid(a) && \valid(b) && \valid(c) && \valid(d);
requires *a <= *b && *b < *c && *c <= *d;
ensures *a < *d;
assigns \nothing;
*/
void calc_example_4_impl(int* a, int* b, int* c, int* d) {
    //@ assert less_eq(*a, *b);
    //@ assert less_than(*b, *c);
    //@ assert less_eq(*c, *d);
    //@ assert less_than(*a, *d);
}

/*@
requires \valid(x) && \valid(y) && \valid(z) && \valid(w);
requires *x <= *y && *y < *z && *z <= *w;
ensures *x < *w;
assigns \nothing;
*/
void calc_example_5_impl(int* x, int* y, int* z, int* w) {
    //@ assert less_eq(*x, *y);
    //@ assert less_than(*y, *z);
    //@ assert less_eq(*z, *w);
    //@ assert less_than(*x, *w);
}

/*@
assigns \nothing;
*/
int main() {
    int a = 0;
    int b = 0;
    int c = 1;
    int d = 1;
    
    int x = 0;
    int y = 0;
    int z = 1;
    int w = 1;
    
    //@ assert a <= b && b < c && c <= d;
    calc_example_4_impl(&a, &b, &c, &d);
    
    //@ assert x <= y && y < z && z <= w;
    calc_example_5_impl(&x, &y, &z, &w);
    
    return 0;
}
