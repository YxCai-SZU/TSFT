/*@
    predicate is_subset(integer x, integer sub, integer sup) =
        sub <= x && x <= sup;

    predicate is_superset(integer x, integer sub, integer sup) =
        sub <= x && x <= sup;

    predicate superset_equal(integer sub1, integer sup1, integer sub2, integer sup2) =
        sub1 == sub2 && sup1 == sup2;

    predicate equality_equal(integer left_sub1, integer left_sup1, integer right_sub1, integer right_sup1,
                             integer left_sub2, integer left_sup2, integer right_sub2, integer right_sup2) =
        superset_equal(left_sub1, left_sup1, left_sub2, left_sup2) &&
        superset_equal(right_sub1, right_sup1, right_sub2, right_sup2);

    lemma equality_preserved:
        \forall integer left_sub1, left_sup1, right_sub1, right_sup1,
                   integer left_sub2, left_sup2, right_sub2, right_sup2;
        equality_equal(left_sub1, left_sup1, right_sub1, right_sup1,
                       left_sub2, left_sup2, right_sub2, right_sup2) ==>
        equality_equal(left_sub1, left_sup1, right_sub1, right_sup1,
                       left_sub2, left_sup2, right_sub2, right_sup2);
*/

struct SuperSet {
    int sub;
    int sup;
};

struct Equality {
    struct SuperSet left;
    struct SuperSet right;
};

/*@
    requires \valid(e1) && \valid(e2);
    requires e1->left.sub == e2->left.sub && e1->left.sup == e2->left.sup;
    requires e1->right.sub == e2->right.sub && e1->right.sup == e2->right.sup;
    ensures e1->left.sub == e2->left.sub && e1->left.sup == e2->left.sup;
    ensures e1->right.sub == e2->right.sub && e1->right.sup == e2->right.sup;
*/
void equality_example(struct Equality* e1, struct Equality* e2) {
    //@ assert e1->left.sub == e2->left.sub;
    //@ assert e1->left.sup == e2->left.sup;
    //@ assert e1->right.sub == e2->right.sub;
    //@ assert e1->right.sup == e2->right.sup;
}

int main() {
    return 0;
}
