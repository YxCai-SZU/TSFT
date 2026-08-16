/*@
requires x < y && y < z;
ensures \result == 0;
assigns \nothing;
*/
int verify_all_chains(int x, int y, int z) {
    //@ assert x < y;
    //@ assert y < z;
    //@ assert x < z;
    //@ assert x <= z;
    return 0;
}

int main() {
    return 0;
}
