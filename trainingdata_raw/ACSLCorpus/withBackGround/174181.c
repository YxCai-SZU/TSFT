#include <stdbool.h>

struct ComplexData {
    int id;
    int **nested;
    int *set;
    int *map_keys;
    int *map_vals;
    int rows;
    int cols;
    int set_size;
    int map_size;
};

/*@
    predicate nested_eq(int **nested1, int **nested2, integer rows, integer cols) =
        \forall integer i, j; 0 <= i < rows && 0 <= j < cols ==> nested1[i][j] == nested2[i][j];

    predicate set_eq(int *set1, int *set2, integer size) =
        \forall integer i; 0 <= i < size ==> set1[i] == set2[i];

    predicate map_eq(int *keys1, int *vals1, int *keys2, int *vals2, integer size) =
        \forall integer i; 0 <= i < size ==> keys1[i] == keys2[i] && vals1[i] == vals2[i];

    predicate complex_eq(int id1, int id2, int **nested1, int **nested2, integer rows, integer cols,
                         int *set1, int *set2, integer set_size,
                         int *keys1, int *vals1, int *keys2, int *vals2, integer map_size) =
        id1 == id2 &&
        nested_eq(nested1, nested2, rows, cols) &&
        set_eq(set1, set2, set_size) &&
        map_eq(keys1, vals1, keys2, vals2, map_size);

    lemma complex_data_lemma:
        \forall int id1, id2, **nested1, **nested2, *set1, *set2, *keys1, *vals1, *keys2, *vals2,
               integer rows, cols, set_size, map_size;
        complex_eq(id1, id2, nested1, nested2, rows, cols, set1, set2, set_size,
                   keys1, vals1, keys2, vals2, map_size) ==>
        id1 == id2;
*/

/*@
    requires \valid(data1) && \valid(data2);
    requires data1->rows == data2->rows && data1->cols == data2->cols;
    requires data1->set_size == data2->set_size;
    requires data1->map_size == data2->map_size;
    requires data1->id == data2->id;
    requires nested_eq(data1->nested, data2->nested, data1->rows, data1->cols);
    requires set_eq(data1->set, data2->set, data1->set_size);
    requires map_eq(data1->map_keys, data1->map_vals, data2->map_keys, data2->map_vals, data1->map_size);
    ensures data1->id == data2->id;
*/
void complex_data_example(struct ComplexData *data1, struct ComplexData *data2) {
    //@ assert data1->id == data2->id;
}

int main() {
    return 0;
}
