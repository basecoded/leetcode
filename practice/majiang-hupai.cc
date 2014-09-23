bool Win(vector<vector<int>>& allPai);
bool Analyze(vector<int>& aKindPai, bool ziPai);

bool Win(vector<vector<int>>& allPai) {
  int jiangPos, yushu;
  bool jiangExisted = false;
  for (int i = 0; i < 4; i++) {
    yushu = allPai[i][0] % 3;
    if (yushu == 1)
      return false;
    else if (yushu == 2) {
      if (jiangExisted)
        return false;
      jiangExisted = true;
      jiangPos = i;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (i != jiangPos) {
      if (Analyze(allPai[i], i == 3) == false)
        return false;
    }
  }

  bool success = false;
  for (int j = 1; j < 10; j++) {
    if (allPai[jiangPos][j] >= 2) {
      allPai[jiangPos][j] -= 2;
      allPai[jiangPos][0] -= 2;
      if (Analyze(allPai[jiangPos], jiangPos == 3))
        success = true;
      allPai[jiangPos][j] += 2;
      allPai[jiangPos][0] += 2;
      if (success)
        break;
    }
  }
  return success;
}

  bool Analyze(vector<int>& aKindPai, bool ziPai) {
    if (aKindPai[0] == 0)
      return true;
    int j = 1;
    for (; j < 10; j++) {
      if (aKindPai[j] != 0)
        break;
    }
    bool result = false;
    if (aKindPai[j] >= 3) {
      aKindPai[0] -= 3;
      aKindPai[j] -= 3;
      result = Analyze(aKindPai, ziPai);
      aKindPai[0] += 3;
      aKindPai[j] += 3;
      return result;
    }
    if (!ziPai && j < 8 && aKindPai[j + 1] > 0 && aKindPai[j + 2] > 0) {
      aKindPai[0] -= 3;
      aKindPai[j]--;
      aKindPai[j + 1]--;
      aKindPai[j + 2]--;
      result = Analyze(aKindPai, ziPai);
      aKindPai[0] += 3;
      aKindPai[j]++;
      aKindPai[j + 1]++;
      aKindPai[j + 2]++;
      return result;
    }
    return false;
  }

int main() {
  vector<int> v1 { 6, 1, 4, 1, 0, 0, 0, 0, 0, 0 };
  vector<int> v2 { 3, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  vector<int> v3(10, 0);
  vector<int> v4 { 5, 2, 3, 0, 0, 0, 0, 0, 0, 0 };
  vector<vector<int>> allPai;
  allPai.push_back(v1);
  allPai.push_back(v2);
  allPai.push_back(v3);
  allPai.push_back(v4);
  cout << Win(allPai) << endl;
  return 0;
}
