#include <iostream>
#include <cstring>
#include <fstream>

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
        left = nullptr;
        right = nullptr;
    }
    itemNode(char itemName[], int population)
    {
        strcpy(name, itemName);
        count = population;
        left = nullptr;
        right = nullptr;
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
        theTree = nullptr;
        left = nullptr;
        right = nullptr;
    }
    treeNameNode(char name[])
    {
        strcpy(treeName, name);
        theTree = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class treeName{
public:
    treeNameNode* root;

    treeName() : root(nullptr) {}

    //always checks if string1 is greater than string two
    //i.e. if it returns false if string2 is bigger, but if it returns true then string1 is bigger
    bool compareStrings(const string string1, const string string2){

        char sone;
        char stwo;
        int i = 0;

        bool answer;
        if(string1.length() < string2.length())
            answer = false;
        else
            answer = true;
        do{
            sone = string1[i];
            stwo = string2[i];
            i++;
            if(sone > stwo){
                return true;
            }
            else if(sone < stwo){
                return false;
            }
            else
                continue;


        } while(string1[i++] != '\0' && string2[i++] != '\0');

        return answer;

    }
    //searches if an item exists
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
    //searches for a NameTree
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
    //Searches for an item using the root of the nameTree
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
    //Inorder traversal of the item trees
    void inOrder(itemNode* root, string* arr ,int index){
        if(root == nullptr){
            return;
        }
        inOrder(root->left,arr,index);
        arr[index] = root->name;
        index++;
        inOrder(root->right,arr,index);
    }

    //converts the item trees into an array with all the names
    string* itemTreeToArray(itemNode* root){
        string* itemArray = new string[11];
        inOrder(root,itemArray,0);
        return itemArray;

    }
    //prints all the items that come alphabetically before the item inserted
    void item_before(const string type, const string item) {
        treeNameNode *treeNode = findTreeName(type, root);
        if (treeNode != nullptr) {
            itemNode *itemnode = findItem(item, treeNode->theTree);
            if (itemnode != nullptr) {
                string* itemArray = itemTreeToArray(itemnode);
                for(int i =0; i<itemArray->length();i++){
                    if(itemnode->name > itemArray[i]){
                        cout<<itemArray[i]<< " ";
                    }
                }
            }
            else
                return;
            } else
                return;


        }

    void inOrderCounting(itemNode* root,int index,int* count){
        if(root == nullptr){
            return;
        }
        inOrderCounting(root->left,index,count);
        count[index] += root->count;
        index++;
        inOrderCounting(root->right,index,count);
    }

    void countArray(itemNode* root){
        int* count = new int[11];
        inOrderCounting(root,0,count);
        int index = 0;
        int total = 0;
        while(true){
            cout<<count[index] <<" ";
            total += count[index];
            index++;
            if(index < 11 || count[index] < 1000){
                cout<<"+ ";
            }
            else {
                cout << "= ";
                break;
            }
        }
        cout<<total<<endl;


    }


};

int main() {

    ifstream fin;
    string line;
    string treeNames;
    string totalItems;
    string queries;
    int readingLine = 1;

    fin.open("in.txt");
    while(fin){
        getline(fin,line);
        if(readingLine == 1){
            size_t spacepos1 = line.find(' ');
            treeNames = line.substr(0,spacepos1);
            string line2 = line.substr(spacepos1,line.length());
            totalItems = line.substr(spacepos1,line)
        }
    }
    fin.close();


    return 0;
}
