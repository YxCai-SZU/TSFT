/*@
    predicate no_duplicates(int *s, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> s[i] != s[j];

    predicate no_common_elements(int *a, integer len_a, int *b, integer len_b) =
        \forall integer i, j; 0 <= i < len_a && 0 <= j < len_b ==> a[i] != b[j];

    predicate unique_elements(int *a, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> a[i] != a[j];

    predicate all_unique_elements(int *a, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> a[i] != a[j];

    lemma lemma_no_duplicates:
        \forall int *s, integer len;
        no_duplicates(s, len) ==> no_duplicates(s, len);

    lemma lemma_no_common_elements:
        \forall int *a, integer len_a, int *b, integer len_b;
        no_common_elements(a, len_a, b, len_b) ==> no_common_elements(a, len_a, b, len_b);

    lemma lemma_unique_elements:
        \forall int *a, integer len;
        unique_elements(a, len) ==> unique_elements(a, len);

    lemma lemma_all_unique_elements:
        \forall int *a, integer len;
        all_unique_elements(a, len) ==> all_unique_elements(a, len);
*/

int main()
{
    return 0;
}
