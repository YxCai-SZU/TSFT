/*@
    logic integer square(integer x) = x * x;

    lemma square_is_monotonic:
        \forall integer x;
            x >= 0 && x < 100 ==> square(x) < 10000;

    lemma square_example:
        \forall integer x;
            x >= 0 && x < 100 ==> square(x) == x * x;

    lemma square_monotonic:
        \forall integer x, integer y;
            x >= 0 && y >= 0 && x < 100 && y < 100 && x <= y ==>
            square(x) <= square(y);
*/

int main() {
    return 0;
}
