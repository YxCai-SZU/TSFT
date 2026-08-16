/*@
predicate radius_nonnegative(integer r) = r >= 0;

logic integer area_circle(integer radius) = 
    radius < 0 ? 0 : radius * radius;

lemma area_circle_nonneg:
    \forall integer radius; radius >= 0 ==> area_circle(radius) >= 0;
*/

int main() {
    //@ assert area_circle(5) == 25;
    return 0;
}
