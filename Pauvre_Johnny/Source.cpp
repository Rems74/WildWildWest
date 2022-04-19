#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void nbOccurrences(char c, string str, map<char, int>& Mymap)
{
    int count = 0;

    for (char i : str) {
        if (i == c) {
            count++;
        }
    }

    Mymap.insert(pair<char, int>(c, count));

}

int main() {

    map<char, int> Mymap;

    char ch1 = 'e';
    char ch2 = 'h';

    string str1("zero e enfin la eeeeee ee e e e eil y en as 4");
    string str2("pas de h enfin hla sh hmaish tg");
    
    nbOccurrences(ch1, str1, Mymap);

    for (map<char, int>::iterator it = Mymap.begin(); it != Mymap.end(); it++) {
        cout << (*it).first << " = " << it->second << endl;
    }

    return 0;
}