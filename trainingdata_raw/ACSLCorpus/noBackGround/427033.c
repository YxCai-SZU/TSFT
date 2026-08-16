/*@
    requires ((x) < (y)) && ((y) < (z));
    ensures ((x) + 3 <= (z) + 10);
*/
void complex_calc(int x, int y, int z) {
    //@ assert x < y;
    //@ assert y < z;
    //@ assert x + 3 <= z + 10;
}

int main() {
    return 0;
}
