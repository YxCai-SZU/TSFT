/*@
    logic integer f1_example(integer x) = x + 2;
    logic integer f2_example(integer x) = x + 1 + 1;
    lemma spec_functions_example:
        (\forall integer x; f1_example(x) == f2_example(x)) ==>
        (\forall integer x; f1_example(x) == f2_example(x));
*/

/*@
    logic integer f1_example2(integer x) = x + 3;
    logic integer f2_example2(integer x) = x + 1 + 2;
    lemma spec_functions_example2:
        (\forall integer x; f1_example2(x) == f2_example2(x)) ==>
        (\forall integer x; f1_example2(x) == f2_example2(x));
*/

/*@
    logic integer f1_example3(integer x) = x + 4;
    logic integer f2_example3(integer x) = x + 1 + 3;
    lemma spec_functions_example3:
        (\forall integer x; f1_example3(x) == f2_example3(x)) ==>
        (\forall integer x; f1_example3(x) == f2_example3(x));
*/

/*@
    logic integer f1_example4(integer x) = x + 5;
    logic integer f2_example4(integer x) = x + 1 + 4;
    lemma spec_functions_example4:
        (\forall integer x; f1_example4(x) == f2_example4(x)) ==>
        (\forall integer x; f1_example4(x) == f2_example4(x));
*/

/*@
    logic integer f1_example5(integer x) = x + 6;
    logic integer f2_example5(integer x) = x + 1 + 5;
    lemma spec_functions_example5:
        (\forall integer x; f1_example5(x) == f2_example5(x)) ==>
        (\forall integer x; f1_example5(x) == f2_example5(x));
*/

int main() {
    return 0;
}
