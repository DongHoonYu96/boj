#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int N = 5;
const int K = 7;

vector<string> grid(N);
vector<int> selected;
int answer = 0;

// 비트마스크를 사용하여 방문 여부를 빠르게 체크
bitset<25> visited;

// 4방향 이동을 위한 배열
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// DFS를 사용하여 연결성 검사
void dfs(int x, int y, int& count) {
    visited[x * N + y] = true;
    count++;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx * N + ny] && (selected[nx * N + ny] == 1)) {
            dfs(nx, ny, count);
        }
    }
}

// 선택된 7명이 서로 연결되어 있는지 확인
bool is_connected() {
    visited.reset();
    int count = 0;
    for (int i = 0; i < N * N; ++i) {
        if (selected[i] == 1) {
            dfs(i / N, i % N, count);
            break;
        }
    }
    return count == K;
}

// 백트래킹을 사용한 조합 생성
void backtrack(int idx, int s_count, int y_count) {
    if (y_count > 3) return;  // 임도연파가 4명 이상이면 더 이상 진행하지 않음
    if (s_count + y_count == K) {
        if (s_count >= 4 && is_connected()) {
            answer++;
        }
        return;
    }
    if (idx == N * N) return;

    // 현재 학생을 선택하는 경우
    selected[idx] = 1;
    backtrack(idx + 1, s_count + (grid[idx / N][idx % N] == 'S'), y_count + (grid[idx / N][idx % N] == 'Y'));
    
    // 현재 학생을 선택하지 않는 경우
    selected[idx] = 0;
    backtrack(idx + 1, s_count, y_count);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    selected.resize(N * N, 0);
    backtrack(0, 0, 0);

    cout << answer << endl;

    return 0;
}