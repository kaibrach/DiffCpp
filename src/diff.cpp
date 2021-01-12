#include "../include/diff.h"

using namespace std;

int main(int argc, char** argv) {

    cout << Starting_MSG << endl;

    if (argc < 3) {
        cout << "Insufficient number of file specifications" << endl;
        return 0;
    }
    
    // Start a single session for files comparison
    DiffSession session(argc, argv);
    
    // Get the diff and Display it for the running session
    session.showDiff();

    return 0;
}
