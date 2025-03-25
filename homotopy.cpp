#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

int main() {
  std::string str;
  std::getline(std::cin, str);

  // correction check
  std::unordered_map<char, std::vector<int>> counts;
  for (int ind = 0; char t : str) {
    counts[t].push_back(ind++);
  }
  for (auto& [sym, num] : counts) {
    if (num.size() != 2) {
      throw std::invalid_argument(
          std::string("symbol ") +
              sym +
              " in input provided " +
              std::to_string(num.size()) +
              " times, but 2 times were expected."
      );
    }
  }

  // construct graph
  const size_t n = str.size();
  std::vector<std::vector<size_t>> graph(2 * str.size());
  for (size_t i = 0; i < str.size(); ++i) {

    graph[i * 2].push_back((i * 2 - 1u + n * 2) % (n * 2));
    if (counts[str[i]][0] != i) {
      graph[i * 2].push_back(counts[str[i]][0] * 2 + 1);
    } else {
      graph[i * 2].push_back(counts[str[i]][1] * 2 + 1);
    }

    graph[i * 2 + 1].push_back((i * 2 + 1u + n * 2) % (n * 2));
    if (counts[str[i]][0] != i) {
      graph[i * 2 + 1].push_back(counts[str[i]][0] * 2);
    } else {
      graph[i * 2 + 1].push_back(counts[str[i]][1] * 2);
    }

  }

  // dfs to find number of bound circles
  size_t cnt = 0;
  std::stack<size_t> stack;
  std::vector<bool> used(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    if (used[i]) {
      continue;
    }
    cnt++;
    stack.push(i);
    while (!stack.empty()) {
      size_t vertex = stack.top();
      stack.pop();

      used[vertex] = true;

      for (size_t next : graph[vertex]) {
        if (!used[next]) {
          stack.push(next);
        }
      }
    }
  }
  
  cnt = std::max(cnt, 1ul); // an empty string situation
  
  std::cout << "The ribbon disk is homeomorphic to a sphere with " << (n / 2 + 1 - cnt) / 2 <<
            " handles and " << cnt << " holes.";

}
