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
#include <string.h>

int lengthOfLongestSubstring(char * s);

//using counting sort idea
int lengthOfLongestString(char * s, int len){
    char *temp = s;
    int count = len;
    char min = *temp, max = *temp;
    
    while (count-- > 0){
        if (*temp > max)
            max = *temp;
        if (*temp < min)
            min = *temp;
        temp = temp+1;
    }

    temp = s;
    count = len;
    int size = max - min + 1;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
    
    while (count-- > 0){
        arr[*temp -min] += 1;
        temp = temp+1;
    }
   
    int ret = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] != 0)
            ret ++;
    }
    
    return ret;
}

int lengthOfLongestSubstring(char * s){
    if (!strcmp(s, ""))
        return 0;
    int max = lengthOfLongestString(s, strlen(s));
    fprintf(stdout, "max:: %d\n", max);
    char * temp = s;
    for (int i = max; i > 1; i--){
        while (*(temp+i-1) != '\0'){
            if (i == lengthOfLongestString(temp, i)){
		fprintf(stdout, "substring:: %s\n", temp);
                return i;
            } 
            //have repeat 
            temp = temp+1;
        }
	temp = s;
    }
    
    return 1;
}


void main(){
    //char* string = "abcabcbb";
    char* string = "pwwkew";
    //char* string = "au";
    fprintf(stdout, "length:: %d\n", lengthOfLongestSubstring(string));
    //fprintf(stdout, "length:: %d\n", lengthOfLongestString(string, strlen(string)));
    return;
}
