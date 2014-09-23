// Cracking the coding interview 7.7

int GetTheKthMagicNumber(int k) {
  queue<int> queue3, queue5, queue7;
  queue3.push(1);
  int val = 0;
  for (int i = 0; i <= k; i++) {
    int v3 = queue3.size() > 0 ? queue3.front() : INT_MAX;
    int v5 = queue5.size() > 0 ? queue5.front() : INT_MAX;
    int v7 = queue7.size() > 0 ? queue7.front() : INT_MAX;
    val = min(v3, min(v5, v7)); 
    if (val == v3) {
      queue3.pop();
      queue3.push(val * 3);
      queue5.push(val * 5);
    } else if (val == v5) {
      queue5.pop();
      queue5.push(val * 5);
    } else {
      queue7.pop();
    }
    queue7.push(val * 7);
  }
  return val;
}

int main() {
  for (int i = 1; i <= 6; i++)
    cout << GetTheKthMagicNumber(i) << endl;
  return 0;
}
