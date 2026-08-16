/*@
    requires ((x) >= 0 && (x) <= 100) && ((y) >= 0 && (y) <= 100);
    ensures ((x) * (y) >= 0 && (x) * (y) <= 10000);
*/
void verify_product_bounds(int x, int y) {
    //@ assert ((x) >= 0);
    //@ assert ((y) >= 0);
    //@ assert x * y <= 10000;
    //@ assert x * y >= 0;
}

int main() {
    return 0;
}
