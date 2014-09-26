class Solution {
  public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
      int total = m + n;
      if(total % 2 == 1)
        return findKth(A, m, B, n, total / 2 + 1);
      else
        return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
    }

    double findKth(int A[], int m, int B[], int n, int k) {
      if(m > n)
        return findKth(B, n, A, m, k);
      if(m == 0)
        return B[k-1];
      if(k == 1)
        return min(A[0], B[0]);

      int ia = min(k/2, m);
      int ib = k - ia;
      if(A[ia - 1] < B[ib - 1])
        return findKth(A + ia, m - ia, B, n, k - ia);
      else if(A[ia - 1] > B[ib - 1])
        return findKth(A, m, B + ib, n - ib, k - ib);
      else
        return A[ia - 1];
    }
};
