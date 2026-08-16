/*@
    requires ((x) % 2 == 0);
    ensures ((\result) % 2 == 0);
*/
int times_two(int x) {
    //@ assert ((x) % 2 == 0);
    int result = x * 2;
    //@ assert ((result) % 2 == 0);
    return result;
}

int main() {
    return 0;
}
