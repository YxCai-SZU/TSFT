/*@
    predicate valid_range(integer v) = 1 <= v <= 205;

    logic integer map_x(integer x) =
        x == 1 ? 300000 :
        x == 2 ? 200000 :
        x == 3 ? 100000 :
        0;

    logic integer map_y(integer y) =
        y == 1 ? 300000 :
        y == 2 ? 200000 :
        y == 3 ? 100000 :
        0;

    logic integer max_val(integer x, integer y) = x > y ? x : y;
    logic integer min_val(integer x, integer y) = x < y ? x : y;

    logic integer diff(integer maxv, integer minv) = maxv - minv;

    logic integer steps(integer d) =
        d == 0 ? 0 :
        d == 100000 ? 1 :
        d == 200000 ? 2 :
        d == 300000 ? 3 :
        4;

    lemma max_ge_min: \forall integer x, y; max_val(x, y) >= min_val(x, y);
    lemma diff_nonneg: \forall integer maxv, minv; maxv >= minv ==> diff(maxv, minv) >= 0;
    lemma steps_nonneg: \forall integer d; steps(d) >= 0;
*/

/*@
    requires valid_range(x);
    requires valid_range(y);
    ensures \result >= 0;
    ensures \result <= 1000000;
*/
int func(int x, int y)
{
    int mapped_x;
    int mapped_y;
    int max_val;
    int min_val;
    int diff_val;
    int steps_val;
    int result;

    //@ assert valid_range(x);
    //@ assert valid_range(y);

    if (x == 1) {
        mapped_x = 300000;
    } else if (x == 2) {
        mapped_x = 200000;
    } else if (x == 3) {
        mapped_x = 100000;
    } else {
        mapped_x = 0;
    }

    //@ assert mapped_x == map_x(x);

    if (y == 1) {
        mapped_y = 300000;
    } else if (y == 2) {
        mapped_y = 200000;
    } else if (y == 3) {
        mapped_y = 100000;
    } else {
        mapped_y = 0;
    }

    //@ assert mapped_y == map_y(y);

    if (mapped_x > mapped_y) {
        max_val = mapped_x;
    } else {
        max_val = mapped_y;
    }

    //@ assert max_val == max_val(mapped_x, mapped_y);

    if (mapped_x < mapped_y) {
        min_val = mapped_x;
    } else {
        min_val = mapped_y;
    }

    //@ assert min_val == min_val(mapped_x, mapped_y);

    //@ assert max_val >= min_val;

    if (max_val == 0 || min_val == 0) {
        return 0;
    }

    diff_val = max_val - min_val;

    //@ assert diff_val == diff(max_val, min_val);
    //@ assert diff_val >= 0;

    if (diff_val == 0) {
        steps_val = 0;
    } else if (diff_val == 100000) {
        steps_val = 1;
    } else if (diff_val == 200000) {
        steps_val = 2;
    } else if (diff_val == 300000) {
        steps_val = 3;
    } else {
        steps_val = 4;
    }

    //@ assert steps_val == steps(diff_val);
    //@ assert steps_val >= 0;

    result = min_val + (steps_val * 100000);

    //@ assert result >= 0;
    //@ assert result <= 1000000;

    return result;
}
