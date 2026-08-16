/*@
    requires \true;
    ensures \true;
*/
void test_max_val_greater(void) {
    //@ assert \forall integer x, y; (((x) > (y)) ? (x) : (y)) >= x && (((x) > (y)) ? (x) : (y)) >= y;
}

int main() {
    return 0;
}
