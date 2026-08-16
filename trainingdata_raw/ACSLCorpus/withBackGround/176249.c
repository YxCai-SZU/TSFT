#include <stdbool.h>

/*@
    predicate X_in_range(integer X) = 1 <= X && X <= 205;
    predicate Y_in_range(integer Y) = 1 <= Y && Y <= 205;
    predicate money_nonneg(integer money) = money >= 0;
    predicate money_formula_x(integer money, integer x) = money == (x - 1) * 1000;
    predicate money_formula_xy(integer money, integer X, integer y) = money == (X - 1) * 1000 + (y - 1) * 1000;
*/

/*@
    requires X_in_range(X);
    requires Y_in_range(Y);
    ensures money_nonneg(\result);
    ensures \result == (X - 1) * 1000 + (Y - 1) * 1000;
*/
int func(int X, int Y)
{
    int money;
    int x;
    int y;

    money = 0;
    x = 1;

    /*@
        loop invariant 1 <= x && x <= X;
        loop invariant money_nonneg(money);
        loop invariant money_formula_x(money, x);
        loop assigns money, x;
    */
    while (x < X)
    {
        //@ assert money_formula_x(money, x);
        money = money + 1000;
        x += 1;
    }

    y = 1;

    /*@
        loop invariant 1 <= y && y <= Y;
        loop invariant money_nonneg(money);
        loop invariant money_formula_xy(money, X, y);
        loop assigns money, y;
    */
    while (y < Y)
    {
        //@ assert money_formula_xy(money, X, y);
        money = money + 1000;
        y += 1;
    }

    return money;
}
