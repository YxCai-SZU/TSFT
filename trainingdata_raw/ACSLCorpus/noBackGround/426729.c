/*@
    requires \true;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_distributive_add(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert ((x) * ((y) + (z)) == (x) * (y) + (x) * (z));
    return 0;
}

/*@
    requires ((x) * ((y) + (z)) == (x) * (y) + (x) * (z));
    ensures \result == 0;
    assigns \nothing;
*/
int verify_distributive_add_inversely(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert ((x) * ((y) + (z)) == (x) * (y) + (x) * (z));
    return 0;
}

int main() {
    unsigned int x;
    unsigned int y;
    unsigned int z;
    int result1;
    int result2;
    
    result1 = verify_distributive_add(x, y, z);
    result2 = verify_distributive_add_inversely(x, y, z);
    return 0;
}
