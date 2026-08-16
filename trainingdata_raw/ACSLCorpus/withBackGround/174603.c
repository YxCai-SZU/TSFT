/*@
predicate is_even(integer x) = x % 2 == 0;
predicate non_negative(integer x) = x >= 0;

lemma calc_example_4: \forall integer x; is_even(x) ==> x - 2 == x - 2;
lemma square_area_example: \forall integer a; non_negative(a) ==> a * a == a * a;
lemma area_parallelogram: \forall integer base, height; non_negative(base) && non_negative(height) ==> base * height == base * height;
lemma area_triangle: \forall integer base, height; non_negative(base) && non_negative(height) ==> base * height / 2 == base * height / 2;
*/

int main() {
    return 0;
}
