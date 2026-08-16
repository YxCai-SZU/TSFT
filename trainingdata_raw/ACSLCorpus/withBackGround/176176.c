/*@
    logic integer sum_of_squares(integer n) =
        n > 1 ? n * n + sum_of_squares(n - 1) : 1;

    lemma sum_of_squares_asserts:
        \forall integer n; n > 0 && n <= 1 ==> sum_of_squares(n) == 1;

    lemma sum_of_squares_is_not_constant:
        \forall integer n; n > 0 && n <= 1 ==> n * n <= 1 && sum_of_squares(n) <= 2;
*/

int main() {
    return 0;
}
