class Solution {
  public:
    void sortColors(int A[], int n) {
      int smaller = 0, equal = 0, larger = n - 1;
      while (equal <= larger) {
        if (A[equal] < 1)
          swap(A[equal++], A[smaller++]);
        else if (A[equal] > 1)
          swap(A[equal], A[larger--]);
        else
          equal++;
      }
      return;
    }
};
