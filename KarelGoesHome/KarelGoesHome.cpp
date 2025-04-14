#include <iostream>
#include "StanfordCPPLib/console.h"
#include "StanfordCPPLib/simpio.h"
using namespace std;

/* Recursive function that counts paths to (1,1) spot
 *  we can move only up or left =>
 *  => for each spot we go left or up IF there is no wall.
*/
int numPathsHome(int street, int avenue) {
    if (street == 1 && avenue == 1) return 1; // base case: already reached (1,1)
    if (street < 1 || avenue < 1) return 0; // out of bounds

    return numPathsHome(street - 1, avenue) + numPathsHome(street, avenue - 1);
}

int main() {
    const int sentinel = -1;
    while (true) {
        int row = getInteger("Enter street number (-1 to exit): ");
        if (row == sentinel) break;

        int col = getInteger("Enter avenue number (-1 to exit): ");
        if (col == sentinel) break;

        cout << "Number of paths home: " << numPathsHome(row, col) << endl;
    }

    return 0;
}

