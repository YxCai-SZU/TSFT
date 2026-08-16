/*@
    requires ((i) % 2 == 0);
    ensures ((i) % 2 == 0) == \true;
*/
void is_even_f(int i) {
    //@ assert ((i) % 2 == 0);
}
