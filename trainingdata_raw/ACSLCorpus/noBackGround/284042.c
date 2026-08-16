/*@
    requires ((x) <= 5 && (y) <= 10 && (z) <= 2);
    assigns \nothing;
*/
void mul_comparison(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x * y * z <= 100;
}

/*@
    requires ((x) <= 5 && (y) <= 10 && (z) <= 2);
    assigns \nothing;
*/
void added_bounds_check(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x * y <= 50;
}

/*@
    requires ((x) <= 5 && (y) <= 10 && (z) <= 2);
    assigns \nothing;
*/
void added_bounds_check_diff(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert y * z <= 20;
}

/*@
    requires ((x) <= 5 && (y) <= 10 && (z) <= 2);
    assigns \nothing;
*/
void added_bounds_check_diff_nonlinear(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x * y * z <= 100;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
