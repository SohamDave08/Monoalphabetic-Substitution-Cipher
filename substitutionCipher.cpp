#include <iostream>
#include <iterator>
#include<map>
#include<vector>

using namespace std;

class Substitution
{
    private:
        map<char, char> m1;
        string str;
        vector<char> ct,pt;
    public:
        Substitution()
        {
            m1.insert(pair<char,char>('a','Z'));
            m1.insert(pair<char,char>('b','Y'));
            m1.insert(pair<char,char>('c','X'));
            m1.insert(pair<char,char>('d','W'));
            m1.insert(pair<char,char>('e','V'));
            m1.insert(pair<char,char>('f','U'));
            m1.insert(pair<char,char>('g','T'));
            m1.insert(pair<char,char>('h','S'));
            m1.insert(pair<char,char>('i','R'));
            m1.insert(pair<char,char>('j','Q'));
            m1.insert(pair<char,char>('k','P'));
            m1.insert(pair<char,char>('l','O'));
            m1.insert(pair<char,char>('m','N'));
            m1.insert(pair<char,char>('n','M'));
            m1.insert(pair<char,char>('o','L'));
            m1.insert(pair<char,char>('p','K'));
            m1.insert(pair<char,char>('q','J'));
            m1.insert(pair<char,char>('r','I'));
            m1.insert(pair<char,char>('s','H'));
            m1.insert(pair<char,char>('t','G'));
            m1.insert(pair<char,char>('u','F'));
            m1.insert(pair<char,char>('v','E'));
            m1.insert(pair<char,char>('w','D'));
            m1.insert(pair<char,char>('x','C'));
            m1.insert(pair<char,char>('y','B'));
            m1.insert(pair<char,char>('z','A'));
            m1.insert(pair<char,char>(' ','*'));
        }
        void getData()
        {
            cout<<"Enter Plain Text:  ";
            getline(cin, str);
        }
        void encrypt()
        {
            for(int i = 0; i<str.length(); i++) {
                map<char, char>::iterator itr;
                for (itr = m1.begin(); itr != m1.end(); itr++) {
                    if(str.at(i) == itr->first)
                    {
                        ct.push_back(itr->second);
                    }
                }
            }
        }
        void decrypt()
        {
            for(char x: ct)
            {
                map<char, char>::iterator itr;
                for (itr = m1.begin(); itr != m1.end(); itr++) {
                    if(x == itr->second)
                    {
                        pt.push_back(itr->first);
                    }
                }
            }
        }
        void showCT()
        {
            cout<<"Cipher Text:  ";
            for(char x: ct)
            {
                cout<<x;
            }
        }
        void showPT()
        {
            cout<<endl<<"Decrypted Cipher Text:  ";
            for(char x: pt)
            {
                cout<<x;
            }
        }
};

int main()
{
    Substitution s;
    cout<<endl<<"------------Substitution Cipher------------"<<endl;
    s.getData();
    cout<<endl;
    s.encrypt();
    s.showCT();
    s.decrypt();
    s.showPT();
    cout<<endl;
    return 0;
}