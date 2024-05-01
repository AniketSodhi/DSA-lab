#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
class Student
{
    public:
    int roll;
    char name[30];
    char division;
    char address[50];
   
    void setdata()
	{
	   cout<<"\n**\n";
       cout<<"\nEnter the following : "<<endl;
       cout<<"\nEnter roll no : ";
       cin>>roll;
       cout<<"Enter the Name : ";
       cin>>name;
       cout<<"Enter the division : ";
       cin>>division;
       cout<<"Enter the address : ";
       cin>>address;
	   cout<<"\n**\n";
    }
    void showdata()
	{
        cout<<"Name : "<<name<<endl;
        cout<<"Roll No. : "<<roll<<endl;
        cout<<"Division : "<<division<<endl;
        cout<<"Address is : "<<address<<endl;
    }
};
    void write_record()
	{
        ofstream outFile;
        outFile.open("student.dat",ios::binary| ios::app);  
        Student obj;
        obj.setdata();
        outFile.write((char*)&obj,sizeof(obj));
        outFile.close();
    }
    void display()
	{
        ifstream inFile;
        inFile.open("student.dat",ios::binary);
        Student obj;
        while (inFile.read((char*)&obj,sizeof(obj)))
		{
            obj.showdata();
        }
        inFile.close();
    }
    int search(int n)
	{
        ifstream inFile;
        bool flag=false;
        inFile.open("student.dat",ios::binary);
        Student obj;
        while (inFile.read((char*)&obj,sizeof(obj)))
		{
            if(obj.roll==n)
			{
                flag=true;
                obj.showdata();
                return 1;
            }

        }   
        if(flag==false)
		{
            cout<<"\n\trecord of rollno not found!!!\n"<<endl;
        } 
		inFile.close();
		return 0;
    }
		
    void delete_record(int n)
	{
        Student obj;
        ifstream inFile;
        inFile.open("student.dat",ios::binary);
        ofstream outFile;
        outFile.open("temp.dat",ios::out|ios::binary);
        int a=search(n);
        if(a==1)
		{
            while(inFile.read((char*)&obj,sizeof(obj)))
            {
                if(obj.roll !=n)
                {
                    outFile.write((char*)&obj,sizeof(obj));
                }

            }

            inFile.close();
            outFile.close();
            remove("student.dat");
            rename("temp.dat","student.dat");
            cout<<"\n\n\tDeletion Successful!!\n"<<endl;
        }
       else
       {
            cout<<"\n\tNot present in the file!!\n";
       }  
}

int main(){
    int ch;
    while(ch!=5){
	cout<<"\n**\n";
    cout<<"1.Add record";
    cout<<"\n2.Display Record";
    cout<<"\n3.Search Record";
    cout<<"\n4.Delete a particular from Record";
    cout<<"\n5.Exit";
	cout<<"\n**\n";
	
    cout<<"\n\n\tEnter your choice : ";
    cin>>ch;
    
    switch(ch)
	{
        case 1:
        cout<<"\n\nEnter number of records to enter : ";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
        write_record();
        }
        break;
		
        case 2:
        cout<<"\nList of Records : \n"<<endl;
        display();
        break;
		
        case 3:
        cout<<"\n\nEnter the Student to be searched : ";
        int j;
        cin>>j;
        search(j);
        break;
		
        case 4:
        cout<<"\n\nEnter the Student to be deleted : ";
        int k;
        cin>>k;
        delete_record(k);
        break;

        case 5:
        break;
     }};
      return 0;
}