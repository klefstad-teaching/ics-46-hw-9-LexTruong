#include <cassert>
#include "ladder.h"

void test_adjacent() {
    assert(is_adjacent("car", "cat"));
    assert(is_adjacent("chat", "cheat"));
    assert(!is_adjacent("car", "dart"));
    assert(!is_adjacent("miniscule", "short"));
}

void test_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    vector<string> ladder = generate_word_ladder("car", "cheat", word_list);
    print_word_ladder(ladder);
    cout << endl;
    ladder = generate_word_ladder("Marty", "curls", word_list);
    print_word_ladder(ladder);
    cout << endl;
    ladder = generate_word_ladder("code", "data", word_list);
    print_word_ladder(ladder);
    cout << endl;
}

int main() {
    test_adjacent();
    test_word_ladder();

    return 0;
}