
#include "PhoneticFinder.hpp"

using namespace std;


bool equals(char a, char b, const char x, const char y){
    return (a == x || a == y) && (b == x || b == y);
}

bool equals(char a, char b, const char x, const char y, const char z){
    return (a == x || a == y || a == z) && (b == x || b == y || b == z);
}

bool equals(char a, char b){
    if('A' <= a && a <= 'Z')
        a = a - 'A' + 'a';
    if('A' <= b && b <= 'Z')
        b = b - 'A' + 'a';
    
    return a == b || 
        equals(a, b, 'v', 'w') || 
        equals(a, b, 'b', 'f', 'p') || 
        equals(a, b, 'g', 'j') || 
        equals(a, b, 'c', 'k', 'q') || 
        equals(a, b, 's', 'z') || 
        equals(a, b, 'd', 't') || 
        equals(a, b, 'u', 'o') || 
        equals(a, b, 'i', 'y');
}

bool equals(string s, string t){
    if(s.length() != t.length())
        return false;

    for(size_t i = 0; i < s.length(); i++)
        if(!equals(s.at(i), t.at(i)))
            return false;
    return true;
}

string phonetic::find(string text, string word){

    if(word == "" || word == " ")
        throw runtime_error("empty word - we Can't search");

    string tmp = "";
    for(size_t i = 0; i <= text.length(); i++){
        if(i == text.length() || text.at(i) == ' '){
            if(equals(tmp, word))
                return tmp;
        
            tmp = "";
        } else 
            tmp += text.at(i);
    }
    throw runtime_error("Did not find the word '"+word+"' in the text");
}
