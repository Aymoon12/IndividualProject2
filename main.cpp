#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>

using namespace std;

class itemNode
{
public:
    char name[50];
    int count;
    itemNode *left, *right;


    itemNode()
    {
        name[0] ='\0';
        count = 0;
        left = nullptr;
        right = nullptr;
    }
    itemNode(char itemName[], int population)
    {
        strcpy(name,itemName);
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
        treeName[0] ='\0';
        theTree = nullptr;
        left = nullptr;
        right = nullptr;
    }
    treeNameNode(char name[])
    {
        strcpy(treeName,name);
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
    void search(const char type[],const string item){

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
    treeNameNode* findTreeName(const char type[], treeNameNode* roo) {
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
    void item_before(const char type[], const string item) {
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

void createTreeName(treeName* Tree, char treetype[]){
    treeNameNode* mainTree = Tree->root;
    if(mainTree == nullptr){
        Tree->root = new treeNameNode(treetype);
        printf("Added %s to the tree\n",treetype);
        return;
    }
    while (mainTree != nullptr) {
        // Check if the current node's tree name is greater than the given tree type
        bool rootBigger = strcmp(mainTree->treeName, treetype) > 0;

        // If the tree name should go to the left subtree
        if (rootBigger) {
            // If left child is null, insert the node here
            if (mainTree->left == nullptr) {
                mainTree->left = new treeNameNode(treetype);
                printf("Added %s to the tree\n", treetype);
                return;
            }
            // Move to the left subtree
            mainTree = mainTree->left;
        } else { // If the tree name should go to the right subtree
            // If right child is null, insert the node here
            if (mainTree->right == nullptr) {
                mainTree->right = new treeNameNode(treetype);
                printf("Added %s to the tree\n", treetype);
                return;
            }
            // Move to the right subtree
            mainTree = mainTree->right;
        }
    }

}




void inOrder(treeNameNode* root){
    if(root == nullptr){
        return;
    }
    inOrder(root->left);
    printf("%s tree \n", root->treeName);
    inOrder(root->right);
}
void treeinOrder(treeName* root){
    inOrder(root->root);
}

void addItem(treeName* Tree, char type[],char item[],int count){
    treeNameNode* treeType = Tree->findTreeName(type,Tree->root);
    itemNode* itemTree = treeType->theTree;
    if(itemTree == nullptr){
        treeType->theTree = new itemNode(item,count);
        printf("Root added successfully\n");
        return;
    }
    while(itemTree){

        bool isBigger = strcmp(itemTree->name,item) > 0;
        if(isBigger){

            if(itemTree->left == nullptr){
                itemTree->left = new itemNode(item,count);
                printf("Added %s to the item tree",item);
                return;
            }
            itemTree = itemTree->left;
        }
        else{
            if(itemTree->right == nullptr){
                itemTree->right = new itemNode(item,count);
                printf("Added %s to the item tree", item);
                return;
            }
            itemTree = itemTree->right;
        }

    }

}


int main() {

    ifstream fin;
    string line;
    int treeNames;
    int totalItems;
    int queries;
    char word1[50];
    char word2[50];
    int count;
    int readingLine = 1;
    auto* Tree = new treeName();
    int n=0;
    int i=0;
    int q=0;
    FILE* infile = fopen("in.txt", "r");
    fscanf(infile, "%d %d %d", &treeNames, &totalItems, &queries);
    cout<<treeNames<<" "<<totalItems<<" "<<queries<<endl;
    while(n < treeNames){
        fscanf(infile,"%s",word1);
        createTreeName(Tree,word1);
        n++;
    }
    while(i<totalItems){
        fscanf(infile, "%s %s %d",word1,word2,&count);
        printf("%d",count);
        addItem(Tree,word1,word2,count);
        i++;
    }

   /* while(!fin.eof()) {
        getline(fin, line);
        size_t spacepos1 = line.find(' ');
        string line2 = line.substr(spacepos1 + 1, line.length());
        size_t spacepos2 = line2.find(' ');
        string line3 = line2.substr(spacepos2 + 1, line.length());
        string firstWord = line.substr(0, spacepos1);
        string secondWord = line2.substr(0, spacepos2);
        string thirdWord = line2.substr(spacepos2 + 1, line2.length());
        if (readingLine == 1) {
            treeNames = firstWord;
            totalItems = secondWord;
            queries = thirdWord;
            readingLine++;
        }
        else {
            cout << firstWord << " " << secondWord << endl;
            createTreeName(Tree, firstWord);
        }
    }

    */

    //cout<<Tree->root->right->treeName;
    delete Tree;
    fin.close();


    return 0;
}
