/*@
requires \true;
ensures x * (y + z) == (x * y) + (x * z);
*/
void test_distributivity(int x, int y, int z) {
    //@ assert x * (y + z) == (x * y) + (x * z);
}

/*@
requires 0 <= x && 0 <= y && x + y <= 10;
ensures x * y <= 25;
*/
void test_upper_bound(int x, int y) {
    //@ assert x * y <= 25;
}
