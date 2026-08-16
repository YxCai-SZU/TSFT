/*@
  requires x > 0 && y > 0 && z > 0;
  ensures \result == 0;
*/
int non_linear_arith_example2(int x, int y, int z) {
    //@ assert x * y == y * x;
    //@ assert x * (y * z) == (x * y) * z;
    //@ assert x * (y + z) == x * y + x * z;
    return 0;
}

int main() {
    return 0;
}
