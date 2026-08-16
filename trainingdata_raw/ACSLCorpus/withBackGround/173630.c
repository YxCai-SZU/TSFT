/*@
    logic integer volume_rect_prism(integer l, integer w, integer h) = l * w * h;

    lemma volume_test_1: volume_rect_prism(2, 3, 4) == 24;
    lemma volume_test_2: volume_rect_prism(1, 1, 10) == 10;
    lemma volume_test_3: volume_rect_prism(1, 1, 1) == 1;
*/

/*@
    requires \true;
    ensures volume_rect_prism(2, 3, 4) == 24;
    ensures volume_rect_prism(1, 1, 10) == 10;
    ensures volume_rect_prism(1, 1, 1) == 1;
*/
void test_volume_rect_prism() {
    //@ assert volume_rect_prism(2, 3, 4) == 24;
    //@ assert volume_rect_prism(1, 1, 10) == 10;
    //@ assert volume_rect_prism(1, 1, 1) == 1;
}
