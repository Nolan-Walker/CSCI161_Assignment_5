//
//  dictionary.cpp
//  assignment 5
//
//  Created by Nolan Caissie on 2017-04-04.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#include "dictionary.h"

Dictionary::Dictionary()
{
    head = new Node;
    head->next = NULL;
}

Dictionary::~Dictionary()
{
    Node *ptr;
    while (head != NULL) {
        ptr = head;
        head = head->next;
        delete ptr;
    }
}

Dictionary::Node *Dictionary::search(std::string homeworkName)
{
    Node *ptr = head;
    while (ptr->next != NULL && ptr->next->data->homework_name != homeworkName)
        ptr = ptr->next;
    return ptr;
}

void Dictionary::insert(std::string homeworkName, Data & data) throw (std::string)
{
    Node *ptr = search(homeworkName);
    if (ptr->next != NULL && ptr->next->data->homework_name == homeworkName)
        throw std::string("duplicate key");
    // add new entry to the end of the list
    // instead of the front of the list
    ptr->next = new Node;
    ptr = ptr->next;
    ptr->data->homework_name = homeworkName;
    ptr->data = &data;
    ptr->next = NULL;
}

void Dictionary::remove(std::string homeworkName) throw (std::string)
{
    if (head->next == NULL)
        throw std::string("Dictionary Empty");
    Node *ptr = search(homeworkName);
    if (ptr ->next == NULL)
        throw std::string("No such entry");
    Node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

Data & Dictionary::lookup(std::string homeworkName) throw (std::string)
{
    Node *ptr = search(homeworkName);
    if (ptr->next == NULL)
        throw std::string("No such entry");
    return *(ptr->next->data);
}

void Dictionary::addToFront(Node * ptr){
    Node *tmp;
    tmp = ptr;
    tmp -> next = head;
    head = tmp;
}

int Dictionary::loadData(){
    std::ifstream fin;
    std::string filename = "homework.txt";
    fin.open(filename.c_str());
    if (fin.fail()){
        std::cout << "failed to open a file." << std::endl;
        std::cout << "creating new list for future export." << std::endl;
        return 0;
    }
    //
    int number;
    fin >> number;
    std::string restofline;
    getline(fin, restofline);
    for (int i = 0; i < number; i++){
        Node *ptr = new Node;
        getline(fin, ptr -> data -> homework_name);
        getline(fin, ptr -> data -> submit_deadline);
        getline(fin, ptr -> data -> teacher_info);
        getline(fin, ptr -> data -> description);
        addToFront(ptr);
    }
    fin.close();
    return number;
}

void Dictionary::printNames(){
    while (head != NULL){
        std::cout << head -> data -> homework_name << std::endl;
        head = head -> next;
    }
    
}
