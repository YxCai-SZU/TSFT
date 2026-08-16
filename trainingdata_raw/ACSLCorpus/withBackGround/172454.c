/*@
    logic integer square(integer x) = x * x;

    lemma square_positive:
        \forall integer x; 0 <= x <= 0x7FFFFFFF ==> square(x) >= 0;
*/

int main() {
    //@ ghost int x;
    //@ assert square(0) >= 0;
    //@ assert square(1) >= 0;
    //@ assert square(0x7FFFFFFF) >= 0;
    return 0;
}
