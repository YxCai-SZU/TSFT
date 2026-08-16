/*@
    logic integer mod_2(integer x) = x % 2;

    lemma mod_2_is_bounded:
        \forall integer x;
            x >= 0 && x < 2 ==> mod_2(x) == x;
*/

/*@
    lemma example_mod_usage:
        mod_2(0) == 0 && mod_2(1) == 1;
*/

int main() {
    //@ assert mod_2(0) == 0;
    //@ assert mod_2(1) == 1;
    return 0;
}
