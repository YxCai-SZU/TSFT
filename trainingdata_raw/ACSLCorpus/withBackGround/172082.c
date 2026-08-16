/*@
predicate is_func(integer x, integer y, integer result) =
    result == x + y;

lemma lemma_func:
    \forall integer x, y; is_func(x, y, x + y);
*/

/*@
requires \true;
assigns \nothing;
ensures \result == 30;
*/
int main() {
    //@ assert is_func(10, 20, 30);
    return 30;
}
