// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
*/
void PrintGradeReport(int* grade, int grade_len);

void Main(void)
{
  int grade[3] = {0, 0, 0};
  PrintGradeReport(grade, 1);
}

/*@
    requires grade != \null;
    requires grade_len >= 0;
    requires \valid_read(grade + (0 .. grade_len * 3 - 1));
    requires \forall integer i; 0 <= i < grade_len ==>
        (0 <= grade[i * 3] <= 100 &&
         0 <= grade[i * 3 + 1] <= 100 &&
         0 <= grade[i * 3 + 2] <= 100);
    assigns \nothing;
*/
void PrintGradeReport(int* grade, int grade_len)
{
  /* unsupported stmt: print "이름  국어 영어 수학 합계 평균\n"; */
  int i = 0;
/*@
  loop invariant 0 <= i <= grade_len;
  loop invariant \at(grade_len, LoopEntry) == grade_len;
  loop invariant \valid_read(grade + (0 .. grade_len - 1));
  loop invariant \forall integer k; 0 <= k < i ==>
    \valid_read(&grade[k]);
  loop assigns i;
  loop variant grade_len - i;
*/
  while ((i < grade_len))
    {
      int kor = grade[i * 3];
      int eng = grade[i * 3 + 1];
      int mat = grade[i * 3 + 2];
      int total = ((kor + eng) + mat);
      int average = (total / 3);
      /* unsupported stmt: print student.name, "  ", student.kor, "  ", student.eng, "  ", student.mat, "  ", total, "  ", average, "\n"; */
      i = (i + 1);
    }
}

/*@
    requires \true;
    assigns \nothing;
*/
void TestPrintGradeReport(void)
{
  int testGrade[3] = {0, 0, 0};
  PrintGradeReport(testGrade, 1);
}