class Solution {
  public:
    int removeElement(int A[], int n, int elem) {
      int start = 0, end = n - 1;
      while (start <= end) {
        while (start < n && A[start] != elem)
          start++;
        while (end >= 0 && A[end] == elem)
          end--;
        if (start < end)
          swap(A[start], A[end]);
      }
      return start;
    }
};
