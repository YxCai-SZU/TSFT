/*@
    predicate is_maximum(integer ret, integer a, integer b) =
        (ret == a && a >= b) || (ret == b && b > a);

    predicate is_minimum(integer ret, integer a, integer b) =
        (ret == a && a <= b) || (ret == b && b < a);

    logic integer volume_cube_logic(integer side) = side * side * side;
    logic integer volume_prism_logic(integer l, integer w, integer h) = l * w * h;
    logic integer surface_cube_logic(integer side) = 6 * side * side;
    logic integer surface_prism_logic(integer l, integer w, integer h) =
        2 * (l * w + l * h + w * h);

    lemma cube_volume_bound: \forall integer s; 0 <= s <= 1290 ==> s * s <= 1290 * 1290;
    lemma cube_volume_bound2: \forall integer s; 0 <= s <= 1290 ==> s * s * s <= 1290 * 1290 * 1290;
    lemma prism_volume_bound: \forall integer l,w,h;
        0 <= l <= 1290 && 0 <= w <= 1290 && 0 <= h <= 1290 ==>
        l * w <= 1290 * 1290;
    lemma prism_volume_bound2: \forall integer l,w,h;
        0 <= l <= 1290 && 0 <= w <= 1290 && 0 <= h <= 1290 ==>
        l * w * h <= 1290 * 1290 * 1290;
    lemma cube_surface_bound: \forall integer s; 0 <= s <= 1000 ==> 6 * s * s <= 6 * 1000 * 1000;
    lemma prism_surface_bound: \forall integer l,w,h;
        0 <= l <= 1000 && 0 <= w <= 1000 && 0 <= h <= 1000 ==>
        2 * (l * w + l * h + w * h) <= 2 * (1000 * 1000 + 1000 * 1000 + 1000 * 1000);
*/

/*@
    requires \true;
    ensures \true;
*/
int main() {
    return 0;
}

/*@
    requires \true;
    ensures is_maximum(\result, a, b);
*/
int maximum(int a, int b) {
    int ret;
    //@ assert \true;
    if (a > b) {
        ret = a;
    } else {
        ret = b;
    }
    //@ assert is_maximum(ret, a, b);
    return ret;
}

/*@
    requires \true;
    ensures is_minimum(\result, a, b);
*/
int minimum(int a, int b) {
    int ret;
    //@ assert \true;
    if (a < b) {
        ret = a;
    } else {
        ret = b;
    }
    //@ assert is_minimum(ret, a, b);
    return ret;
}

/*@
    requires 0 <= side <= 1290;
    ensures \result == volume_cube_logic(side);
*/
int volume_cube(int side) {
    int ret;
    //@ assert side * side <= 1290 * 1290;
    //@ assert side * side * side <= 1290 * 1290 * 1290;
    ret = side * side * side;
    //@ assert ret == volume_cube_logic(side);
    return ret;
}

/*@
    requires 0 <= length <= 1290;
    requires 0 <= width <= 1290;
    requires 0 <= height <= 1290;
    requires length * width * height <= 2147483647;
    ensures \result == volume_prism_logic(length, width, height);
*/
int volume_rectangular_prism(int length, int width, int height) {
    int ret;
    //@ assert length * width <= 1290 * 1290;
    //@ assert length * width * height <= 1290 * 1290 * 1290;
    ret = length * width * height;
    //@ assert ret == volume_prism_logic(length, width, height);
    return ret;
}

/*@
    requires 0 <= side <= 1000;
    ensures \result == surface_cube_logic(side);
*/
int surface_area_cube(int side) {
    int ret;
    //@ assert 6 * side * side <= 6 * 1000 * 1000;
    ret = 6 * side * side;
    //@ assert ret == surface_cube_logic(side);
    return ret;
}

/*@
    requires 0 <= length <= 1000;
    requires 0 <= width <= 1000;
    requires 0 <= height <= 1000;
    ensures \result == surface_prism_logic(length, width, height);
*/
int surface_area_rectangular_prism(int length, int width, int height) {
    int ret;
    //@ assert 2 * (length * width + length * height + width * height) <= 2 * (1000 * 1000 + 1000 * 1000 + 1000 * 1000);
    ret = 2 * (length * width + length * height + width * height);
    //@ assert ret == surface_prism_logic(length, width, height);
    return ret;
}
