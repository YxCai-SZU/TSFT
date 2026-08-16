/*@
requires a > 0 && b > 0 && c > 0;
ensures \result == 0;
assigns \nothing;
*/
int verify_non_linear_arith_example(int a, int b, int c) {
    //@ assert a * (b + c) <= a * b + a * c;
    return 0;
}

/*@
requires x > 0 && y > 0 && z > 0;
ensures \result == 0;
assigns \nothing;
*/
int verify_non_linear_arith_example2(int x, int y, int z) {
    //@ assert x * (y + z) <= x * y + x * z;
    return 0;
}

/*@
requires d > 0 && e > 0 && f > 0;
ensures \result == 0;
assigns \nothing;
*/
int verify_non_linear_arith_example3(int d, int e, int f) {
    //@ assert d * (e + f) <= d * e + d * f;
    return 0;
}

/*@
requires k > 0 && l > 0 && m > 0;
ensures \result == 0;
assigns \nothing;
*/
int verify_non_linear_arith_example4(int k, int l, int m) {
    //@ assert k * (l + m) <= k * l + k * m;
    return 0;
}

int main() {
    int a, b, c;
    int x, y, z;
    int d, e, f;
    int k, l, m;
    
    a = 1; b = 1; c = 1;
    verify_non_linear_arith_example(a, b, c);
    
    x = 1; y = 1; z = 1;
    verify_non_linear_arith_example2(x, y, z);
    
    d = 1; e = 1; f = 1;
    verify_non_linear_arith_example3(d, e, f);
    
    k = 1; l = 1; m = 1;
    verify_non_linear_arith_example4(k, l, m);
    
    return 0;
}
