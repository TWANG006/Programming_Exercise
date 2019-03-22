#pragma once

#include "common.h"

class UVA_00489
{
public:
	void Solution()
	{
		int rd;

		char solution[MX], guesses[MX];
		bool visited[MX], G[MX];

		while (cin >> rd, rd != -1)
		{
			// Read the solution
			cin >> solution;

			// Read the guesses
			cin >> guesses;

			// Get the lengths of the solution and guesses
			int slen = strlen(solution);
			int glen = strlen(guesses);

			// Clear visited array
			MS(visited, false);
			MS(G, false);

			int stroke = 0;
			bool win = false, lose = false;

			// Mark the letters of solution in visited 
			REP(i, 0, slen - 1) visited[solution[i]] = true;

			// Unmark the letters of guessed matching the already marked ones in visited
			REP(i, 0, glen - 1) {
				if (G[guesses[i]]) continue;
				G[guesses[i]] = true;

				if (visited[guesses[i]])
					visited[guesses[i]] = false;
				else
					stroke++;

				if (stroke >= 7) lose = true;

				bool found = false;
				for (char c = 'a'; c <= 'z'; c++) found |= visited[c];
				if (!found && stroke < 7) win = true;
			}
			cout << "Round " << rd << endl;
			if (win) cout << "You win." << endl;
			else if (lose) cout << "You lose." << endl;
			else cout << "You chickened out." << endl;;
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		int rd;

		char solution[MX], guesses[MX];
		bool visited[MX], G[MX];

		while (in >> rd, rd != -1)
		{
			// Read the solution
			in >> solution;

			// Read the guesses
			in >> guesses;

			// Get the lengths of the solution and guesses
			int slen = strlen(solution);
			int glen = strlen(guesses);

			// Clear visited array
			MS(visited, false);
			MS(G, false);

			int stroke = 0;
			bool win = false, lose = false;

			// Mark the letters of solution in visited 
			REP(i, 0, slen - 1) visited[solution[i]] = true;

			// Unmark the letters of guessed matching the already marked ones in visited
			REP(i, 0, glen - 1) {
				if (G[guesses[i]]) continue;
				G[guesses[i]] = true;

				if (visited[guesses[i]])
					visited[guesses[i]] = false;
				else
					stroke++;

				if (stroke >= 7) lose = true;

				bool found = false;
				for (char c = 'a'; c <= 'z'; c++) found |= visited[c];
				if (!found && stroke < 7) win = true;
			}
			out << "Round " << rd << endl;
			if (win) out << "You win." << endl;
			else if (lose) out << "You lose." << endl;
			else out << "You chickened out." << endl;;
		}

		in.close();
		out.close();
	}
};