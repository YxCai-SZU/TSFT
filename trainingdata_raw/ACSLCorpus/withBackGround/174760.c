/*@
    predicate x_times_2_eq_y(integer x, integer y) = x * 2 == y;
    predicate y_times_2_eq_z(integer y, integer z) = y * 2 == z;
    predicate x_times_4_eq_z(integer x, integer z) = x * 4 == z;
*/

/*@
    lemma calc_example_8: \forall integer x, y, z;
        x_times_2_eq_y(x, y) && y_times_2_eq_z(y, z) ==> x_times_4_eq_z(x, z);
*/

int main() {
    return 0;
}
