#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct stud
{
    int rno;
    char nm[20];
    int sem;
    char br[10];
}s1;
class student
{
    ofstream fout;
    ifstream fin;
public:
    student()
    {
    }
    void st_append()
    {
        fout.open("D:\\CPP_Prj\\Student_Mgmt\\st.dat", ios::app);
        if(!fout)
        {
            cout<<"\n\tCan't find/open the file"<<endl;
            exit(1);
        }
    }
    void st_read()
    {
        fin.open("D:\\CPP_Prj\\Student_Mgmt\\st.dat");
        if(!fin)
        {
            cout<<"\n\tCan't find/read the file"<<endl;
            exit(1);
        }
    }
    void add_student()
    {
        st_append();
        fout.write((char*)&s1, sizeof(s1));
        fout.close();
    }
    void display_all_students()
    {
        st_read();
        fin.read((char*)&s1, sizeof(s1));
        while(fin!=NULL)
        {
            cout<<"\nRoll No. : "<<s1.rno;
            cout<<"\nName     : "<<s1.nm;
            cout<<"\nSemester : "<<s1.sem;
            cout<<"\nBranch   : "<<s1.br<<endl;
            fin.read((char*)&s1, sizeof(s1));
        }
        fin.close();
    }
    int search_by_branch()
    {
        st_read();
        fin.read((char*)&s1, sizeof(s1));
        char branch[20];
        cout<<"Enter the branch to search : ";
        cin>>branch;
        int b=0;
        while(fin!=NULL)
        {
            if(strcmpi(s1.br, branch)==0)
            {
                b++;
                cout<<"\nRoll No. : "<<s1.rno;
                cout<<"\nName     : "<<s1.nm;
                cout<<"\nSemester : "<<s1.sem<<endl;
            }
            fin.read((char*)&s1, sizeof(s1));
        }
        fin.close();
        return b;
    }
    int search_by_name()
    {
        st_read();
        fin.read((char*)&s1, sizeof(s1));
        char name[20];
        cout<<"Enter the name to search : ";
        cin>>name;
        int n=0;
        while(fin!=NULL)
        {
            if(strcmpi(s1.nm, name)==0)
            {
                n++;
                cout<<"\nRoll No. : "<<s1.rno;
                cout<<"\nsemester : "<<s1.sem;
                cout<<"\nbranch   : "<<s1.br<<endl;
            }
            fin.read((char*)&s1, sizeof(s1));
        }
        fin.close();
        return n;
    }
    int search_by_Rollnumber()
    {
        st_read();
        fin.read((char*)&s1, sizeof(s1));
        int Rollno;
        cout<<"Enter the Roll number to search : ";
        cin>>Rollno;
        int r=0;
        while(fin!=NULL)
        {
            if(r == 0)
            {

                cout<<"\nName     : "<<s1.nm;
                cout<<"\nsemester : "<<s1.sem;
                cout<<"\nbranch   : "<<s1.br<<endl;
                r++;
            }
            fin.read((char*)&s1, sizeof(s1));
        }
        fin.close();
        return r;
    }
    void close()
    {
    }
};
int menu()
{
    int ans;
    cout<<"\n\tMenu :\n\t1. Add Student(s)\n\t2. See All Students";
    cout<<"\n\t3. Search by Branch\n\t4. Search by Name\n\t5. Search by Roll Number\n\t0. Exit/Quit"<<endl;
    cout<<"\nEnter the choice : ";
    cin>>ans;
    return ans;
}
main()
{
    student st;
    int b,n,r;
    int ans=menu();
    do
    {
        switch(ans)
        {
        case 1:
            cout<<"\nEnter the Roll No. : ";
            cin>>s1.rno;
            cout<<"\nEnter the Name     : ";
            cin>>s1.nm;
            cout<<"\nEnter the Semester : ";
            cin>>s1.sem;
            cout<<"\nEnter the Branch   : ";
            cin>>s1.br;
            st.add_student();
            break;
        case 2:
            st.display_all_students();
            break;
        case 3:
            b=st.search_by_branch();
            if(b==0)
                cout<<"\n\tNo record in this branch found"<<endl;
            else
                cout<<"\n\t"<<b<<" record(s) found in the specified branch"<<endl;
            break;
        case 4:
            n=st.search_by_name();
            if(n==0)
                cout<<"\n\tNo record in this semester found"<<endl;
            else
                cout<<"\n\t"<<n<<" record(s) found in the specified semester"<<endl;
            break;

        case 5:
            r=st.search_by_Rollnumber();
            if(r==0)
                cout<<"\n\tNo record in this semester found"<<endl;
            else
                cout<<"\n\t"<<r<<" record(s) found in the specified Roll number"<<endl;
            break;
        }
        ans=menu();
    }
    while(ans!=0);

}

