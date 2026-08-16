/*@
requires ((x) > 5);
ensures ((x) - 3 > 0);
*/
void subtraction_correctness_proof(int x) {
    //@ assert ((x) > 5);
    //@ assert ((x) - 3 > 0);
}

/*@
requires ((x) > 1);
ensures ((x) * 2 > 1);
*/
void multiplication_correctness_proof(int x) {
    //@ assert ((x) > 1);
    //@ assert ((x) * 2 > 1);
}

int main() {
    return 0;
}
