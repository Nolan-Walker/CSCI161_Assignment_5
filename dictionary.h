//
//  dictionary.h
//  assignment 5
//
//  Created by Nolan Caissie on 2017-04-04.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#ifndef dictionary_h
#define dictionary_h
#include <iostream>
#include <fstream>
class Data // Objects to put into Dictionary
{
public:
    int key;
    std::string homework_name;
    std::string submit_deadline;
    std::string teacher_info;
    std::string description;
};
class Dictionary
{
private:
    struct Node {
        Data * data;
        Node * next;
    };
    Node * search(std::string);
    Node * head;

public:
    Dictionary();
    ~Dictionary();
    int loadData();
    void remove();
    void printNames();
    void addToFront(Node*);
    void insert(std::string homeworkName, Data &) throw (std::string);
    void remove(std::string homeworkName) throw (std::string);
    Data & lookup(std::string) throw (std::string);

};

#endif /* dictionary_h */
