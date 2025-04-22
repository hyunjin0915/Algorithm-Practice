#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

map<string, multiset<string>> m;
map<pair<string, string>, int> ticket_count;
vector<string> answer;
bool finished = false;

void DFS(string from, int depth, int total_ticket_count)
{
    answer.push_back(from);

    if (depth == total_ticket_count) {
        finished = true;
        return;
    }

    for (auto to : m[from]) {
        auto key = make_pair(from, to);
        if (ticket_count[key] > 0) {
            ticket_count[key]--;
            DFS(to, depth + 1, total_ticket_count);
            if (finished) return;
            ticket_count[key]++;
        }
    }

    answer.pop_back(); // 백트래킹
}

vector<string> solution(vector<vector<string>> tickets) {
    // 1. 그래프 구성 및 티켓 수 세기
    for (auto& ticket : tickets) {
        m[ticket[0]].insert(ticket[1]);
        ticket_count[{ticket[0], ticket[1]}]++;
    }

    DFS("ICN", 0, tickets.size());

    return answer;
}
