// Generated C + ACSL

typedef struct {
  char* title;
  char* author;
} Post;

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} DateTime;

typedef struct {
  DateTime lastTimestamp;
} SocialMediaFeed;

int totalPostsCount;
int maxPostsCount;
Post* posts;

/*@
    requires \valid(&post);
    requires totalPostsCount >= 0;
    requires maxPostsCount > 0;
    assigns posts, totalPostsCount;
    ensures \result == 1 ==> totalPostsCount == \old(totalPostsCount) + 1;
    ensures \result == 0 ==> totalPostsCount == \old(totalPostsCount);
    ensures totalPostsCount >= \old(totalPostsCount);
*/
int AddPost(Post post)
{
  int success;
  if ((totalPostsCount >= maxPostsCount))
  {
    success = 0;
    /*@ assert success >= 0 && success <= 2147483647; */
    return success;
  }
  if (((post.title == "") || (post.author == "")))
  {
    success = 0;
    return success;
  }
  totalPostsCount = (totalPostsCount + 1);
  /*@ assert totalPostsCount >= 0 && totalPostsCount <= 2147483647; */
  success = 1;
  return success;
}

/*@
  predicate ValidDateTime(DateTime dt) =
    dt.year >= 1900 && dt.year <= 9999 &&
    dt.month >= 1 && dt.month <= 12 &&
    dt.day >= 1 && dt.day <= 31 &&
    dt.hour >= 0 && dt.hour <= 23 &&
    dt.minute >= 0 && dt.minute <= 59 &&
    dt.second >= 0 && dt.second <= 59;
*/

/*@
  predicate IsNewer(DateTime dt1, DateTime dt2) =
    dt1.year > dt2.year ||
    (dt1.year == dt2.year && dt1.month > dt2.month) ||
    (dt1.year == dt2.year && dt1.month == dt2.month && dt1.day > dt2.day) ||
    (dt1.year == dt2.year && dt1.month == dt2.month && dt1.day == dt2.day &&
     (dt1.hour > dt2.hour ||
      (dt1.hour == dt2.hour &&
       (dt1.minute > dt2.minute ||
        (dt1.minute == dt2.minute && dt1.second > dt2.second)))));
*/

/*@
  predicate ShouldProcessPost(DateTime postDate, SocialMediaFeed* this) =
    \valid_read(this) && ValidDateTime(this->lastTimestamp) && IsNewer(postDate, this->lastTimestamp);
*/