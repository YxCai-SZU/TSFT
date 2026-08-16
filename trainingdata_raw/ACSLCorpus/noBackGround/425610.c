/*@
    requires x >= 0;
    ensures (((x) * 3 + 1) * 3 == (x) * 3 * 3 + 3);
    assigns \nothing;
*/
void calc_example_5(int x) {
    //@ assert x >= 0;
    //@ assert (((x) * 3 + 1) * 3 == (x) * 3 * 3 + 3);
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
