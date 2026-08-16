/*@
  requires x >= 0;
  ensures \result >= x + 3;
*/
int linear_arithmetic(int x) {
    //@ assert 2 * x >= x;
    //@ assert x <= x + 3;
    //@ assert 2 * x + 3 >= x + 3;
    return 2 * x + 3;
}

int main() {
    return 0;
}
