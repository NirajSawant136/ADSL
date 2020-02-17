#include<iostream>
#include<fstream>
using namespace std;

class Student{

	private:char name[20]; int rollNo;

	public:
			void accept(){

				cout<<"\nEnter name -> ";
				cin>>name;
				cout<<"\nEnter Roll No. -> ";
				cin>>rollNo;
			}

			void showData(){

				cout<<"\nName -> "<<name;
				cout<<"\nRoll No. -> "<<rollNo;
			}

			void update(){

				cout<<"\nEnter new Name -> ";
				cin>>name;
				cout<<"\nEnter new Roll No. -> ";
				cin>>rollNo;
			}

			void clear(){

			}

			char* getName(){

				return(name);
			}

			int getRollNo(){

				return(rollNo);
			}
	
};
int main(int argc, char const *argv[])
{
	int choice, found = 0;
	char name[20];

	Student s, s1;

	fstream f("Student.txt");

	cout<<"1. Add details of a student"<<endl;
	cout<<"2. Search details of a student"<<endl;
	cout<<"3. Display details of a student"<<endl;
	cout<<"4. Update details of a student"<<endl;
	cout<<"5. Delete details of a student"<<endl;
	cout<<"\nEnter choice";
	cin>>choice;

	switch(choice){

		case 1:	{
					f.open("Student.txt" , ios::in | ios::out | ios::ate);
					s.accept();
					f.write((char*)&s , sizeof(s));
					break;
				}

		case 2:	{
					f.open("Student.txt" , ios::in | ios::out);
					cout<<"\nEnter name -> ";
					cin>>name;
					found = 0;
					f.seekg(0, ios::beg);
					while(f.read((char *) &s1, sizeof(s1))){
	
	                    if(s1.getName() == name){
	
	                        found = 1;
	                        cout<<"\nRecord of "<<name<<" was found!\n";
	                    }
	                }
	                if(found == 0)
	                    cout<<"\nRecord of "<<name<<" was not found\n";
					break;
				}

		case 3: {
					f.open("Student.txt" , ios::in | ios::out);
					cout<<"\nEnter name -> ";
					cin>>name;
					found = 0;
					f.seekg(0, ios::beg);
					while(f.read((char *) &s1, sizeof(s1))){
	
	                    if(s1.getName() == name){
	
	                        found = 1;
	                        s1.showData();
	                    }
	                }
	                if(found==0)
	                    cout<<"\nRecord of "<<name<<" was not found\n";
					break;
				}

		case 4: f.open("Student.txt" , ios::in | ios::out);
				cout<<"\nEnter name -> ";
				cin>>name;
				found = 0;
				f.seekg(0, ios::beg);
				while(f.read((char *) &s1, sizeof(s1))){

                    if(s1.getName() == name){

                        found = 1;
                        s1.update();
                        f.write((char*)&s1, sizeof(s1));
                    }
                }
                if(found==0)
                    cout<<"\nRecord of "<<name<<" was not found\n";
				break;

		case 5: f.open("Student.txt");
			
				break;

		default:cout<<"\nEnter valid choice!";
	}
	f.close();
	return 0;
}