#include "StanfordCPPLib/console.h"
#include "StanfordCPPLib/vector.h"
#include "StanfordCPPLib/set.h"
using namespace std;

/*
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.
 */
bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
                               Vector< Set<string> >& result);

int main() {
    // test here

    return 0;
}

bool canOfferUniversalCoverage(Set<string>& cities, Vector< Set<string> >& locations, int numHospitals, Vector< Set<string> >& result) {
    // base cases
    if (cities.isEmpty()) return true;
    if (numHospitals == 0) return false;

    for (Set<string> loc : locations) {
        Set<string> citiesCopy = cities;
        for (string city : loc) {
            citiesCopy.remove(city);
        }

        result.add(loc);
        if (canOfferUniversalCoverage(citiesCopy, locations, numHospitals - 1, result)) {
            return true;
        }

        result.remove(result.size() - 1);
    }

    return false;
}


