#include <iostream>
#include <fstream>
#include "StanfordCPPLib/console.h"
#include "StanfordCPPLib/simpio.h"
#include "StanfordCPPLib/set.h"
#include "StanfordCPPLib/map.h"
using namespace std;

Map<char, Set<string>> readCodons();
string getProteins(Map<char, Set<string>>&);
bool validProt(string&, Map<char, Set<string>>&);
void listAllRNAStrandsFor(Map<char, Set<string>>&, string, string);

int main() {
    Map<char, Set<string>> codons = readCodons();
    string protein = getProteins(codons);
    listAllRNAStrandsFor(codons, protein, "");

    return 0;
}

// recursively generate all possible valid sequences
void listAllRNAStrandsFor(Map<char, Set<string>> &codonMap, string protein, string currStrand) {
    if (protein == "") { // base-case
        cout << currStrand << endl;
        return;
    }

    for (string codon : codonMap[protein[0]]) {
        listAllRNAStrandsFor(codonMap, protein.substr(1), currStrand + codon);
    }
}

// this function reads the file and stores the codons in a hashmap
Map<char, Set<string>> readCodons() {
    ifstream data("codons.txt");
    Map<char, Set<string>> codons;

    string codon;
    char prot;
    while (data >> codon >> prot) {
        codons[prot] += codon;
    }

    return codons;
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

