#include <iostream>
#define T 10;
using namespace std;


class TreeNode {
    private:
        int x;
    public:
        int val;
        TreeNode *left, *right,*testza;
    TreeNode(){ 
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int param){
        val = param;
        left = NULL;
        right = NULL;
    }
};

class TreeImpl{
    public:
        TreeNode * base;
    TreeImpl(){
        base=NULL;
    }
    bool isTreeIsEmpty(){
        if (base==NULL)
        {
            return true;
        }else{
            return false;
        }
    }

    void insertNode(TreeNode *newNode){
        if (base==NULL){
            base=newNode;
            cout<<"'Il valore \202 stato inserito alla base dell'albero'"<<endl;
        }else
        {
            TreeNode * pointertemp = base;
            while (pointertemp!=NULL)
            {
                if (newNode->val==pointertemp->val)
                {
                    cout << "'il valore esiste gia Inserire un'altro valore !'" << endl;
                    return;
                }else if ((newNode->val<pointertemp->val)&&(pointertemp->left==NULL)){
                    pointertemp->left = newNode;
                    cout<<"'Il valore \202 stato inserito a Sinistra'"<<endl;
                    break;
                }else if ((newNode->val<pointertemp->val)){
                    pointertemp=pointertemp->left;
                }else if ((newNode->val>pointertemp->val)&&(pointertemp->right==NULL)){
                    pointertemp->right = newNode;
                    cout<<"'Il valore \202 stato inserito a Destra'"<<endl;
                    break;    
                }else{
                    pointertemp=pointertemp->right;
                }
            }

        }

    }
    
    void stampaNode(TreeNode *node,int spazio){
        if(node==NULL){
            return;
        }
        spazio+=T;
        stampaNode(node->right,spazio);
        cout<<endl;
        int i=T;
       for (i; i < spazio; i++){
         cout <<" ";
       }
        cout <<node->val<<"\n";
        stampaNode(node->left,spazio);
    }

    void levelNode(TreeNode *node,int level){
        if (node==NULL) return;
        else if (level==0){
            cout<<"/"<<node->val<<endl;
        }else{
            levelNode(node->left,level-1);
            levelNode(node->right,level-1);
        }
    }

    TreeNode *TreeNodeSearch(int var){
        if (base==NULL)
        {
            return NULL;
        }else{
            TreeNode * pointertemp =base;
            while(pointertemp != NULL){
                if (var== pointertemp->val)
                {
                    return pointertemp;
                }else if (var<pointertemp->val){
                    pointertemp=pointertemp->left;
                }else{
                    pointertemp=pointertemp->right;
                }
            }
            return NULL;
        }

    }
};

int main() {
    int scelta,var;
    TreeImpl myTree;

    do{
        cout<<endl;
        cout<<"Fare una scelta per proseguire"<<endl;
        cout<<"1- Inserire un node"<<endl;
        cout<<"2- Ricercare un valore dentro il Tree"<<endl;
        cout<<"3- Stampare il nodi di un certo livello"<<endl;
        cout<<"0. Uscire"<<endl;

        cin>>scelta;

        TreeNode * newNode =new TreeNode();

        switch(scelta){
            case 0:
                break;
            case 1:
                cout<<"Inserire un valore :"<<endl;
                cin>>var;
                newNode->val=var;
                myTree.insertNode(newNode);
                cout<<endl;
                cout<<"''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
                myTree.stampaNode(myTree.base,5);
                cout<<endl;
                cout<<"''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
                if (myTree.isTreeIsEmpty()==true)
                {
                    cout<<"Il Tree e vuoto :( "<<endl;
                }
                break;
            case 2:
                cout<<"Inserire un valore a ricercare dentro il tree :"<<endl;
                cin >>var;
                newNode=myTree.TreeNodeSearch(var);
                if (newNode!=NULL)
                {
                    cout<<endl;
                    cout<<"'Valore Presente dentro il Tree :)'"<<endl;

                }else{
                    cout<<"'Valore non presente :('"<<endl;
                }
                break;
            case 3:
                cout<<"Inserire un livello :"<<endl;
                cin >>var;
                cout<<endl;
                myTree.levelNode(myTree.base,var);
                break;    
        }
    }while(scelta!=0);
    cout<<"Fine Processo ....";
    return 0;
}