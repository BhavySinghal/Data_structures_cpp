#include<bits/stdc++.h>
using namespace std;
template<typename T>
class node
{
public:
T data;
vector<node<T>*>children;
node(T data)
{
this->data=data;
}
};
#define loop(i,n) for(int i=0;i<n;i++)
#define pb push_back
int sumnodes(node<int>* head)
{
int ans=head->data;
loop(i,head->children.size())
ans+=sumnodes(head->children[i]);
return ans;
}
int maxdata(node<int>* head)
{
int ans=head->data;
loop(i,head->children.size())
{
int smallans=maxdata(head->children[i]);
if(smallans>ans)
{ans=smallans;}
}
return ans;
}
int treeheight(node<int>* head)
{
int ans=0;
loop(i,head->children.size())
{
int small=treeheight(head->children[i]);
if(small>ans)
{ans=small;}
}
return ans+1;
}
int nodenumber(node<int>* head)
{
int ans=1;
loop(i,head->children.size()) ans+=nodenumber(head->children[i]);
return ans;
}
node<int>* tree_input()
{
int rdata;
cout<<"Enter root data";
cin>>rdata;
node<int>* root=new node<int>(rdata);
queue<node<int>*> pending;
pending.push(root);
while(pending.size())
{
node<int>* front=pending.front();
pending.pop();
cout<<"enter number of children of "<<front->data<<" ";
int nchild;
cin>>nchild;
loop(i,nchild)
{
cout<<"enter data of "<<i+1<<" child of "<<front->data<<" ";
int dchild;
cin>>dchild;
node<int>* child=new node<int>(dchild);
front->children.pb(child);
pending.push(child);
}
}
return root;
}
void print_tree_levelwise(node<int>* root)
{
queue<node<int>*> pending;
pending.push(root);
while(pending.size())
{
node<int>* front=pending.front();
pending.pop();
cout<<front->data<<":";
loop(i,front->children.size()) 
{
cout<<front->children[i]->data<<",";
pending.push(front->children[i]);
}
cout<<endl;
}
}
void print_tree(node<int>* root)
{
cout<<root->data<<": ";
loop(i,root->children.size()) cout<<root->children[i]->data<<",";
cout<<endl;
loop(i,root->children.size()) print_tree(root->children[i]);
}
int main()
{
node<int>* root=tree_input();
print_tree(root);
cout<<endl<<"number of nodes: "<<nodenumber(root);
cout<<endl;
print_tree_levelwise(root);
cout<<endl<<"height: "<<treeheight(root);
cout<<endl<<"maxdata: "<<maxdata(root);
cout<<endl<<"sumtree: "<<sumnodes(root);
}
