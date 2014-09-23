// http://www.careercup.com/question?id=5678435150069760

int convertVectorToInt(const vector<int>& num) {
  int result = 0;
  for (const auto& i : num)
    result = result * 10 + i;
  return result;
}

int getSum(vector<int>& A) {
  int first_digit_a = -1, first_digit_b = -1;
  vector<int> a, b;
  bool its_a_turn = true;
  sort(A.begin(), A.end());
  for (int i = 0; i < A.size(); i++) {
    if (A[i] != 0) {
      if (first_digit_a == -1) {
        first_digit_a = i;
        a.push_back(A[i]);
        its_a_turn = false;
      } else if (first_digit_b == -1) {
        first_digit_b = i;
        b.push_back(A[i]);
        its_a_turn = true;
        break;
      }
    }
  }
  for (int i = 0; i < A.size(); i++) {
    if (i != first_digit_a && i != first_digit_b) {
      if (its_a_turn)
        a.push_back(A[i]);
      else
        b.push_back(A[i]);
      its_a_turn = !its_a_turn;
    }
  }
  return convertVectorToInt(a) + convertVectorToInt(b);
}

int main() {
  vector<int> v{1, 1, 1, 1, 0, 0};
  cout << getSum(v) << endl;
  return 0;
}
