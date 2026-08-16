/*@
    requires 0 <= x && x <= 8;
    requires 0 <= y && y <= 8;
    requires z <= 1000;
    requires x * y <= z;
    ensures x * y <= z;
*/
void verify_property(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert (0 <= (x) && (x) <= 8 &&         0 <= (y) && (y) <= 8 &&         (z) <= 1000 &&         (x) * (y) <= (z));
    //@ assert x * y <= z;
}
