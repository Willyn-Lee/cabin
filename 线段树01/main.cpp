#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 500

int arr[]={1,3,5,7,9,11};
    int size=6;
    int tree[MAX_LEN]={0};
using namespace std;
int flag;
void build_tree(int arr[],int tree[],int node,int start,int end)
{
    int left_node=2*node+1,right_node=2*node+2;
    int mid=(start+end)/2;
    if(start==end)
    {
        tree[node]=arr[start];
    }
    else{
        build_tree(arr,tree,left_node,start,mid);
        build_tree(arr,tree,right_node,mid+1,end);
        tree[node]=tree[left_node]+tree[right_node];
    }
}

void sett(int arr[],int tree[],int node,int start,int end,int idx,int val)
{
    if(start==end)
    {
        arr[idx]=val;
        tree[node]=val;
        return;//����
    }
    int mid=(start+end)/2;
    int left_node=2*node+1;
    int right_node=2*node+2;
    if(/*idx>=start&&*/idx<=mid){
        sett(arr,tree,left_node,start,mid,idx,val);
    }
    else{
        sett(arr,tree,right_node,mid+1,end,idx,val);
    }
    tree[node]=tree[left_node]+tree[right_node];

}

int main()
{

    int arr[]={1,3,5,7,9,11};
    int size=6;
    int tree[MAX_LEN]={0};

    build_tree(arr,tree,0,0,size-1);
    for(int i=0;i<15;i++)
    {
        cout<<"tree["<<i<<"]=="<<tree[i]<<' ';
    }
    sett(arr,tree,0,0,size-1,2,9);
    for(int j=0;j<5;j++)
    {
        cout<<'\n';
    }
    for(int i=0;i<15;i++)
    {
        //cout<<arr[i];
        cout<<"tree["<<i<<"]=="<<tree[i]<<' ';
    }
    return 0;
}
