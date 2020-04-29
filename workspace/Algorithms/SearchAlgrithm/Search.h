#pragma once
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<unordered_set>
#include<stack>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid);

int ladderLength(string beginWord, string endWord, vector<string>& wordList);
//int ladderLength2(string beginWord, string endWord, vector<string>& wordList);

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix);

void solve(vector<vector<char>>& board);

int maxAreaOfIsland(vector<vector<int>>& grid);