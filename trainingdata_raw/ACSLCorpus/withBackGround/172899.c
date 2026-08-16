/*@
    logic integer area_rectangular(integer x, integer y) = x * y;

    lemma rectangular_area_lemma:
        \forall integer x, y;
            x >= 0 && y >= 0 && x <= 10000 && y <= 10000 ==>
                area_rectangular(x, y) == x * y &&
                area_rectangular(x, y) >= 0 &&
                area_rectangular(x, y) <= 10000 * 10000;
*/

int main() {
    //@ assert area_rectangular(10, 20) == 200;
    //@ assert area_rectangular(100, 200) == 20000;
    return 0;
}
