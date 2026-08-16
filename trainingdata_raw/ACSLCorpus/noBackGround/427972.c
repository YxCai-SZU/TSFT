/*@
    requires x <= 8;
    ensures \result == 0;
    assigns \nothing;
*/
int check_all_x_values(unsigned int x) {
    //@ assert ((x) * (8) == (8) * (x));
    //@ assert ((x) * ((8) * (1)) == ((x) * (8)) * (1));
    //@ assert ((x) * ((8) + (0)) == (x) * (8) + (x) * (0));
    //@ assert x * 8 <= 64;
    return 0;
}

int main() {
    return 0;
}
