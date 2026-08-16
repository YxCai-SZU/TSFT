/*@
    requires \valid(a) && \valid(b);
    requires *a > 0 && *b > 0;
    ensures *a * *b < *a * (*b + 1);
*/
void example18(int* a, int* b) {
    //@ assert *a > 0 && *b > 0;
    //@ assert *a * *b < *a * (*b + 1);
}

/*@
    requires \valid(x) && \valid(y) && \valid(z);
    requires 0 <= *x <= 8 && 0 <= *y <= 8 && 0 <= *z <= 8;
    ensures *x * *y * *z <= 8 * 8 * 8;
*/
void example19(int* x, int* y, int* z) {
    //@ assert 0 <= *x <= 8 && 0 <= *y <= 8 && 0 <= *z <= 8;
    //@ assert *x * *y <= 8 * 8;
    //@ assert *x * *y * *z <= 8 * 8 * 8;
}

int main() {
    int a = 5;
    int b = 3;
    example18(&a, &b);
    
    int x = 2;
    int y = 4;
    int z = 6;
    example19(&x, &y, &z);
    
    return 0;
}
