#include <iostream>
#include <cstring>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <unistd.h>

using namespace std;
class menu
{
    public:
    virtual void login()=0;
    virtual void registration()=0;
    void getdata(){
    B:    
    system("cls");
    char c;
    int user_choice;
    string fname;
    char usern[100];
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t -->> USER MENU <<--";
    cout << "\n\n\t\t 1. Login";
    cout << "\n\t\t 2. Registration";
    cout << "\n\t\t 3. Exit";
    cout << "\n\t\tEnter Choice: ";
    cin >> user_choice;

    switch(user_choice)
    {
        case 1:
            login();
            break;
        case 2:
             registration(); 
             break;
        case 3:
            system("cls");
            cout << "\n\n\t\t\t COVID19 MANAGEMENT SYSTEM ";
            break;
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
            cout<<"Press any key to continue.....";
            getchar();
            getchar();
            goto B;
    }
    
}
};

class sub_menu:public menu
{
protected:
    string username;
    string password;
    string usn;
    char u_name[100], u_pass[100];
    char name[100];
    char gender[100];
    int age;
    string mob_no;
    string vaccine_name;
    string center;
    string adhaar;
    int dose;
    string center1 = "1center";
    string center2 = "2center";
    string center3 = "3center";
    int sum_vaccine_c1 = 0; // Center1 vaccine Dose
    int sum_vaccine_c2 = 0; // Center2 vaccine Dose
    int sum_vaccine_c3 = 0; // Center3 vaccine Dose
    int add, center_no;

    public:
    void user();
    void menu();
    void search_center1();
    void search_center2();
    void search_center3();       // 1
    void add_patient_data();    // 2
    void update_patient_data();
    void patient_show_data(); // 4
    void show_data();

    void login()
    {
        system("cls");
        string username;
        string password1;
        char u_name[100];
        char u_pass[100];
        string usn;
        int count;
        string id;
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\n\t\t -->> LOGIN USER <<--";
        cout << "\n\n\t\tEnter Your Username: ";
        cin >> u_name;
        cout << "\n\t\tEnter Your Password: ";
        cin >> u_pass;
        ifstream input("records.txt");
        while(input>>id>>password1)
        {
            if(id==u_name && password1==u_pass)
            {
                count=1;
                system("cls");
            }
        }
        input.close();
        if(count==1)
        {
            cout << "\nYou are successfully logged in :)";
            cout<<"\nPress Enter to continue......";
            getchar();
            getchar();
            user();
        }
        else
        {
            cout << "\nYou are not registered, please register before logging in.\n";
            cout<<"\nPress any key to continue.....";
            getchar();
            getchar();
            getdata();
        }  
        
    }
    void registration ()
    {
        system("cls");
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\n\t\t -->> REGISTRATION USER <<--";
        cout << "\n\t\tEnter Your Username: ";
        cin >> usn;
        cout << "\n\t\tEnter Your password: ";
        cin >> password;
        ofstream f1("records.txt",ios::app);
        f1<<usn<<password<<endl;
        cout << "\nYou are successfully registered :)";
        cout<<"\nPress any key to continue.....";
        getchar();
        getchar();
        f1.close();
        getdata();
    }

};


void sub_menu::user()
{

B:
    system("cls");
    int user_choice;
    string date;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    // USER MENU OPTIONS
    cout << "\n\n\t\t -->> USER MENU <<--";
    cout << "\n\n\t\t 1. Search Vaccination Center";
    cout << "\n\t\t 2. Apply For Vaccine First Dose";
    cout << "\n\t\t 3. Apply For Vaccine Second Dose";
    cout << "\n\t\t 4. Show Details";
    cout << "\n\t\t 5. LOG OUT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> user_choice;
    system("cls");
    switch (user_choice)
    {
    case 1:
        int center_choice;
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\n\t\t-->> Various Vaccination Centers In Your City <<--";
        cout << "\n\n\t\t -->> SELECT CENETR <<--";
        cout << "\n\n\t\t 1. Center 1";
        cout << "\n\t\t 2. Cenetr 2";
        cout << "\n\t\t 3. cenetr 3";
        cout<<endl;
        cin>>center_choice;
        switch (center_choice){
            case 1:
            search_center1();
            cout<<"Enter Date : ";
            cin>>date;
            goto B;
            case 2:
            search_center2();
            cout<<"Enter Date : ";
            cin>>date;
            goto B;
            case 3:
            search_center3();
            cout<<"Enter Date : ";
            cin>>date;
            goto B;
        }

    case 2:
        add_patient_data();
        goto B;
    case 3:
        update_patient_data();
        goto B;
    case 4:
        patient_show_data();
    default:
        cout << "\n\n\t\tInvalid Choice.. Please Try Again..\n";
        cout << "\n\nPress Any Key To Continue..";
        getchar();
        getchar();
        goto B;
    }
}

void sub_menu::search_center1()
{
    system("cls");
    ifstream file;
    file.open("center1.txt");
    cout<<endl;
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        string ch;
        while (1)
        {
            file >> ch;
            if (file.eof())
                break;
            cout << ch<<endl;
        }
    }
    file.close();
}

    void sub_menu::search_center2()
{
    system("cls");
    ifstream file;
    file.open("center1.txt");
    cout<<endl;
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        string ch;
        while (1)
        {
            file >> ch;
            if (file.eof())
                break;
            cout << ch<<endl;
        }
    }
    file.close();
}
    
    void sub_menu::search_center3()
{
    system("cls");
    ifstream file;
    file.open("center1.txt");
    cout<<endl;
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        string ch;
        while (1)
        {
            file >> ch;
            if (file.eof())
                break;
            cout << ch<<endl;
        }
    }
    file.close();
}
    

void sub_menu::add_patient_data()
{
    ofstream file("add_patient_data.txt",ios :: app | ios :: binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> APPLY FOR VACCINE FIRST DOSE <<--";
    cout << "\n\n\t\tEnter Name: ";
    fflush(stdin);
    cin.getline(name, 100);
B:
    cout << "\n\n\t\tEnter Your Mobile Number: ";
    cin >> mob_no;
    if (mob_no.length() != 10)
    {
        cout << "\nInvalid Phone Number";
        cout<<endl<<"Enter again ....";
        sleep(5);
        goto B;
    }
    else
    {
        if (mob_no[0] == '0' || mob_no[0] == '1')
        {
            cout << "\nInvalid Phone Number";
            cout<<endl<<"Enter again ....";
            sleep(5);
            goto B;
        }
        else
        {
            cout << "\nValid Phone Number";
        }
    }
    cout << "\n\n\t\tEnter Gender (M/F): ";
    cin >> gender;
    cout << "\n\n\t\tEnter Age: ";
    cin >> age;
    cout<<"\nEnter Adhaar Number:";
    cin>> adhaar;
    cout << "\n\n\t\tEnter Vaccine Name [Covishield & Covaxin]: ";
    cin >> vaccine_name;
    cout << "\n\n\t\tEnter Dose: ";
    cin >> dose;
    cout << "\n\n\t\tEnter Center Allotted: ";
    cin >> center;
    file<<endl<<"Adhaar number : "<<adhaar<<endl<<"Name : "<<name<<endl<<"Mobile no. : "<<mob_no<<endl<<"Gender : "<<gender<<endl<<"Age : "<<age<<endl<<"Vaccine name : "
        <<vaccine_name<<endl<<"Dose : "<<dose<<endl<<"Center : "<<center<<endl << "objectend" << endl;
    cout << "\n\nYOU HAVE SUCCESSFULLY VACCINATED :)";
    cout << "\n\nPress Any Key To Continue..";
    getchar();
    getchar();
    file.close();
}

sub_menu c;

void sub_menu::update_patient_data()
{
    string maadhaar;
    system("cls");
    int count = 0;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> APPLY FOR SECOND DOSE <<--";
    cout << "\n\n\t\tEnter Adhar Number: ";
    cin>>maadhaar;
    string word;
    fstream file("add_patient_data.txt", ios:: in | ios::out);
    while(file >> word)
    {
        if (maadhaar.compare(word) == 0)
        {
            count++;
            while(getline(file, word))
            {
                if(word.compare("Dose : 1") == 0)
                {
                    fstream temp("add_patient_data.txt", ios:: in | ios::out);
                    string tmpsentence;
                    while(temp >> tmpsentence)
                    {
                        if (maadhaar.compare(tmpsentence) == 0)
                        
                            while(getline(temp, tmpsentence))
                            {
                                if(tmpsentence.compare("Vaccine name : Covaxin") == 0 || tmpsentence.compare("Vaccine name : Covidshield") == 0)
                                {
                                    temp << "Dose : 2";
                                }
                                if(tmpsentence.compare("objectend") == 0)
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
                if(word.compare("objectend") == 0)
                {
                    break;
                }
            }
        }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    ifstream output("add_patient_data.txt");
    string ch;
    while(output >> ch)
    {
        if (maadhaar.compare(ch) == 0)
        {
            while(getline(output, ch))
            {
                if(ch.compare("objectend") == 0)
                {
                    break;
                }
                else{
                    cout << ch << endl;
                }
            }
        }
    }
    output.close();
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getchar();
    getchar();
}

void sub_menu::patient_show_data()
{
    int count = 0;
    string vadhaar;
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH DATA BY AADHAR <<--";
    cout << "\n\n\t\tEnter Aadhar No.: ";
    cin >> vadhaar;
    ifstream file("add_patient_data.txt");
    string word;
    while(file >> word)
    {
        if (vadhaar.compare(word) == 0)
        {
            count++;
            while(getline(file, word))
            {
                if(word.compare("objectend") == 0)
                {
                    break;
                }
                else{
                    cout << word << endl;
                }
            }
        }
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getchar();
    getchar();
}

int main()
{
    system("color B");
    sub_menu system;
    
    system.getdata();

}