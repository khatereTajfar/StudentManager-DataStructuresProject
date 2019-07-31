#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree()
{
    root=NULL;
}

Student *BinarySearchTree::SearchByFamilyName(QString familyName){
    Student *t=root;
    while (t) {
        if(familyName==t->FamilyName)   return t;
        if(familyName < t->FamilyName)  t=t->Left;
        else if(familyName > t->FamilyName) t=t->Right;
    }
    return NULL;
}

Student *BinarySearchTree::SearchByIdentityCode(int identityCode){
    Student *t=root;
    while (t) {
        if(identityCode==t->IdentityCode)   return t;
        if(identityCode < t->IdentityCode)  t=t->Left;
        else if(identityCode > t->IdentityCode) t=t->Right;
    }
    return NULL;
}

bool BinarySearchTree::BSTInsertFamilyName(QString name,QString familyname,int identityCode,
                                           int enteringYear,QString tendency,double average){
    Student *p=root ,*parent=NULL;
    while(p){
        parent=p;
        if(identityCode == p->IdentityCode)   return false;
        if(familyname <= p->FamilyName)    p=p->Left;
        else if(familyname > p->FamilyName) p=p->Right;
    }
    p=new Student;
    p->Left=p->Right=NULL;
    p->Name=name;
    p->FamilyName=familyname;
    p->IdentityCode=identityCode;
    p->EnteringYear=enteringYear;
    p->Tendency=tendency;
    p->Average=average;
    if(root==NULL) root=p;
    else if(familyname <= parent->FamilyName) parent->Left=p;
    else if(familyname > parent->FamilyName)  parent->Right=p;
    return true;
}

bool BinarySearchTree::BSTInsertAverage(QString name,QString familyname, int identityCode,
                                        int enteringYear, QString tendency, double average){
    Student *p=root ,*parent=NULL;
    while(p){
        parent=p;
        if(identityCode == p->IdentityCode)   return false;
        if(average <= p->Average)    p=p->Left;
        else if(average > p->Average) p=p->Right;
    }
    p=new Student;
    p->Left=p->Right=NULL;
    p->Name=name;
    p->FamilyName=familyname;
    p->IdentityCode=identityCode;
    p->EnteringYear=enteringYear;
    p->Tendency=tendency;
    p->Average=average;
    if(root==NULL) root=p;
    else if(average <= parent->Average) parent->Left=p;
    else if(average > parent->Average)  parent->Right=p;
    return true;
}

void BinarySearchTree::InorderFamilyName(){
    InorderFamilyName(root);
}

void BinarySearchTree::InorderFamilyName(Student *Root){

    if(Root==NULL) return;
    InorderFamilyName(Root->Left);
    SaveToFile(Root->FamilyName);
    InorderFamilyName(Root->Right);
}

void BinarySearchTree::InorderAverage(){
    InorderAverage(root);
}

void BinarySearchTree::InorderAverage(Student *Root){
    if(Root==NULL) return;
    InorderAverage(Root->Left);
    cout<<Root->Average<<"\n";
    InorderAverage(Root->Right);
}

void BinarySearchTree::SaveToFile(QString text){
    QFile file("test.txt");
    QTextStream stream(&file);
    if (file.open(QIODevice::ReadWrite))
        stream << text<<endl;
}
