/*@
predicate bounds_x(integer x) = 0 <= x <= 10;
predicate bounds_y(integer y) = 0 <= y <= 10;
predicate bounds_z(integer z) = 0 <= z <= 10;

lemma product_bound_xy:
    \forall integer x, y; bounds_x(x) && bounds_y(y) ==> x * y <= 100;

lemma product_bound_xyz:
    \forall integer x, y, z; bounds_x(x) && bounds_y(y) && bounds_z(z) ==> x * y * z <= 1000;

lemma linear_combination_bound:
    \forall integer x, y, z; bounds_x(x) && bounds_y(y) && bounds_z(z) ==> x * (y + z) <= 200;
*/

/*@ requires x <= 4 && y <= 5;
    ensures \true;
*/
void various_checks(unsigned int x, unsigned int y)
{
    //@ assert x * y <= 20;
    //@ assert x * y <= 50;
}

/*@ requires 0 <= x && x <= 10 && 0 <= y && y <= 10 && 0 <= z && z <= 10;
    ensures \true;
*/
void nonlinear_arithmetic_example(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x * y <= 100;
    //@ assert x * y * z <= 1000;
    //@ assert x * (y + z) <= 200;
}

int main() {
    return 0;
}
