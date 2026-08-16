/*@
    requires \valid(out);
    requires a >= 0 && a <= 100;
    requires b >= 0 && b <= 100;
    assigns *out;
    ensures *out == a * b;
    ensures *out <= 10000;
*/
void compute_product(int a, int b, int *out) {
    int result;
    result = a * b;
    
    //@ assert ((a) >= 0 && (a) <= 100);
    //@ assert ((b) >= 0 && (b) <= 100);
    //@ assert ((a) * (b) <= 10000);
    
    *out = result;
}

int main() {
    int x = 50;
    int y = 50;
    int product;
    
    compute_product(x, y, &product);
    return 0;
}
