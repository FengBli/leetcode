## leetcode刷题记录

### 1. \#(AC)
> 43

- Easy: 23
- Medium: 20

### 2. TODO list
- [ ] [easy]168 Excel number convert to title
- [ ] [medium] 43 string multiplication

### 3. Notes

#### 3.1. [17 phone letter combinations]

> char** letterCombinations(char* digits, int* returnSize){...}

DO NOT malloc addr-space for returnSize. I've been stuck on this for nearly an hour. ~returnSize = (int*) malloc(sizeof(int));~
