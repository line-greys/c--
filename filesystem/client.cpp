#include <iostream>
#include "DFactory.cpp"
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

Directory* initialize();
vector<string> parse_line(string line);
void print_dir(vector<Directory*>);
Directory *move_dir(Directory* current_dir,string name);
vector<string> getUserInfo();

int main()
{
    Directory *home = initialize();
    Directory *current_dir = home;
    vector<string> path = getUserInfo();
    bool running = 1;

    do {
        string input;
        vector <string>::iterator iter;
        cout << path[0] << "@" << path[1] << " ~";
        for(iter=path.begin() + 2;iter!=path.end();iter++){
            cout << "/" << *iter;
        }
        
        cout << " % ";
        getline(cin, input);
        //cout << "Your command: " << input << endl;
        vector<string> args = parse_line(input);
        string command = args[0];
        if(command.compare("mkdir")==0){
            if(args.size()>1){
                Directory *dir = DFactory::createDirectory(1,args[1],current_dir);
                current_dir->addChild(dir);
                if(dir){
                    cout << "Name of your new directory: " << dir->getName() << endl;
                }
            }
            else {
                cout << "Must enter a name." << endl;
            }
        }
        
        else if(command.compare("dir")==0){
            cout << "Current directory contains: " << endl;
            vector<Directory*> children = current_dir->getChild();
            print_dir(children);
        }
        else if(command.compare("cd")==0){
            if(args.size()>1){
                if(args[1].compare("..") == 0){
                    if(current_dir == home){
                        cout << "In home directory." << endl;
                    } else {
                        current_dir = current_dir->getParent();
                        path.pop_back();
                    }
                } else {
                    current_dir = move_dir(current_dir,args[1]);
                    if(!(current_dir->getName().compare(args[1])==0)){
                        cout << "No such directory." << endl;
                    } else {
                        path.push_back(args[1]);
                    }
                }
                
            } else {
                cout << "Must enter directory." << endl;
            }
        }
        else if(command.compare("bye")==0){
            running = 0;
        }
        else {
            cout << "Invalid command." << endl;
        }
    } while (running);

}

Directory* initialize(){
    Directory *home = DFactory::createDirectory(1,"home",NULL);
    return home;
}

vector<string> parse_line(string line){
    string space_delimiter = " ";
    vector<string> words;

    size_t pos = 0;
    while ((pos = line.find(space_delimiter)) != string::npos) {
        words.push_back(line.substr(0, pos));
        line.erase(0, pos + space_delimiter.length());
    }
    words.push_back(line);
    return words;

}

void print_dir(vector<Directory*> dir){
    vector<Directory*>::iterator iter;
    for(iter = dir.begin();iter!=dir.end();++iter){
        cout << (*iter)->getName() << endl;
    }
}

Directory *move_dir(Directory* current_dir,string name){
    vector<Directory*> children = current_dir->getChild();
    vector<Directory*>::iterator iter;
    for(iter = children.begin();iter!=children.end();++iter){
        if((*iter)->getName()==name){
            current_dir = *iter;
            return current_dir;
        }
    }
    return current_dir;
}

vector<string> getUserInfo(){
    vector<string> path;
    cout << "What's your name? ";
    string name;
    getline(cin,name);
    cout << "What's your machine's name? ";
    string machine_name;
    getline(cin,machine_name);
    path.push_back(name);
    path.push_back(machine_name);
    return path;
}