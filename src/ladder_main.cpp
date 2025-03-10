#include <cassert>
#include "ladder.h"

void test_adjacent() {
    assert(is_adjacent("car", "cat"));
    assert(is_adjacent("chat", "cheat"));
    assert(!is_adjacent("car", "dart"));
    assert(!is_adjacent("miniscule", "short"));
}

int main() {
    test_adjacent();

    return 0;
}