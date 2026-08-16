/*@
    requires \true;
    ensures \true;
*/
int main() {
    /*@ assert ((1) != (2) && (2) != (3) && (1) != (3)); */
    /*@ assert !((1) != (1) && (1) != (2) && (1) != (2)); */
    return 0;
}
