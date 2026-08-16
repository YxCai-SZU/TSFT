/*@
    requires a <= b;
    requires (((a) < (b)) ? (a) : (b)) == a;
    requires (((a) > (b)) ? (a) : (b)) == b;
    ensures (((a) < (b)) ? (a) : (b)) == a;
    ensures (((a) > (b)) ? (a) : (b)) == b;
*/
void calc_example_5(int a, int b) {
    /*@ assert (((a) < (b)) ? (a) : (b)) == a; */
    /*@ assert (((a) > (b)) ? (a) : (b)) == b; */
}

int main() {
    return 0;
}
