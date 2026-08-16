/*@
requires a < b;
ensures \result == 0;
*/
int calc_example_v(int a, int b) {
    //@ assert ((a) < (b));
    //@ assert ((a) - 1) < ((b) - 1);
    return 0;
}

/*@
requires a < b && b < c;
ensures \result == 0;
*/
int calc_example_v2(int a, int b, int c) {
    //@ assert ((a) < (b));
    //@ assert ((b) < (c));
    //@ assert ((a) - 1) < ((b) - 1);
    //@ assert ((b) - 1) < ((c) - 1);
    return 0;
}

int main() {
    int a = 5;
    int b = 10;
    int c = 15;
    
    //@ assert ((a) < (b));
    //@ assert ((b) < (c));
    
    calc_example_v(a, b);
    calc_example_v2(a, b, c);
    
    return 0;
}
