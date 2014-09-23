// http://www.careercup.com/question?id=4699414551592960

struct Person {
  int height;
  int taller;
  char name;
  bool operator() (const Person& p1, const Person& p2) {
    return p1.height > p2.height;
  }
};
string ArrangeQueue(const vector<Person>& persons) {
  priority_queue < Person, vector<Person>, Person> q;
  for (const auto& person : persons)
    q.push(person);
  string result(persons.size(), '.');
  while (!q.empty()) {
    Person p = q.top();
    q.pop();
    int pos = p.taller + 1;
    int idx = 0;
    for (; idx < result.size(); idx++) {
      if (result[idx] == '.')
        pos--;
      if (pos == 0) {
        result[idx] = p.name;
        break;
      }
    }
  }
  return result;
}

int main() {
  vector<Person> persons;
  persons.push_back({ 6, 2, 'A'});
  persons.push_back({ 1, 4, 'B' });
  persons.push_back({ 11, 0, 'C' });
  persons.push_back({ 5, 1, 'D' });
  persons.push_back({ 10, 0, 'E' });
  persons.push_back({ 4, 0, 'F' });
}
