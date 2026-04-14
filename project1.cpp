#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Function Protos
void getWords(vector<string> &words, ifstream &file);
void sortWords(vector<string> &words);
vector<pair<string, int>> getWordCounts(vector<string> &words);

int main(){
    ifstream file("homes.txt");
    vector<string> words;

    getWords(words, file);
    sortWords(words);
    vector<pair<string, int>> counts = getWordCounts(words);
    //TESTING LOOP
    /*int i;
    for(i = 0; i < words.size(); i++){
        cout << words[i] << ". ";
    } */

    for(int t = 0; t < counts.size(); t++){
        cout << "Word: " << counts[t].first << " (Frequency:  " << counts[t].second << ")" << endl;
    }

    file.close();
    return 0;
}



//Function Defs
void getWords(vector<string> &words, ifstream &file){
    string word;
    while (file >> word){
        words.push_back(word);
    }
    
}

void sortWords(vector<string> &words){
    sort(words.begin(), words.end());
}

vector<pair<string, int>> getWordCounts(vector<string> &words){
    vector<pair<string, int>> count;
    string wordhold = words[0];
    int counter = 1;

    for (int i = 1; i < words.size(); i++){
        if(words[i] == wordhold){
            counter++;
        }
        else{
            count.push_back(make_pair(wordhold, counter));
            wordhold = words[i];
            counter = 1;
        }
    }
    count.push_back(make_pair(wordhold, counter));
    return count;
}
