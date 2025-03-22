#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class Tokenizer
{
public:

    Tokenizer(string filename)
    {
        in.open(filename);
        if ( !in )
        {
           cerr << "File does not exist!\n";
        }
    }

    string getToken()
    {
        return (ss >> token) ? token : "";
    }

    string getLine()
    {
        return line;
    }

    bool nextLine()
    {
        while(getline(in, line))
        {
            if (!line.size()) continue;
            ss.clear();
            ss.str(line);
            return true;
        }
        return false;
    }

private:

    string token, line;
    istringstream ss;
    ifstream in;
};
