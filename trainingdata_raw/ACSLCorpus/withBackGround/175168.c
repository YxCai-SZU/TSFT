/*@
predicate eq_int(integer a, integer b) = a == b;

lemma calc_example_y:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma calc_example_x:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma triangle_area_example:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma rectangle_perimeter_example:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma square_area_example:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma volume_cube_example:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma volume_rectangular_prism_example:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma surface_area_sphere_example:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma surface_area_cube_example:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma volume_cone_example:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma volume_cylinder_example:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);

lemma volume_rectangular_prism:
    \forall integer a, b, c;
        eq_int(a, b) && eq_int(b, c) ==> eq_int(a, c);
*/

int main() {
    int a;
    int b;
    int c;
    
    //@ assert \true;
    
    return 0;
}
