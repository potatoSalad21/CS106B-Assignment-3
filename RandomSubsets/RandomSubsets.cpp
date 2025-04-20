#include <iostream>
#include "StanfordCPPLib/console.h"
#include "StanfordCPPLib/set.h"
#include "StanfordCPPLib/random.h"
using namespace std;

const double chance = 0.5;

// generate subsequences randomly
Set<int> makeSubset(Set<int> s, Set<int> res) {
    if (s.isEmpty()) return res;

    int curr = s.first();
    if (randomChance(chance)) {
        res.add(curr);
    }

    s.remove(curr);
    return makeSubset(s, res);
}

Set<int> randomSubsetOf(Set<int> &s) {
    Set<int> result;
    return makeSubset(s, result);
}

int main() {
    Set<int> testSet;
    testSet += 1;
    testSet += 2;
    testSet += 3;
    testSet += 4;
    while (true) {
        int garbage;
        cin >> garbage;
        cout << randomSubsetOf(testSet).toString() << endl;
    }

    return 0;
}

