#ifndef BST_H
#define BST_H

#include "mainwindow.h"
using namespace std;

struct BSTnode
{
    //标题
    QString ttl;
    //事件号
    int evid;

    BSTnode*left;
    BSTnode*right;
    BSTnode():left(NULL),right(NULL){}
    BSTnode(QString str,int value,BSTnode*l=NULL,BSTnode*r=NULL):ttl(str),evid(value),left(l),right(r){}
    ~BSTnode(){left=NULL;right=NULL;}
};

class BST
{
public:
    BST();
    BST(BSTnode*r);
    ~BST();
    bool Insert(QString str,int value,BSTnode*&p);
    bool Build_BST(QList<Event>evtlist,int len);
    BSTnode* Search_BST(QString str,int &value);
    void deleteBST();

    BSTnode*root;
};

extern BST bst;

#endif // BST_H
