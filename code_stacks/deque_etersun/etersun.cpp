#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    vector<int> array = {1, 2, 4, 3, 6, 7};
    vector<int> results(array.size());
    results[0] = array[0];
    int jump_size = 3;
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i < array.size(); i++) {
        int best_previous = results[q.front()];
        results[i] = best_previous + array[i];
        // If the best people have retired, remove them from the team
        while (q.front() <= i - jump_size)
            q.pop_front();
        // Everyone who is senior to you and worse, kick them out
        while (!q.empty() && results[q.back()] >= results[i]) {
            q.pop_back();
        }
        // Put yourself in the team
        q.push_back(i);
    }
    cout << results[results.size() - 1] << endl;
    cout << "DEBUG: "; for (auto el : results) cout << el << ' '; cout << endl;
}