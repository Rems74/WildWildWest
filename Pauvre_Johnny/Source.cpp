#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void WriteTxt(map<char, int> Mymap) {

    ofstream text;

    text.open("txt/Occurrences.txt");
    if (text) {
        text << "Les Occurrences demander : " << endl ;
        for (map<char, int>::iterator it = Mymap.begin(); it != Mymap.end(); it++) {
            text << (*it).first << " = " << it->second << endl;
        }
    }
    else {
        cout << "erreur";
    }
}

string ReadTxt() {

    string text;
    string test = "";

    ifstream txt;

    txt.open("txt/WildWildWest.txt");

    if (txt) {
        while (not txt.eof()) {
            txt >> text;
            test += text;
        }
    }
    else {
        cout << "erreur";
    }

    return test;
}

void nbOccurrences(char c, map<char, int>& Mymap)
{
    int count = 0;

    for (char i : ReadTxt()) {
        if (i == c) {
            count++;
        }
    }

    Mymap.insert(pair<char, int>(c, count));

}

int main() {

    map<char, int> Mymap;

    int end = 1;
    char chr;

    while (end == 1) {
        cout << "quelle lettre voulez vous pour en connaitre le nombre de fois qu'elle est dans le fichier texte : ";

        cin >> chr;

        nbOccurrences(chr, Mymap);

        cout << " voulez vous encore d'autre lettre/symbole ?" << endl << "Si oui : 1               Si non : 0" << endl;

        cin >> end;
    }

    for (map<char, int>::iterator it = Mymap.begin(); it != Mymap.end(); it++) {
        cout << (*it).first << " = " << it->second << endl;
    }

    cout << "Tous vos demandes sont ecrit dans le fichier texte Occurences dans le dossier txt." << endl;

    WriteTxt(Mymap);

    return 0;
}