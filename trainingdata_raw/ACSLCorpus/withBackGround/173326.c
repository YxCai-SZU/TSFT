/*@
    predicate cube_volume_positive_cond(integer l, integer w, integer h) =
        l > 0 && w > 0 && h > 0;

    logic integer cube_volume(integer l, integer w, integer h) =
        (l <= 0 || w <= 0 || h <= 0) ? 0 :
        (l == 1) ? w * h :
        w * h * l;

    lemma cube_volume_positive:
        \forall integer l, w, h;
            cube_volume_positive_cond(l, w, h) ==>
            cube_volume(l, w, h) > 0;
*/

/*@
    requires cube_volume_positive_cond(3, 4, 5);
    ensures \result > 0;
    assigns \nothing;
*/
int example_cube_volume_usage_1(void) {
    //@ assert cube_volume(3, 4, 5) > 0;
    return 1;
}

/*@
    requires cube_volume_positive_cond(10, 20, 30);
    ensures \result > 0;
    assigns \nothing;
*/
int example_cube_volume_usage_2(void) {
    //@ assert cube_volume(10, 20, 30) > 0;
    return 1;
}

/*@
    requires cube_volume_positive_cond(60, 40, 50);
    ensures \result > 0;
    assigns \nothing;
*/
int example_cube_volume_usage_3(void) {
    //@ assert cube_volume(60, 40, 50) > 0;
    return 1;
}

int main(void) {
    int r1;
    int r2;
    int r3;
    
    r1 = example_cube_volume_usage_1();
    r2 = example_cube_volume_usage_2();
    r3 = example_cube_volume_usage_3();
    
    return 0;
}
