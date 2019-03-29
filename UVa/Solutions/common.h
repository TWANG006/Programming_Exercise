#ifndef COMMON_H_
#define COMMON_H_

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <bitset>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define REP(i, a, b) for(int i=int(a); i<=int(b); i++)
#define MS(a, v) memset(a, v, sizeof a)

// Bit manipulations
#define isOn(S, j) (S & (1<<j))
#define setBit(S, j) (S |= (1<<j))
#define clearBit(S, j) (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1<<n) - 1)
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastBit(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

const double pi = 2 * acos(0.0);
const int MX = 1e5 + 7;
const int INF = 1e8 + 7;

#endif // !COMMON_H_