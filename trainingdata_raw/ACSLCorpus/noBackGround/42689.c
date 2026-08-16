/*@
    requires \valid(v+(0..n-1));
    requires n > 0;
    ensures n >= 0;
*/
void calc_vector_example_1(int* v, int n) {
    //@ assert n > 0;
}

/*@
    requires \valid(v+(0..n-1));
    requires n > 0;
    ensures n > 0;
*/
void calc_vector_example_2(int* v, int n) {
    //@ assert n > 0;
}

/*@
    requires \valid(v+(0..n-1));
    requires n >= 3;
    ensures n >= 3;
*/
void calc_vector_example_3(int* v, int n) {
    //@ assert n >= 3;
}

/*@
    requires \valid(v+(0..n-1));
    requires n <= 10;
    ensures n <= 10;
*/
void calc_vector_example_4(int* v, int n) {
    //@ assert n <= 10;
}

/*@
    requires \valid(v+(0..n-1));
    requires n <= 5;
    ensures n <= 5;
*/
void calc_vector_example_5(int* v, int n) {
    //@ assert n <= 5;
}

/*@
    requires \valid(v+(0..n-1));
    requires n == 5;
    ensures n == 5;
*/
void calc_vector_example_6(int* v, int n) {
    //@ assert n == 5;
}

/*@
    requires \valid(v+(0..n-1));
    requires n >= 2;
    ensures n >= 2;
*/
void calc_vector_example_7(int* v, int n) {
    //@ assert n >= 2;
}

/*@
    requires \valid(v+(0..n-1));
    requires n <= 8;
    ensures n <= 8;
*/
void calc_vector_example_8(int* v, int n) {
    //@ assert n <= 8;
}

/*@
    requires \valid(v+(0..n-1));
    requires n <= 9;
    ensures n <= 9;
*/
void calc_vector_example_9(int* v, int n) {
    //@ assert n <= 9;
}

/*@
    requires \valid(v+(0..n-1));
    requires n >= 10;
    ensures n >= 10;
*/
void calc_vector_example_10(int* v, int n) {
    //@ assert n >= 10;
}

/*@
    requires \valid(v+(0..n-1));
    requires n >= 5 && n <= 20;
    ensures n >= 5 && n <= 20;
*/
void multi_step(int* v, int n) {
    //@ assert n >= 5;
    //@ assert n <= 20;
}

int main() {
    return 0;
}
