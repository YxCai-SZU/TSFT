/*@
predicate is_between(integer x, integer a, integer b) =
    a <= x && x <= b;

lemma establish_forall{L}:
    \forall integer a, integer b, int* v, integer len;
    (\forall integer i; 0 <= i < len ==> is_between(v[i], a, b)) ==>
    (\forall integer i; 0 <= i < len ==> v[i] >= a && v[i] <= b);
*/

int main()
{
    return 0;
}
