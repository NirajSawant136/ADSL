#include<iostream>
using namespace std;

struct Node{
	string word, meaning;
	Node *left, *right;
};

class dict{
	public:	Node *root;
	
	public:	dict(){
			root = NULL;
		}
		void create(){
			
			string word;
			char ch = 'Y';
			while(ch == 'Y'){
			
				cout<<"\nENTER WORD-> ";
				cin>>word;
				append(word);
				cout<<"WANT TO ADD MORE?(Y/N)";
				cin>>ch;

			}

		}
		void append(string word){
		
			Node* tr = root;
			Node* cn = new Node;
			cn->left = NULL;
			cn->right = NULL;
			cn->word = word;
			 
			if(root == NULL){

				root = cn;

			}
			else{

				while(true){

					if(tr->word < word){

						if(tr->right == NULL){

							tr->right = cn;
							break;

						}

						tr= tr->right;
					}
					else if(tr->word > word){

						if(tr->left == NULL){

							tr->left = cn;
							break;
						}

						tr= tr->left;
					}
				}
			}
		}
		void display(){
			
			Node *tr = root;

			if(tr != NULL){

				Inorder(tr->left);
				cout<<tr->word<<" ";
				Inorder(tr->right);

			}
		}
		void Inorder(Node *tr){
			
			if(tr != NULL){

				Inorder(tr->left);
				cout<<tr->word<<" ";
				Inorder(tr->right);

			}
		}
		Node* search(string word){
			
			Node *tr = root;
			int fnd = 0;
			
			while(tr != NULL){
				
				if(tr->word == word){

					return(tr);
				}
				else if(tr->word > word){

					tr = tr->left;
				}
				else{

					tr = tr->right;
				}
			}
			return(NULL);
		}
		void del(string word){
			
			Node *tr = root;
			Node *pr = root;
			
			while(tr != NULL && tr->word != word){
				
				
				if(tr->word > word)
					tr = tr->left;
				else
					tr = tr->right;

				pr = tr;
			}

			cout<<tr->left;

			if(tr->left == NULL && tr->right == NULL){
				
				if(tr->word < pr->word)
					pr->left = NULL;
				else
					pr->right = NULL;
				delete (tr);
			}
			else if(tr->left == NULL && tr->right != NULL){
				
				if(tr->word < pr->word)
					pr->left = tr->right;
				else
					pr->right = tr->right;
				delete (tr);
			}
			else if(tr->left != NULL && tr->right == NULL){
				
				if(tr->word < pr->word)
					pr->left = tr->left;
				else
					pr->right = tr->left;
				delete (tr);
			}
			else{

				Node *tmp = tr;
				tr = tr->left;
				
				while(tr->right != NULL)
					tr = tr->right;

				string k = tmp->word;
				del(k);
				tr->word = k;
			}
		}
		void update(string word){
			
			Node *tr = search(word);
			
			if(tr){
				//tr -> meaning = meaning;
				cout<<"\n"<<word<<" was successfully updated in the Dictionary\n";
			}
			else
				cout<<"\n"<<word<<" not found in the Dictionary\n";
		}	
};
int main(){

	dict d1;
	d1.create();
	d1.display();
	string wrd = "a",wrd1 = "l";
	if(d1.search(wrd)){
		cout<<"\n"<<wrd<<" was found in the Dictionary\n";
	}
	else
		cout<<"\n"<<wrd<<" not found in the Dictionary\n";
	d1.update(wrd);
	d1.del(wrd);
	if(d1.search(wrd1)){
		cout<<"\n"<<wrd1<<" was found in the Dictionary\n";
	}
	else
		cout<<"\n"<<wrd1<<" not found in the Dictionary\n";
	d1.display();
	return 0;
	
}
