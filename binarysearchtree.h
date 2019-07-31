#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <stdio.h>
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
using namespace std;

struct Student{
    Student *Left;
    QString Name;
    QString FamilyName;
    int IdentityCode;
    int EnteringYear;
    QString Tendency;
    double Average;
    Student *Right;
};

class BinarySearchTree
{
public:
    Student *root;
    BinarySearchTree();
    Student *SearchByFamilyName(QString familyName );
    Student *SearchByIdentityCode(int average );
    bool BSTInsertFamilyName(QString name, QString familyname, int identityCode,
                             int enteringYear, QString tendency, double average);
    bool BSTInsertAverage(QString name, QString familyname, int identityCode,
                          int enteringYear, QString tendency, double average);
    void InorderFamilyName(); //driver
    void InorderAverage();  //driver
    void SaveToFile(QString text);
private:
    void InorderFamilyName(Student *Root);
    void InorderAverage(Student *Root);
    QMessageBox messageBox;
};

#endif // BINARYSEARCHTREE_H
