/*@
    logic integer rectangle_area(integer w, integer h) =
        w <= 0 ? 0 :
        w == 1 ? h :
        w * h;

    lemma rectangle_area_monotonic:
        \forall integer w, h;
        0 <= w <= 1 && h >= 0 ==>
        rectangle_area(w, h) <= rectangle_area(1, h);
*/

int main() {
    return 0;
}
