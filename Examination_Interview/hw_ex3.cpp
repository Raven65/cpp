//#define hw_ex3
#ifdef hw_ex3

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(vector<vector<int>> &board, vector<vector<int>> &steps, int goal_x, int goal_y, string & target) {
	queue<pair<int,int>> q;
	vector<int> dx{ 1,0,-1,0 }, dy{ 0,1,0,-1 };
	vector<vector<string>> monster(board.size(), vector<string>(board.size(),"1"));
	q.push(make_pair(0,0));
	steps[0][0] = 0;
	while (q.size()) {
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first, y = p.second;
		if (x == goal_x && y == goal_y) break;
		for (int i = 0; i < 4; ++i) {
			int next_x = x + dx[i], next_y = y + dy[i];
			if(next_x<0||next_y<0||next_x>=board.size()||next_y>=board.size()) continue;
			if (steps[next_x][next_y]==-1&&board[next_x][next_y] >= 1 &&  (board[next_x][next_y]+'0'>monster[x][y].back()|| monster[x][y].find(board[next_x][next_y]+'0')!=string::npos)) {
				monster[next_x][next_y] = monster[x][y];
				if (board[next_x][next_y] + '0' > monster[x][y].back())
					monster[next_x][next_y].push_back(board[next_x][next_y] + '0');
				if (next_x == goal_x && next_y == goal_y && monster[next_x][next_y] != target) continue;
				else {
					steps[next_x][next_y] = steps[x][y] + 1;
					q.push(make_pair(next_x, next_y));
				}
				
			}
		}
	}
}
int main() {
	vector<int> input;
	int n;
	while (cin >> n) input.push_back(n);
	n = sqrt(input.size());
	int gx = 0, gy = 0;
	int max = 1;
	vector<vector<int>> board(n, vector<int>(n));
	vector<vector<int>> steps(n, vector<int>(n,-1));
	string target("1");
	for (int i = 0,k = 0; i != n; ++i) {
		for (int j = 0; j != n; ++j) {
			board[i][j] = input[k++];
			if (board[i][j] > max) {
				max = board[i][j];
				gx = i;
				gy = j;
			}
			if (board[i][j] > 1) {
				target.push_back(board[i][j]+'0');
			}

		}
	}
	sort(target.begin(), target.end());
	bfs(board, steps, gx, gy,target);
	cout << steps[gx][gy];
	return 0;
}

#endif