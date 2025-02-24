#include <iostream>
#include <fstream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

/**
 * Outputs the content of an input stream with optional line numbering
 * @param is - Input stream to process
 * @param prefix - Prefix to add before each line
 * @param enumerate - Line numbering mode: 0=none, 1=all lines, 2=non-empty lines
 */
void outstream(istream& is, string prefix, int enumerate) {
    int counter = 0;
    string line;
    
    while (getline(is, line)) {
        if (enumerate) {
            // For mode 2 (-b), only number non-empty lines
            if (!(enumerate == 2 && line.empty())) {
                counter++;
                prefix = to_string(counter) + " ";
                cout << prefix;
            }
        }
        cout << line << "\n";
    }
}

int main(int argc, char *argv[]) {
    fastio;
    // Handle stdin input when no files are specified
    if (argc == 1 || string(argv[1]) == "-") {
        string line;
        while (getline(cin, line)) {
            cout << line << "\n";
        }
        return 0;
    }

    string prefix = "";
    int enumerate = 0;
    bool read_input = false;

    // Parse command line options
    if (argv[1][0] == '-') {
        read_input = true;
        string args = argv[1];
        
        // Process each flag in the argument
        for (size_t i = 1; i < args.length(); i++) {
            switch (args[i]) {
                case 'n': // Number all lines
                    enumerate = 1;
                    break;
                case 'b': // Number non-blank lines
                    enumerate = 2;
                    break;
            }
        }
    }

    // Process each input file or stdin
    for (int i = 1; i < argc; i++) {
        if (read_input) {
            outstream(cin, prefix, enumerate);
        } else {
            ifstream fin(argv[i]);
            if (!fin) {
                cerr << "Error: Cannot open file " << argv[i] << "\n";
                continue;
            }
            outstream(fin, prefix, enumerate);
            fin.close();
        }
    }

    return 0;
}