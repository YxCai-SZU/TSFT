/*@
    predicate my_relations_pre(integer x, integer y) = x < y;
    predicate my_relations_post(integer x, integer y) = x + 1 <= y + 2;
    predicate my_relations2_pre(integer x, integer y) = x < y;
    predicate my_relations2_post(integer x, integer y) = x + 1 <= y + 2;
    predicate my_relations3_pre(integer x, integer y) = x < y;
    predicate my_relations3_post(integer x, integer y) = x + 1 <= y + 2;

    lemma my_relations: \forall integer x, y; my_relations_pre(x, y) ==> my_relations_post(x, y);
    lemma my_relations2: \forall integer x, y; my_relations2_pre(x, y) ==> my_relations2_post(x, y);
    lemma my_relations3: \forall integer x, y; my_relations3_pre(x, y) ==> my_relations3_post(x, y);
*/

int main() {
    return 0;
}
