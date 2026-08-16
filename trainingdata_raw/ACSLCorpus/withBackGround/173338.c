#include <stdbool.h>

/*@ predicate nonnegative(integer x) = x >= 0; */

/*@ lemma y_ge_x: \forall integer x, y; nonnegative(x) && nonnegative(y) && x <= y ==> y >= x; */

/*@ lemma x_le_y_plus_one: \forall integer x, y; nonnegative(x) && nonnegative(y) && x <= y + 1 ==> x <= y + 1; */

/*@ lemma y_le_x_plus_one: \forall integer x, y; nonnegative(x) && nonnegative(y) && y <= x + 1 ==> y <= x + 1; */

/*@ lemma x_le_y: \forall integer x, y; nonnegative(x) && nonnegative(y) && x <= y ==> x <= y; */

/*@ lemma y_le_x: \forall integer x, y; nonnegative(x) && nonnegative(y) && y <= x ==> y <= x; */

/*@ lemma abs_x_minus_y: \forall integer x, y; nonnegative(x) && nonnegative(y) && x >= y ==> x - y >= 0; */

/*@ lemma abs_y_minus_x: \forall integer x, y; nonnegative(x) && nonnegative(y) && y >= x ==> y - x >= 0; */

/*@ lemma max_x_y: \forall integer x, y; nonnegative(x) && nonnegative(y) ==> nonnegative(x) && nonnegative(y); */

/*@ lemma min_x_y: \forall integer x, y; nonnegative(x) && nonnegative(y) ==> nonnegative(x) && nonnegative(y); */

int main()
{
    return 0;
}
