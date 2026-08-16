/*@
    predicate is_palindrome{L}(int *s, integer len) =
        \forall integer i; 0 <= i < len/2 ==> s[i] == s[len - 1 - i];

    predicate is_increasing{L}(int *s, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> s[i] < s[i + 1];

    lemma func_is_palindrome{L}:
        \forall int *s, integer len;
        is_palindrome(s, len) ==>
        (\forall integer i; 0 <= i < len/2 ==> s[i] == s[len - 1 - i]);

    lemma func_is_increasing{L}:
        \forall int *s, integer len;
        is_increasing(s, len) ==>
        (\forall integer i; 0 <= i < len - 1 ==> s[i] < s[i + 1]);
*/

int main() {
    return 0;
}
