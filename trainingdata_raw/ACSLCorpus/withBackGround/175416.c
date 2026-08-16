/*@
predicate non_collinear_pred(integer x1, integer y1, integer x2, integer y2, integer x3, integer y3) =
    (x1 - x2) * (y3 - y2) != (y1 - y2) * (x3 - x2);

lemma calc_example_y_lemma:
    \forall integer a, b, c; a == b && b == c ==> a == c;

lemma non_collinear_lemma:
    \forall integer x1, y1, x2, y2, x3, y3;
    non_collinear_pred(x1, y1, x2, y2, x3, y3) ==>
    non_collinear_pred(x1, y1, x2, y2, x3, y3);

lemma non_collinear_2_lemma:
    \forall integer x1, y1, x2, y2, x3, y3;
    non_collinear_pred(x1, y1, x2, y2, x3, y3) ==>
    non_collinear_pred(x1, y1, x2, y2, x3, y3);
*/

/*@
requires a == b && b == c;
ensures a == c;
*/
void calc_example_y(int a, int b, int c)
{
    //@ assert a == b;
    //@ assert b == c;
    //@ assert a == c;
}

/*@
requires (x1 - x2) * (y3 - y2) != (y1 - y2) * (x3 - x2);
ensures (x1 - x2) * (y3 - y2) != (y1 - y2) * (x3 - x2);
*/
void non_collinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    //@ assert (x1 - x2) * (y3 - y2) != (y1 - y2) * (x3 - x2);
}

/*@
requires (x1 - x2) * (y3 - y2) != (y1 - y2) * (x3 - x2);
ensures (x1 - x2) * (y3 - y2) != (y1 - y2) * (x3 - x2);
*/
void non_collinear_2(int x1, int y1, int x2, int y2, int x3, int y3)
{
    //@ assert (x1 - x2) * (y3 - y2) != (y1 - y2) * (x3 - x2);
}

int main()
{
    return 0;
}
