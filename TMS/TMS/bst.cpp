#include "bst.h"

BST bst;

BST::BST():root(NULL) {}
BST::BST(BSTnode*r):root(r){}
BST::~BST(){root=NULL;}

bool BST::Insert(QString str,int value,BSTnode*&p)
{
    if(p==NULL)//到达叶结点
    {
        p=new BSTnode(str,value);
        return true;
    }
    else
    {
        if(str<p->ttl)//比指针当前指向结点词汇更小的词汇
        {
            Insert(str,value,p->left);//递归于左子树
        }
        else if(str>p->ttl)//比指针当前指向结点词汇更大的词汇
        {
            Insert(str,value,p->right);//递归于右子树
        }
        else
        {
            return false;//已存在该结点，无需插入
        }
    }
    return false;
}

bool BST::Build_BST(QList<Event>data,int len)
{
    if(data.size()==0)//数组为空
    {
        return false;
    }
    else
    {
        int mid=len/2;
        Insert(data[mid].title,data[mid].event_id,root);//将数组中间值首先插入树中

        QList<Event>data_left(mid);
        int i=-1;
        for(i=0;i<mid;++i)
        {
            data_left[i]=data[i];
        }//取中间值左方的所有元素组成一个新的字符串数组
        if(i!=0)
        {
            Build_BST(data_left,mid);//递归左子树
        }

        if(len-mid>1)
        {
            QList<Event>data_right(len-mid-1);
            int j=-1;
            for(j=0;j<len-mid-1;++j)
            {
                data_right[j]=data[mid+j+1];
            }//取中间值右方的所有元素组成一个新的字符串数组
            if(j!=0)
            {
                Build_BST(data_right,len-mid-1);//递归右子树
            }
        }
        return true;
    }
    return false;
}

BSTnode* BST::Search_BST(QString str,int &value)
{
    BSTnode*ftemp=new BSTnode;
    BSTnode*temp=new BSTnode;
    ftemp=nullptr;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->ttl==str)
        {
            value=temp->evid;
            return ftemp;
        }
        else if(str>temp->ttl)
        {
            ftemp=temp;
            temp=temp->right;
        }
        else if(str<temp->ttl)
        {
            ftemp=temp;
            temp=temp->left;
        }
    }
    value=-1;
    return ftemp;
}

void BST::deleteBST()
{
    root=nullptr;
}
