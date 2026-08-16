/*@
    logic integer func(integer a) =
        a == 0 ? 0 : 1 + func(a - 1);
*/

/*@
    lemma func_proof:
        \forall integer a; 0 <= a <= 10 ==> func(a) == a;
*/

int main() {
    int a = 10;
    //@ assert func(a) == a;
    return 0;
}
