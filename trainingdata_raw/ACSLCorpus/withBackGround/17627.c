#include <stdbool.h>

/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate is_non_negative(integer n) = n >= 0;

    lemma calc_example_5: 
        \forall integer x, y; 
        x >= 2 && y >= 3 && is_even(x + y) ==> 
        is_non_negative(x + y - 2);
*/

/*@
    requires x >= 2;
    requires y >= 3;
    requires (x + y) % 2 == 0;
    ensures \result >= 0;
*/
int calc_example_5(int x, int y) {
    int even_x;
    int odd_y;
    int result;

    even_x = x + 2 * 1;
    odd_y = y + 1;
    result = x + y - 2;

    //@ assert is_even(x + y);
    //@ assert even_x + odd_y == x + y + 3;
    //@ assert result == x + y - 2;
    //@ assert result >= 0;

    return result;
}

int main() {
    return 0;
}
