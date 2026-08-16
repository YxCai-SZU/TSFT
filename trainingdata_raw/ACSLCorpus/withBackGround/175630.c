#include <stdbool.h>

/*@
    predicate is_positive(integer x) = x > 0;
    predicate is_less_than_million(integer x) = x < 1000000;
    predicate is_non_negative(integer x) = x >= 0;
*/

/*@
    lemma test_something_lemma:
        \forall integer x; is_positive(x) && is_less_than_million(x) ==> x <= x;
    lemma test_something_lemma2:
        \forall integer x; is_positive(x) && is_less_than_million(x) ==> x <= x + 1;
    lemma test_something_lemma3:
        \forall integer x; is_less_than_million(x) ==> x + 1 <= 1000000;
    lemma test_something_lemma4:
        \forall integer x; is_positive(x) ==> x >= 1;
*/

/*@
    lemma is_square_positive_lemma:
        \forall integer n; is_positive(n) ==> n * n > 0;
    lemma is_square_positive_lemma2:
        \forall integer n; n >= 1 ==> n * n >= 1;
*/

/*@
    lemma less_than_add_1_lemma:
        \forall integer a, b; a < b ==> a + 1 <= b;
*/

/*@
    requires is_positive(x) && is_less_than_million(x);
    ensures \true;
*/
void test_something(int x)
{
    //@ assert x <= x;
    //@ assert x <= x + 1;
    //@ assert x + 1 <= x + 2;
    //@ assert x + 1 <= 1000000;
    //@ assert x >= 1;
}

/*@
    requires is_positive(n);
    ensures \true;
*/
void is_square_positive(int n)
{
    //@ assert n >= 1;
    //@ assert n * n >= 1;
    //@ assert n * n > 0;
}

/*@
    requires a < b;
    ensures \true;
*/
void less_than_add_1(int a, int b)
{
    //@ assert a < b;
    //@ assert a + 1 <= b;
}
