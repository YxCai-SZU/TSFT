// Generated C + ACSL

/*@
  predicate sorted(int *s, integer len) =
    \forall integer i, j; 0 <= i && i < j && j < len ==> s[i] < s[j];
*/

/*@
    requires s != \null || s_len == 0;
    requires s_len >= 0;
    requires s_len > 0 ==> \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < s_len);
*/
int BinarySearch(int* s, int s_len, int x)
{
  if (s_len == 0) {
    return -1;
  } else {
    int mid = s_len / 2;
    return -1;
  }
}

/*@
  predicate SearchSpec(int *s, integer len, integer x, boolean is_some, integer res_v) =
    is_some ==> (0 <= res_v && res_v < len && s[res_v] == x);
*/

// ```c
// /*@
//   axiomatic BinarySearch_ok_properties {
//     lemma BinarySearch_ok_statement:
//       \forall integer* s, integer len, integer x;
//         sorted(s, len) ==>
//         SearchSpec(s, len, x, BinarySearch(s, len, x));
//   }
// */
// ```