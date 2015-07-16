#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class segtree{

    public :
    //here both array and tree should be well defined and allocated suitabily o avoid any segmentation fault.
    //we start from index 1.
    //at the time of calling; ind=1,start=1 and endd=size of the arr.

    void build(int *arr,int *tree,int ind,int start,int endd){
        if(start==endd){
            tree[ind]=arr[start];
        }
        else{
            build(arr,tree, ind*2,start,(start+endd)/2);
            build( arr, tree,ind*2+1,(start+endd)/2+1, endd);
            tree[ind]=tree[ind*2]+tree[ind*2+1];//here we are calculating sum for any segment;for min or max just change this line of code .
        }

    }
    //method to add certain value to given range in query in nlog(n) time.
    //here we add v
    void addval(int *tree,int ind,int start,int endd,int qstart,int qend,int v){
        if (start>endd||start>qend || endd<qstart){
        return;
        }
        else if (start==endd){
            tree[ind]+=v;
        }
        else{
            addval(tree,ind*2,start,(start+endd)/2,qstart,qend,v);
            addval(tree,ind*2+1,(start+endd)/2+1,endd,qstart,qend,v);
            tree[ind]=tree[ind*2]+tree[ind*2+1];
        }
    }


};

int main()
{
    int *arr,*tree;
    arr= new int[6];
    tree = new int [20];
    int i;
    for (i =1;i<6;i++){
        arr[i]=i;
    }
    segtree b1;
    b1.build(arr,tree,1,1,5);
    for(i=1;i<10;i++){
    cout<<tree[i]<<endl;
    }
    b1.addval(tree,1,1,5,2,4,9);
    cout<<"update complete"<<endl;
    for(i=1;i<10;i++){
    cout<<tree[i]<<endl;
    }
    return 0;
}

