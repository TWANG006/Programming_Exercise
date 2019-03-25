#pragma once

#include "common.h"

/*
	Print a blank line after each test case - even after the last one. 
	Printing a blank line only in between each test case will result 
	in a verdict of wrong answer on UVa.
*/
class UVA_00401
{
	unordered_map<char, char> reverseMap = {
		{'A', 'A'},		{'E', '3'},		{'H', 'H'},
		{'I', 'I'},		{'J', 'L'},		{'L', 'J'},
		{'M', 'M'},		{'O', 'O'},		{'S', '2'},
		{'T', 'T'},		{'U', 'U'},		{'V', 'V'},
		{'W', 'W'},		{'X', 'X'},		{'Y', 'Y'},
		{'Z', '5'},		{'1', '1'},		{'2', 'S'},
		{'3', 'E'},		{'5', 'Z'},		{'8', '8'}
	};

	bool isMirror(const string& s)
	{
		int i = 0, j = s.size() - 1;

		if (s.size() % 2 == 0)
		{
			while (i <= j - 1) {
				if (reverseMap.find(s[i]) == reverseMap.end())
				{
					return false;
				}
				else
				{
					if (reverseMap[s[i]] != s[j])
						return false;
				}
				i++;
				j--;
			}
		}
		else
		{
			while (i <= j) {
				if (reverseMap.find(s[i]) == reverseMap.end())
				{
					return false;
				}
				else
				{
					if (reverseMap[s[i]] != s[j])
						return false;
				}
				i++;
				j--;
			}
		}

		return true;
	}
	bool isPalindrome(const string& s)
	{
		int i = 0, j = s.size() - 1;

		if (s.size() % 2 == 0)
		{
			while (i <= j - 1) {
				if (s[i] != s[j])
					return false;
				i++;
				j--;
			}
		}
		else
		{
			while (i <= j) {
				if (s[i] != s[j])
					return false;
				i++;
				j--;
			}
		}
		return true;
	}
	void is_mirror_or_palindrome(const string&s, bool &isMirror, bool &isPalindrome)
	{
		isMirror = true;
		isPalindrome = true;

		int i = 0, j = s.size() - 1;
		if (s.size() % 2 == 0)
		{
			while (i <= j - 1) {

				if (reverseMap.find(s[i]) == reverseMap.end())
				{
					isMirror = false;
				}
				else
				{
					if (reverseMap[s[i]] != s[j])
						isMirror = false;
				}

				if (s[i] != s[j])
					isPalindrome = false;
				i++;
				j--;
			}
		}
		else
		{
			while (i <= j) {
				if (reverseMap.find(s[i]) == reverseMap.end())
				{
					isMirror = false;
				}
				else
				{
					if (reverseMap[s[i]] != s[j])
						isMirror = false;
				}

				if (s[i] != s[j])
					isPalindrome = false;
				i++;
				j--;
			}
		}
	}

public:

	void Solution()
	{
		string s;
		bool blank = false;

		while (getline(cin, s))
		{
			bool bIsMirr = isMirror(s);
			bool bIsPalin = isPalindrome(s);

			if (blank)
			{
				cout << endl;
			}

			blank = true;

			if (bIsMirr && bIsPalin)
				cout << s << " --" << " is a mirrored palindrome." << endl;
			else if (bIsMirr && (!bIsPalin))
				cout << s << " --" << " is a mirrored string." << endl;
			else if ((!bIsMirr) && bIsPalin)
				cout << s << " --" << " is a regular palindrome." << endl;
			else
				cout << s << " --" << " is not a palindrome." << endl;
		}
		cout << endl;
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		string s;
		bool blank = false;

		while (getline(in, s))
		{
			bool bIsMirr = isMirror(s);
			bool bIsPalin = isPalindrome(s);			

			if (blank)
			{
				out << endl;
			}

			blank = true;

			if (bIsMirr && bIsPalin)
				out << s << " --" << " is a mirrored palindrome." << endl;
			else if (bIsMirr && (!bIsPalin))
				out << s << " --" << " is a mirrored string." << endl;
			else if ((!bIsMirr) && bIsPalin)
				out << s << " --" << " is a regular palindrome." << endl;
			else
				out << s << " --" << " is not a palindrome." << endl;			
		}
		out << endl;

		in.close();
		out.close();
	}
};