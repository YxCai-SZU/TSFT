/*@
    logic integer min_val(integer x, integer y) = (x <= y) ? x : y;
    logic integer max_val(integer x, integer y) = (x >= y) ? x : y;

    lemma min_val_properties:
        \forall integer x, y;
            min_val(x, y) == x || min_val(x, y) == y;

    lemma min_val_properties2:
        \forall integer x, y;
            min_val(x, y) <= x;

    lemma min_val_properties3:
        \forall integer x, y;
            min_val(x, y) <= y;

    lemma max_val_properties:
        \forall integer x, y;
            max_val(x, y) == x || max_val(x, y) == y;

    lemma max_val_properties2:
        \forall integer x, y;
            max_val(x, y) >= x;

    lemma max_val_properties3:
        \forall integer x, y;
            max_val(x, y) >= y;
*/

int main() {
    int x;
    int y;
    int min;
    int max;

    return 0;
}
