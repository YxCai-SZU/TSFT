/*@
    predicate product_bounded(integer num_list_entries_per_node, integer list_element_size, integer metadata_size) =
        num_list_entries_per_node <= 2147483647 / (list_element_size + metadata_size) ==>
        num_list_entries_per_node * (list_element_size + metadata_size) <= 2147483647;

    lemma nonlinear_arithmetic_example_2:
        \forall integer num_list_entries_per_node, integer list_element_size, integer metadata_size;
            (list_element_size + metadata_size) > 0 ==>
            product_bounded(num_list_entries_per_node, list_element_size, metadata_size);

    predicate triple_product_bounded(integer x, integer y, integer z) =
        x >= 0 && y >= 0 && z >= 0 && x <= 8 && y <= 8 && z <= 8 ==> x * y * z <= 512;

    lemma nonlinear_arithmetic_example_3:
        \forall integer x, integer y, integer z;
            x >= 0 && y >= 0 && z >= 0 ==>
            triple_product_bounded(x, y, z);
*/

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
