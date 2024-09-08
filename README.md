# SpellChecker

## Problem Statement

Design an efficient spell checker using a trie data structure which supports the following functionalities:

### Required Features

1. **SpellCheck**: Check if the input string is present in the dictionary.
2. **Autocomplete**: Find all the words in the dictionary which begin with the given input.
3. **Autocorrect**: Find all the words in the dictionary which are at an edit distance (Levenshtein distance) of at most 3 from the given input.

### Input Format

- The first line will contain two space-separated integers `n` and `q` which represent the number of words in the dictionary and the number of queries to be processed respectively.
- The next `n` lines will contain a single string each which represents a word in the dictionary.
- The next `q` lines will contain two space-separated values: the first one will be an integer `ai` and the second will be a string `ti`.
  - `ai=1` means SpellCheck operation needs to be done on `ti`.
  - `ai=2` means Autocomplete operation needs to be done on `ti`.
  - `ai=3` means Autocorrect operation needs to be done on `ti`.
  
Both strings `s` and `t` consist of lowercase English letters.

### Output Format

For each query print the result on a new line:
- **SpellCheck**: Print `1` if the string is present in the dictionary, otherwise print `0`.
- **Autocomplete & Autocorrect**: Print the number of words found in the first line. The following lines will be the set of words in lexicographical order.

### Constraints

- `1 <= n <= 1000`
- `1 <= q <= 1000`
- `1 <= len(s) <= 100`
- `1 <= len(ti) <= 110`

### Sample Input

  10 4 consider filters filers entitled tilers litter dames filling grasses fitter 1 litter 1 dame 2 con 3 filter

  
### Sample Output

1 0 1 consider 5 filers filters fitter litter tilers


### Note

1. Only tries should be used for storing the words in the dictionary.
2. You are allowed to use vectors for this problem.
