#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<string_view>
#include<stack>
using namespace std;

string reverseWords(string s);
string reverseWords2(string s);

bool isPalindrome(int x);

bool isAnagram(string s, string t);

bool isIsomorphic(string s, string t);

int longestPalindrome(string s);

int countSubstrings(string s);

int countBinarySubstrings(string s);

int myAtoi(string str);

int getMaxRepetitions(string s1, int n1, string s2, int n2);

string removeDuplicates(string s, int k);

string removeDuplicateLetters(string s);