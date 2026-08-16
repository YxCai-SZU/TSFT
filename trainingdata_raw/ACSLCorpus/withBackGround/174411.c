/*@
    logic integer spec_factorial(integer n) =
        n <= 1 ? n : n * spec_factorial(n - 1);
*/

/*@
    lemma factorial_lemma:
        \forall integer n;
            n >= 0 ==>
            (spec_factorial(n) == n * spec_factorial(n - 1) || (n == 0 || n == 1));
*/

int main()
{
    return 0;
}
