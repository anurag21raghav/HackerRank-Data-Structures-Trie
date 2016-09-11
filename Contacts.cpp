# HackerRank-Data-Structures-Trie

#include<bits/stdc++.h>
using namespace std;
struct node{
    int mark; //Number of words with prefix
    node* children[26]; //Connects to every other alphabets
};
node* get(){  //Add the node
    node* n = new node;
    n->mark = 0;
    for(int i=0;i<26;i++){
        n->children[i] = NULL;
    }
    return n;
}
void insert(node* root, string s){
    for(int i=0;i<s.length();i++){
        int now = s[i]-'a';
        if(root->children[now]==NULL){  
            root->children[now] = get();
        }
        root = root->children[now];
        root->mark+=1;  //Increment the count 
    }
}
int n;
string type, s;
void solve(){
    sd(n);  //Number of Operations
    node* root = get(); //Initialize the first node
    loop(i, n){
        cin>>type>>s;
        node* temp = root;
        if(type=="add"){
            insert(temp, s);  //Insert the given word
        }
        else{
            int flag = 0; //Indicates if there is any word with the given prefix
            for(int j=0;j<s.length();j++){
                int now = s[j]-'a';
                if(temp->children[now]==NULL){
                    flag = 1;
                    break;  //No word with the given prefix
                }
                temp = temp->children[now];
            }
            if(flag)cout<<"0\n";
            else cout<<temp->mark<<"\n";  //Number of words with the given prefix
        }
    }
}
int main(){
    solve();
    return 0;
}
