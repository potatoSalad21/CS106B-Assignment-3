#include <iostream>
#include "StanfordCPPLib/console.h"
#include "StanfordCPPLib/simpio.h"
using namespace std;

bool isSubsequence(string txt, string subseq) {
    // base-cases
    if (txt == "" && subseq == "") return true;
    if (txt == "") return false; // subseq is non-empty and txt is empty

    // if chars match consider next two chars
    if (txt[0] == subseq[0]) return isSubsequence(txt.substr(1), subseq.substr(1));
    else return isSubsequence(txt.substr(1), subseq); // skip char
}

int main() {
    while (true) {
        string mainWord = getLine("Enter the main word (return to exit): ");
        if (mainWord.empty()) break;
        string testWord = getLine("Enter the test word (return to exit): ");
        if (testWord.empty()) break;

        cout << (isSubsequence(mainWord, testWord) ? "YES" : "NO");
        cout << endl;
    }

    return 0;
}

