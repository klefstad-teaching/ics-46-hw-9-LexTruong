#include <iostream>
#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg) {
    cout << word1 << " and " << word2 << ": " << msg << endl;
}

// bool edit_distance_within(const std::string& str1,
//                             const std::string& str2, int d);

bool is_letter_substitution(const string& word1, const string& word2) {
    int len = word1.length();
    int num_diff = 0;
    for (int i=0; i < len; ++i)
        if (word1[i] != word2[i])
            ++num_diff;
    return num_diff == 1;
}

bool is_letter_insertion(const string& word1, const string& word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    int i = 0, j = 0, num_diff = 0;
    while (i < len1 && j < len2) {
        if (word1[i] != word2[j]) {
            ++num_diff;
            (len1 > len2) ? ++i : ++j;
        } else {
            ++i;
            ++j;
        }
    }
    return num_diff == 1;
}

bool is_adjacent(const string& word1, const string& word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    if (abs(len1-len2) > 1)
        return false;
    else if (len1 == len2)
        return is_letter_substitution(word1, word2);
    else
        return is_letter_insertion(word1, word2);
}

// vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list);

// void load_words(set<string> & word_list, const string& file_name);

void print_word_ladder(const vector<string>& ladder) {
    for (string word: ladder)
        cout << word << " ";
}

// void verify_word_ladder();