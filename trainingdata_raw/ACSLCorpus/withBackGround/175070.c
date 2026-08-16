#include <stdbool.h>

/*@
    predicate example_inequality_requires(integer n) =
        1 <= n && n <= 10;

    predicate example_inequality_ensures(integer n) =
        n * n <= 100;
*/

/*@
    lemma example_inequality:
        \forall integer n; example_inequality_requires(n) ==> example_inequality_ensures(n);
*/

/*@
    lemma property_of_example_inequality:
        \forall integer n; example_inequality_requires(n) ==> example_inequality_ensures(n);
*/

/*@
    lemma property_of_example_inequality2:
        \forall integer n; example_inequality_requires(n) ==> example_inequality_ensures(n);
*/

int main()
{
    return 0;
}
