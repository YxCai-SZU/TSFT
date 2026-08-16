/*@
    requires n >= 0;
    ensures \exists integer x; ((x) % 10 == 0);
*/
void establish_exists_divisible_by_10_proof(int n) {
    //@ assert ((10) % 10 == 0);
}

int main() {
    int n = 0;
    establish_exists_divisible_by_10_proof(n);
    return 0;
}
