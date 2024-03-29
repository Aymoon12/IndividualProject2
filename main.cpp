#include <iostream>
#include <fstream>
#include <string.h>


/* HAVE TO ADD in.txt FILE TO CMAKE EACH TIME REPOSITORY IS CLONED
 * ALSO KEEP IN MIND THAT THE PROGRAM WRITES TO THE OUTPUT FILE IN CMAKE IF USING CLION */
using namespace std;


ofstream myFile("out.txt");

class itemNode
{
public:
    char name[50]{};
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
    char treeName[50]{};
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

class treeName {
public:
    treeNameNode *root;

    treeName() : root(nullptr) {}
};



    //My replacement for the searchNameNode function
    treeNameNode* findTreeName(const char type[], treeNameNode* roo) {
        while(roo){

            if(strcmp(roo->treeName,type) == 0)
                return roo;

            bool rootBigger = strcmp(roo->treeName, type) > 0;
            if(rootBigger){
                roo = roo->left;
            }
            else
                roo=roo->right;
        }
        return nullptr;
    }


    //Searches for an item using the root of the nameTree
    itemNode* findItem(const char item[], itemNode* next){
        while(next){

            if(strcmp(next->name,item) == 0)
                return next;

            bool rootBigger = strcmp(next->name, item) > 0;
            if(rootBigger){
                next = next->left;
            }
            else
                next=next->right;
        }
        return nullptr;
    }

    //searches if an item exists
    void search(char type[],char item[],treeName* root){

        treeNameNode* tree = findTreeName(type,root->root);
        if(tree == nullptr){
            cout<<""<< type<< " does not exist\n";
            myFile<<""<< type<< " does not exist\n";
            return;
        }
        itemNode* itemN = findItem(item, tree->theTree);
        if(itemN == nullptr){
            cout<<""<<item<<" not found in "<<type<< "\n";
            myFile<<""<<item<<" not found in "<<type<< "\n";
            return;
        }
        cout<<itemN->count<< " " <<itemN->name<< " found in " << type<<endl;
        myFile<<itemN->count<< " " <<itemN->name<< " found in " << type<<endl;
    }




// Function to count the number of items that come before the input item alphabetically
int countItemsBefore(itemNode* root, const char item[]) {
    if (root == nullptr) {
        return 0;
    }


    if (strcmp(root->name, item) >= 0) {
        return countItemsBefore(root->left, item);
    }


    return 1 + countItemsBefore(root->left, item) + countItemsBefore(root->right, item);
}

// Function to print the number of items that come before the input item alphabetically
void item_before(const char type[], const char item[], treeName* root) {
    treeNameNode* treeNode = findTreeName(type, root->root);
    if (treeNode != nullptr && treeNode->theTree != nullptr) {
        int count = countItemsBefore(treeNode->theTree, item);
        cout << "Items before " << item  << ": " << count << endl;
        myFile << "Items before " << item  << ": " << count << endl;
    } else {
        cout << "Tree " << type << " does not exist or is empty" << endl;
        myFile << "Tree " << type << " does not exist or is empty" << endl;
    }
}



// Inorder traversal of the item trees to count items
int inOrderCounting(itemNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = inOrderCounting(root->left);
    int rightCount = inOrderCounting(root->right);


    return leftCount + rightCount + root->count;
}

// Function to print the counts of all items and return the total count
int printItemCountsAndGetTotal(itemNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int totalCount = printItemCountsAndGetTotal(root->left) + root->count;
    return totalCount + printItemCountsAndGetTotal(root->right);
}

// count command implementation
int count(const char type[], treeName* root) {

    treeNameNode* treeNode = findTreeName(type, root->root);
    if (treeNode != nullptr) {
        int totalCount = printItemCountsAndGetTotal(treeNode->theTree);
        cout << type <<" count "<< totalCount << endl;
        myFile << type <<" count "<< totalCount << endl;
        return totalCount;
    } else {
        cout << type << " does not exist" << endl;
        myFile << type << " does not exist" << endl;
        return 0;
    }
}



//My replacement from the buildNameTree function
void createTreeName(treeName* Tree, char treetype[]){
    treeNameNode* mainTree = Tree->root;
    if(mainTree == nullptr){
        Tree->root = new treeNameNode(treetype);
      //  printf("Added %s to the tree\n",treetype);
        return;
    }
    while (mainTree != nullptr) {

        bool rootBigger = strcmp(mainTree->treeName, treetype) > 0;


        if (rootBigger) {

            if (mainTree->left == nullptr) {
                mainTree->left = new treeNameNode(treetype);
            //    printf("Added %s to the tree\n", treetype);
                return;
            }

            mainTree = mainTree->left;
        } else {

            if (mainTree->right == nullptr) {
                mainTree->right = new treeNameNode(treetype);
              //  printf("Added %s to the tree\n", treetype);
                return;
            }

            mainTree = mainTree->right;
        }
    }

}


void addItem(treeNameNode* Tree,char item[],int count){

   itemNode* itemTree = Tree->theTree;
    if(itemTree == nullptr){
        Tree->theTree = new itemNode(item,count);
     //   printf("Added %s successfully\n",item);
        return;
    }
    while(itemTree){

        bool isBigger = strcmp(itemTree->name,item) > 0;
        if(isBigger){

            if(itemTree->left == nullptr){
                itemTree->left = new itemNode(item,count);
              //  printf("Added %s successfully\n",item);
                return;
            }
            itemTree = itemTree->left;
        }
        else{
            if(itemTree->right == nullptr){
                itemTree->right = new itemNode(item,count);
               // printf("Added %s successfully\n",item);
                return;
            }
            itemTree = itemTree->right;
        }

    }

}


// Helper function to print the data of the items in an item tree
void printItems(itemNode* root) {
    if (root == nullptr) {
        return;
    }

    printItems(root->left);
    cout <<root->name << " ";
    myFile << root->name<< " ";
    printItems(root->right);
}

// Function to recursively traverse the name tree and print data of each node along with the data of its corresponding item tree
void traverse_in_traverse(treeNameNode *root) {
    if (root == nullptr) {
        return;
    }

    traverse_in_traverse(root->left);
    cout << "***"<<root->treeName << "***"<<endl;
    myFile << "***"<<root->treeName << "***"<<endl;
    printItems(root->theTree);
    cout<<endl;
    myFile<<endl;
    traverse_in_traverse(root->right);
}

// Function to calculate the height of a tree
int calculateHeight(itemNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Function to check if a tree is height-balanced
bool height_balance(const char type[], treeName* root) {
    treeNameNode* treeNode = findTreeName(type, root->root);
    if (treeNode != nullptr && treeNode->theTree != nullptr) {

        int leftHeight = calculateHeight(treeNode->theTree->left);
        int rightHeight = calculateHeight(treeNode->theTree->right);


        int heightDifference = abs(leftHeight - rightHeight);

        // Print the heights and the balance status
        cout <<type <<": left height " << leftHeight << ", right height " << rightHeight << ", difference " << heightDifference;
        myFile <<type <<": left height " << leftHeight << ", right height " << rightHeight << ", difference " << heightDifference;
        if (heightDifference > 1) {
            cout << ", not balanced" << endl;
            myFile << ", not balanced" << endl;
            return false;
        } else {
            cout << ", balanced" << endl;
            myFile << ", balanced" << endl;
            return true;
        }
    } else {
        cout << "Tree not found" << endl;
        myFile << "Tree not found" << endl;
        return false;
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
    char word3[50];
    int pop;
    auto *Tree = new treeName();
    int n = 0;
    int i = 0;
    int q = 0;
    FILE *infile = fopen("in.txt", "r");
    fscanf(infile, "%d %d %d", &treeNames, &totalItems, &queries);
    //cout << treeNames << " " << totalItems << " " << queries << endl;
    while (n < treeNames) {
        fscanf(infile, "%s", word1);
        createTreeName(Tree, word1);
        n++;
    }


    auto *fishTree = findTreeName("fish", Tree->root);
    auto *animalTree = findTreeName("animal", Tree->root);
    auto *fruitTree = findTreeName("fruit", Tree->root);
    auto *birdTree = findTreeName("bird", Tree->root);

    while(i<totalItems){
         fscanf(infile, "%s %s %d",word1,word2,&pop);
         if(strcmp(fishTree->treeName,word1) == 0)
             addItem(fishTree,word2,pop);

         else if(strcmp(animalTree->treeName,word1) == 0)
             addItem(animalTree,word2,pop);

         else if(strcmp(fruitTree->treeName,word1) == 0)
            addItem(fruitTree,word2,pop);

         else if(strcmp(birdTree->treeName,word1) == 0)
            addItem(birdTree,word2,pop);
      i++;

}
    //search("fruit", "adawd",Tree);
   // item_before("animal","deer",Tree); cout<<"\n";
   // count("animal",Tree);
   traverse_in_traverse(Tree->root);

   while(q<queries){
       if(q == 7 || q == 8 || q==9 || q == 11 || q == 12 || q== 15){
           fscanf(infile,"%s %s",word1,word2);
       }
       else
           fscanf(infile,"%s %s %s",word1,word2,word3);
       if(strcmp(word1,"search") == 0){
           search(word2,word3,Tree);

       }
       else if(strcmp(word1,"item_before") == 0){
           item_before(word2, word3,Tree);


       }
       else if(strcmp(word1,"height_balance") == 0){
           height_balance(word2,Tree);


       }
       else if(strcmp(word1,"count") == 0){
           count(word2,Tree);

       }

       q++;
   }
    delete Tree;
    fin.close();
    myFile.close();


    return 0;
}
