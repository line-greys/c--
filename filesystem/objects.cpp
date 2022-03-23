#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

class SubDir;

class Directory {
    protected:
        string name;
        Directory *parent;
    public:
        virtual string getName() = 0;
        virtual void setName(string aName) = 0;
        virtual vector<Directory*> getChild() = 0;
        virtual void addChild(Directory * child) = 0;
        virtual Directory* getParent() = 0;
};

class SubDir: public Directory {
    private:
        vector<Directory*> children;
    public:
        SubDir(string aName, Directory *aParent = nullptr)
        {
            name = aName;
            parent = aParent;
            
        };
        string getName() {return name;}
        void setName(string aName) {this->name = aName;}
        vector<Directory*> getChild() {return children;}
        void addChild(Directory * child) {children.push_back(child);}
        Directory* getParent(){return parent;}
};

class File: public Directory {
    //private: 
        //string content;

    public:
        File(string aName, Directory *aParent = nullptr)
        {
            name = aName;
            parent = aParent;
            
        };
        string getName() {return name;}
        void setName(string aName) {this->name = aName;}
        vector<Directory*> getChild() {
            vector<Directory*> v;
            return v;
            }
        void addChild(Directory * child){name = name;}
        Directory* getParent(){return parent;}
};