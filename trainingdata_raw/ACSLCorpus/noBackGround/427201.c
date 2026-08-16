/*@
requires ((a) * ((b) + (c)) == (a) * (b) + (a) * (c));
ensures a * (b + c) == a * b + a * c;
*/
void right_distributive_mul(int a, int b, int c) {
    //@ assert a * (b + c) == a * b + a * c;
}

int main() {
    return 0;
}
