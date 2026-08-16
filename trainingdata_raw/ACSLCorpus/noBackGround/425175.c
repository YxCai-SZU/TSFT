/*@
requires n >= 0;
ensures n * n >= n;
assigns \nothing;
*/
void proof_example_2(int n) {
    //@ assert ((n) >= 0);
    //@ assert n * n >= n;
}

/*@
requires a < b && b < c;
ensures a < c;
assigns \nothing;
*/
void proof_example_3(int a, int b, int c) {
    //@ assert a < b && b < c;
    //@ assert a < c;
}

/*@
requires n >= 0;
ensures n * n >= n;
assigns \nothing;
*/
void proof_example_4(int n) {
    //@ assert ((n) >= 0);
    //@ assert n * n >= n;
}

/*@
assigns \nothing;
*/
int main() {
    int n;
    int a;
    int b;
    int c;
    
    return 0;
}
