/*@
    requires k % 2 == 0;
    ensures ((k) % 2 == 0);
*/
void is_even_f(int k) {
    //@ assert ((k) % 2 == 0);
}

/*@
    requires k % 2 == 0;
    ensures ((k) % 2 == 0);
*/
void choose_even_f(int k) {
    //@ assert ((k) % 2 == 0);
}

int main() {
    return 0;
}
