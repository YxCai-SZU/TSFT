/*@
    logic integer min_value(integer a, integer b) = 
        (a < b) ? a : b;

    lemma min_property:
        \forall integer a, b;
            min_value(a, b) <= a && 
            min_value(a, b) <= b && 
            (min_value(a, b) == a || min_value(a, b) == b);
*/


void example_min_usage() {
    //@ assert min_value(10, 20) <= 10;
    //@ assert min_value(100, 200) <= 200;
}

int main() {
    example_min_usage();
    return 0;
}
