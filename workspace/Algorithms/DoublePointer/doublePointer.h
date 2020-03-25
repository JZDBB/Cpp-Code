#pragma once
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool judgeSquareSum(int c);

vector<int> twoSum(vector<int>& numbers, int target);

char a[10] = { 'a', 'e', 'i', 'o', 'u' , 'A', 'E', 'I', 'O', 'U' };
vector<char> Vowels(a, a + 10);
string reverseVowels(string s);

bool validPalindrome(string s);

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

bool isSubsequence(string s, string d);

void moveZeroes(vector<int>& nums);

int removeElement(vector<int>& nums, int val);

int removeDuplicates(vector<int>& nums);

int removeDuplicates2(vector<int>& nums);


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head);

ListNode *detectCycle(ListNode *head);

ListNode* middleNode(ListNode* head);