/*@
    logic integer cuboid_volume(integer l, integer w, integer h) = l * w * h;

    lemma cuboid_volume_lemma:
        \forall integer l, w, h;
            l >= 0 && w >= 0 && h >= 0 ==>
            cuboid_volume(l, w, h) == l * w * h &&
            cuboid_volume(l, w, h) >= 0;
*/

void main() {
    //@ assert cuboid_volume(5, 4, 3) == 60;
    //@ assert cuboid_volume(2, 1, 6) == 12;
}
