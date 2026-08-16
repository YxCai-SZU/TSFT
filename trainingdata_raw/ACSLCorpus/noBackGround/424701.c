/*@
    requires (-1000 <= (x) && (x) <= 1000);
    ensures \result == (2 * (x));
    assigns \nothing;
*/
int double_value(int x) {
    //@ assert (-1000 <= (x) && (x) <= 1000);
    return x * 2;
}

/*@
    requires (-1000 <= (x) && (x) <= 1000);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int square_value(int x) {
    //@ assert (-1000 <= (x) && (x) <= 1000);
    //@ assert -1000000 <= x * x && x * x <= 1000000;
    return x * x;
}

int main() {
    return 0;
}
