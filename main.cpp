#include <iostream>

using namespace std;

class itemNode
{
public:
    char name[50];
    int count;
    itemNode *left, *right;


    itemNode()
    {
        name[0]='\0';
        count = 0;
        left = NULL;
        right = NULL;
    }
    itemNode(char itemName[], int population)
    {
        strcpy(name, itemName);
        count = population;
        left = NULL;
        right = NULL;
    }
};

//For Tree Names
class treeNameNode
{
public:
    char treeName[50];
    treeNameNode *left, *right;
    itemNode *theTree;


    treeNameNode()
    {
        treeName[0]='\0';
        theTree = NULL;
        left = NULL;
        right = NULL;
    }
    treeNameNode(char name[])
    {
        strcpy(treeName, name);
        theTree = NULL;
        left = NULL;
        right = NULL;
    }
};

class treeName{
public:
    treeNameNode* root;

    treeName() : root(nullptr) {}

    //always checks if string1 is greater than string two
    //i.e if it returns false then string 2 is bigger, but if it returns true then string1 is bigger
    bool compareStrings(const string string1, const string string2){

        char sone;
        char stwo;
        int i = 0;
        bool answer = true;
        do{
            sone = string1[i];
            stwo = string2[i];
            i++;
            if(sone > stwo){
                return answer;
            }
            if(sone < stwo){
                return false;
            }

        } while(sone != '\0' && stwo != '0')
    }
    void search(const string type,const string item){

        treeNameNode* tree = findTreeName(type,root);
        if(tree == nullptr){
            cout<<"\nTree does not exist\n";
            return;
        }
        itemNode* itemN = findItem(item, tree->theTree);
        if(itemN == nullptr){
            cout<<"\nItem does not exist\n";
            return;
        }
        cout<<itemN->name<<": count: "<<itemN->count<<endl;
    }

    treeNameNode* findTreeName(const string type, treeNameNode* roo) {
        if(roo->treeName == type){
            return roo;
        }

        treeNameNode* leftTree = findTreeName(type,roo->left);
        if(leftTree != nullptr){
            return leftTree;
        }
        treeNameNode* rightTree = findTreeName(type,roo->right);
        if(rightTree != nullptr){
            return rightTree;
        }
        return nullptr;
    }

    itemNode* findItem(const string item, itemNode* next){
        if(next->name == item){
            return next;
        }

        itemNode* leftTree = findItem(item,next->left);
        if(leftTree != nullptr){
            return leftTree;
        }

        itemNode* rightTree = findItem(item,next->right);
        if(rightTree != nullptr){
            return rightTree;
        }
        return nullptr;
    }
    void item_before(const string type, const string item){
        treeNameNode* treeNode = findTreeName(type,root);
        if(treeNode != nullptr){
            itemNode* itemnode = findItem(item,treeNode->theTree);
            if(itemnode != nullptr){
                itemNode* itemTree = treeNode->theTree;
                while(itemTree)
                if(itemTree->name[0] > itemnode->name[0]){
                    itemTree = itemTree->left;
                }
                if(itemTree->name[0] < itemnode->name[0]){
                    itemTree = itemTree->right;
                }


            }
            else
                return;
        }
        else
            return;




    }



};

int main() {


    return 0;
}
