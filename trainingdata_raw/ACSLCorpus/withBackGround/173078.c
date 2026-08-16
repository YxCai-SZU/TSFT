/*@
    logic integer add_or_subtract(integer x, integer y) =
        x >= y ? x - y : y - x;

    lemma add_or_subtract_nonneg:
        \forall integer x, y; add_or_subtract(x, y) >= 0;
*/

/*@
    requires \true;
    ensures \true;
*/
void test() {
    //@ assert add_or_subtract(10, 20) >= 0;
    //@ assert add_or_subtract(100, 200) >= 0;
}

int main() {
    return 0;
}
