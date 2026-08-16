/*@
predicate max_ge_x(integer x, integer y) =
    \max(x, y) >= x;

predicate max_ge_y(integer x, integer y) =
    \max(x, y) >= y;

lemma max_nonlinear:
    \forall integer x, y;
    \max(x, y) >= x && \max(x, y) >= y;
*/

/*@
requires \true;
ensures \forall integer x, y; \max(x, y) >= x;
ensures \forall integer x, y; \max(x, y) >= y;
*/
void establish_max_nonlinear()
{
    //@ assert \forall integer x, y; \max(x, y) >= x;
    //@ assert \forall integer x, y; \max(x, y) >= y;
}

int main()
{
    return 0;
}
