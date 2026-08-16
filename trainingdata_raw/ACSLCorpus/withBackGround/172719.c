/*@
    logic integer func(integer n) =
        n <= 1 ? n : func(n - 1) * n;

    lemma func_nonzero:
        \forall integer n; func(n) != 0 ==>
            (n > 1 ==> func(n - 1) != 0);
*/

int main() {
    return 0;
}
