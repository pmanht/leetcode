/************************************
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.


 ************************************/

#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s);

//using counting sort idea
int lengthOfLongestSubstring(char * s){
    char *temp = s;
    char min = 0, max = 0;

    while (*temp != '\0'){
        if (*temp > max)
            max = *temp;
        if (*temp < min)
            min = *temp;
	temp = temp+1;
    }

    temp = s;
    int len = max - min + 1;
    char arr[len];
    for (int i = 0; i < len; i++)
        arr[i] = 0;

    while (*temp != '\0'){
        arr[(int)(*temp -min)] += 1;
        temp = temp+1;
    }

    int ret = 0;
    for (int i = 0; i < len; i++)
        if (arr[i] != 0)
            ret ++;

    return ret;
}


void main(){
    char* string = "abcabcbb";
    fprintf(stdout, "length:: %d\n", lengthOfLongestSubstring(string));
    return;
}
