#include "ladder.h"

using namespace std;

#define my_assert(e) {cout << #e << ((e) ? " passed" : " failed") << endl;}

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
            if (num_diff == 1)
                return false;
            ++num_diff;
            (len1 > len2) ? ++i : ++j;
        } else {
            ++i;
            ++j;
        }
    }
    return true;
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

vector<string> generate_word_ladder(const string& begin_word,
                                    const string& end_word, 
                                    const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    vector<string> ladder, new_ladder;
    string last_word;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()) {
        ladder = ladder_queue.front();
        ladder_queue.pop();
        last_word = ladder.back();
        for (string word: word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    for(string word; in >> word;)
        word_list.insert(word);
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    for (string word: ladder)
        cout << word << " ";
}


void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}