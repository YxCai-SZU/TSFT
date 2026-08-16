/*@
    requires n < 1000;
    ensures \result <= (n + 1) * n / 2;
    assigns \nothing;
*/
unsigned int is_triangular(unsigned int n) {
    //@ assert n * (n + 1) <= (unsigned long long)n * ((unsigned long long)n + 1);
    return n * (n + 1) / 2;
}
