#include <iostream>
#include <fstream>
#include "StanfordCPPLib/console.h"
#include "StanfordCPPLib/simpio.h"
#include "StanfordCPPLib/set.h"
#include "StanfordCPPLib/map.h"
using namespace std;

Map<char, Set<string> > loadCodonMap();
string getProteins(Map<char, Set<string>>&);
bool validProt(string&, Map<char, Set<string>>&);
void listAllRNAStrandsFor(string, Map<char, Set<string> >&, string);

int main() {
    Map<char, Set<string>> codons = loadCodonMap();
    string protein = getProteins(codons);
    listAllRNAStrandsFor(protein, codons, "");

    return 0;
}

// recursively generate all possible valid sequences
void listAllRNAStrandsFor(string protein, Map<char, Set<string>> &codonMap, string currStrand) {
    if (protein == "") { // base-case
        cout << currStrand << endl;
        return;
    }

    for (string codon : codonMap[protein[0]]) {
        listAllRNAStrandsFor(protein.substr(1), codonMap, currStrand + codon);
    }
}

Map<char, Set<string> > loadCodonMap() {
    ifstream input("codons.txt");
    Map<char, Set<string> > result;

    /* The current codon / protein combination. */
    string codon;
    char protein;

    /* Continuously pull data from the file until all data has been
     * read.
     */
    while (input >> codon >> protein) {
        result[protein] += codon;
    }

    return result;
}

// get valid user input
string getProteins(Map<char, Set<string>> &codonMap) {
    while (true) {
        string prot = getLine("Enter valid protein sequence: ");
        if (validProt(prot, codonMap)) return prot;
        cout << "ERROR: Wrong input" << endl;
    }
}

bool validProt(string &prot, Map<char, Set<string>> &codonMap) {
    for (char ch : prot) {
        if (!codonMap.containsKey(ch))
            return false;
    }

    return true;
}

