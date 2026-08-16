/*@
    requires 0 <= x <= 10;
    requires 0 <= y <= 10;
    requires 0 <= z <= 10;
    ensures \result == (x * y * z <= 1000);
    assigns \nothing;
*/
int check_bound_product(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x * y <= 100;
    //@ assert x * y * z <= 1000;
    return (x * y * z) <= 1000;
}
