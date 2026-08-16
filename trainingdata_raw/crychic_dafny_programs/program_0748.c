// Generated C + ACSL

typedef struct {
    int engine;
    int cluster_id;
} Cluster;

typedef struct {
    int creationDate;
} Snapshot;

Cluster* clusters;
int clusters_len;
Snapshot* snapshots;
int snapshots_len;

/*@
    requires \valid_read(clusters + (0 .. clusters_len-1));
    requires clusters_len >= 0;
    requires \valid(result_len);
    assigns *result_len;
    ensures 0 <= *result_len <= clusters_len;
*/
int* FilterClustersByEngine(int engineType, int* result_len)
{
  int result_count = 0;
  /*@ assert result_count >= 0 && result_count <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= clusters_len;
  loop invariant result_count <= i;
  loop invariant result_count >= \at(result_count, LoopEntry);
  loop invariant result_count <= \at(result_count, LoopEntry) + i;
  loop assigns i, result_count;
  loop variant clusters_len - i;
*/
  while ((i < clusters_len))
    {
      if ((clusters[i].engine == engineType))
      {
        result_count = (result_count + 1);
      }
      i = (i + 1);
    }
  *result_len = result_count;
  int* result = (int*)0;
  return result;
}

/*@
    requires clusters != \null;
    requires \valid(clusters + (0 .. clusters_len-1));
    requires clusters_len >= 0;
    assigns clusters[0 .. clusters_len-1], clusters_len;
    ensures \result >= 0;
    ensures clusters_len <= \old(clusters_len);
*/
int DeleteClustersByEngine(int engineType)
{
  int newClusters_count = 0;
  int deletedCount = 0;
  /*@ assert deletedCount >= 0 && deletedCount <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= clusters_len;
  loop invariant deletedCount >= 0;
  loop invariant deletedCount + newClusters_count == i;
  loop invariant newClusters_count <= i;
  loop invariant deletedCount <= i;
  loop assigns i, newClusters_count, deletedCount;
  loop variant clusters_len - i;
*/
  while ((i < clusters_len))
    {
      if ((clusters[i].engine != engineType))
      {
        newClusters_count = (newClusters_count + 1);
      }
      else
      {
        deletedCount = (deletedCount + 1);
      }
      i = (i + 1);
    }
  clusters_len = newClusters_count;
  /*@ assert clusters_len >= 0 && clusters_len <= 2147483647; */
  return deletedCount;
}

/*@
    requires maxAgeDays >= 0;
    requires currentTime >= 0;
    requires snapshots != \null;
    requires snapshots_len >= 0;
    requires \valid_read(snapshots + (0 .. snapshots_len-1));
    requires \valid(result_len);
    assigns *result_len;
    ensures *result_len <= snapshots_len;
*/
int* FilterSnapshotsByAge(int maxAgeDays, int currentTime, int* result_len)
{
  int result_count = 0;
  /*@ assert result_count >= 0 && result_count <= 2147483647; */
  int i = 0;
  int ageThreshold = (currentTime - (((maxAgeDays * 24) * 60) * 60));
/*@
  loop invariant 0 <= i <= snapshots_len;
  loop invariant result_count <= i;
  loop invariant result_count <= snapshots_len;
  loop assigns i, result_count;
  loop variant snapshots_len - i;
*/
  while ((i < snapshots_len))
    {
      if ((snapshots[i].creationDate >= ageThreshold))
      {
        result_count = (result_count + 1);
      }
      i = (i + 1);
    }
  *result_len = result_count;
  int* result = (int*)0;
  return result;
}