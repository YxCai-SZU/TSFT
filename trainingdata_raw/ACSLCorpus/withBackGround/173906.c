/*@
    logic integer min_int(integer x, integer y) = (x <= y) ? x : y;

    lemma min_int_properties:
        \forall integer x, y;
            min_int(x, y) <= x &&
            min_int(x, y) <= y &&
            (min_int(x, y) == x || min_int(x, y) == y);
*/

/*@
    requires \true;
    ensures \true;
*/
void M2_test(void) {
    //@ assert min_int(10, 20) == 10;
}

/*@
    requires \true;
    ensures \true;
*/
void M3_test(void) {
    //@ assert min_int(10, 20) == 10;
    //@ assert min_int(100, 200) == 100;
}

int main(void) {
    M2_test();
    M3_test();
    return 0;
}
