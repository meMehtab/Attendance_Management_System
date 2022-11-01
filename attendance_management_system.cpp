#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>                                               //to add ostream class template
#include<windows.h>
#include<unistd.h>
#include <ctime>
#include <sstream> 
using namespace std;
class profile
{   
//     int employee_ID;    
//     static int no_of_employees;                                      //to count number of id's already made
    public:
        // int employee_ID;
        // static int no_of_employees;                                      //to count number of id's already made
        char fullName[30];
        char email[30];
        char password[30];
        char userName[30];  
        char mobileNo[30];
        char secQue[30];
        char secAns[30];
    
        // profile()
        // { 
        //      (this->employee_ID) = ++ (this->no_of_employees);
        //         // employee_ID ++;
        // }
        // ~profile()
        // {
        //     --(this->no_of_employees);
        // }
        // int getEmployeeID(void)
        // {
        //         return this->employee_ID;
        // }
};

class dates
{
        public:
        int date;
        int month;
        int year;
        int hr;
        int min;
        int sec;
        char day[30];
        char am_pm[30];
};

void getinput(char input[30])
{   
    fgets(input, 30, stdin);
    input[strlen(input) - 1] = 0;
}


// void getusername(char input[30],profile &object,FILE *datafile)
// {   
//     datafile = fopen("Users.html","r+");
//     if( access( "C:\\Users\\Admin\\Desktop\\Users.html", F_OK ) == 0)
//     {
//         char usernamecheck[30];
//         char usernamecheck2[30];
//         getinput(usernamecheck);

//         while(fread(&object, sizeof(object), 1, datafile)){
            
//             if(!strcmp(object.userName,usernamecheck))
//             {   
//                 printf("\033[0;31m");
//                 printf("The username is already taken\n");
//                 printf("Please enter another username\n");
//                 printf("\033[0m");
//                 getinput(input);
//                  for(int j = 0; j< strlen(usernamecheck);j++){
//                     usernamecheck[j] = input[j];
//                 }
    
//             }
//             else
//             {
//                 for(int j = 0; j< strlen(usernamecheck);j++){
//                     input[j] = usernamecheck[j];
//                 }
//             }
//         }
        
//     }
//     else
//     {
//         getinput(input);
//     }
//     fclose(datafile);
// };

int main()
{   
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    int date = local_time->tm_mday;
    int month = 1 + local_time->tm_mon;
    int hour = 1 + local_time->tm_hour;
    int min = 1 + local_time->tm_min;


    int selection;

    static int user_no;

    FILE *datafile;
    FILE *userfile;
    fstream file_obj; 

    profile user;

//     time_t ttime = time(0);
//     tm *local_time = localtime(&ttime);

    char nouse[30] = "User_";
    char username2[30];
    char password2[30];
    char password3[30];
    char username3[30];
    char username4[30];
    char username5[30];
    char secAns2[30];


    //do{


    cout<<"\t\t\t***Login System**\n";
    cout<<"Choose your option from below:\n";
    cout<<"1.Signup\n";
    cout<<"2.Login\n";
    cout<<"3.Logout\n";
    cout<<"4.Forgot Password\n";
    cout<<"5.Admin Login\n";
    cout<<"6.Exit\n";
    cout<<"Enter the serial number of your choice:\n";
    cin>>selection;
    fgetc(stdin);

        switch(selection){
                case 1:
                        system("cls");
                        printf("\t\t\t**Signup Portal**\n");
                        printf("Please enter the required information:\n");

                        //profile user;
                        // ofstream file_obj;                                                  // Object to write in file


                        printf("Enter your full name:\n");
                        getinput(user.fullName);
                        printf("Please enter your username:\n");
                        //getusername(user.userName,user,datafile);
                        getinput(user.userName);

                        user_no++;

                        userfile = fopen("Users.txt","a+");
                        fprintf(userfile, "%s %d %s %s \n" ,"User",user_no," : ",user.userName);
                        fclose(userfile);

                        //const char* demo = user.userName.c_str();
                        //string defaultstr = to_string(user.userName);                        //to convert const char to string
                        // char nouse[30] = "User_";
                        strcat(nouse,user.userName);
                        // string filename = "User_" + defaultstr;
                        file_obj.open(nouse, ios::app);

                        printf("Please enter your email:\n");
                        getinput(user.email);
                        printf("Please enter your mobile no.:\n");
                        getinput(user.mobileNo);
                        printf("Please enter your password:\n");
                        getinput(user.password);
                        printf("Enter the security question:\n");
                        getinput(user.secQue);
                        printf("Enter the answer to security question:\n");
                        getinput(user.secAns);

                        system("cls");
                        printf("Creating Account.......please wait\n");

                        //datafile = fopen("Users.html","a+");
                        // fwrite(&user, sizeof(), 1, datafile);

                        file_obj.write((char*)&user, sizeof(user));

                        if(fwrite != 0){
                        printf("\033[0;32m");
                        cout<<"Your account has been created."<<endl;
                        cout<<"Your username is : "<<user.userName<<endl;
                        printf("\033[0m");
                        }
                        else
                        {
                        cout<<"There was an error."<<endl;
                        }
                        // fclose(datafile);
                        break;


                case 2:   
                        // time_t ttime = time(0);
                        // tm *local_time = localtime(&ttime);

                        system("cls");
                        printf("\t\t\t**Login Portal**\n");   
                        printf("Enter your username:\n");
                        getinput(username2);
                        printf("Enter your password:\n");
                        getinput(password2);

                        system("cls");

                        //profile user2;
                        // fstream file_obje;

                        strcat(nouse,username2);

                        // int date = local_time->tm_mday;
                        // int month = 1 + local_time->tm_mon;
                        // int hour = 1 + local_time->tm_hour;
                        // int min = 1 + local_time->tm_min;

                        {stringstream stream;

                        stream << date;
                        string str_date;
                        stream >> str_date;

                        stream << month;
                        string str_month;
                        stream >> str_month;

                        stream << hour;
                        string str_hour;
                        stream >> str_hour;

                        stream << min;
                        string str_min;
                        stream >> str_min;                        

                        string object_name = str_date +" " + str_month + " " + str_hour + " " + str_min;
                        }
                        dates object_name;





                        // string demostr = to_string(username2);
                        // string filename2 = "User_" + demostr;
                        //const char* str = filename2.c_str();

                        // file_obje.open(filename2, ios::in);

                        // if (!file_obje) {
                        //         cout << "No such User Registered"<<endl;
                        // }
                        // else{
                        datafile = fopen(nouse,"r");
                
                        while(fread(&user, sizeof(user), 1, datafile))
                        {
                        if(!strcmp(user.userName,username2)){
                                if(!strcmp(user.password,password2)){
                                
                                printf("\033[0;32m");
                                printf("Successful login at %s\n\n",user.fullName);
                                printf("\033[0m");

                                fclose(datafile);

                                file_obj.open(nouse, ios::app);
                                
                                object_name.date = date;
                                object_name.month = month;
                                object_name.year =  1900 + local_time->tm_year ;
                                object_name.hr = 1 + local_time->tm_hour;
                                object_name.min = 1 + local_time->tm_min;
                                object_name.sec = 1 + local_time->tm_sec;
                                //object_name.day = 1 + local_time->tm_sec;



                                file_obj.write((char*)&object_name, sizeof(object_name));
                                }
                                else
                                {   
                                printf("\033[0;31m");
                                printf("Enter the correct password!\n");
                                printf("\033[0m");
                                }
                                
                        }
                        else
                        {   
                                printf("\033[0;31m");
                                printf("User not registered.\n");
                                printf("\033[0m");
                        }
                        }
                        //fclose(datafile);
                        //}
                        break;

                case 3: 
                        system("cls");        
                        printf("\t\t\t**Logout Portal**\n");
                        
                        printf("Enter your username:\n");
                        getinput(username4);
                        printf("Enter your password:\n");
                        getinput(password3);

                        //system("cls");

                        strcat(nouse,username4);
                        datafile = fopen(nouse,"r");

                        while(fread(&user, sizeof(user), 1, datafile))
                        {
                        if(!strcmp(user.userName,username4)){
                                if(!strcmp(user.password,password3)){
                                
                                printf("\033[0;32m");
                                printf("Successful logout at %s\n\n",user.fullName);
                                printf("\033[0m");                            
                                }
                                else
                                {   
                                printf("\033[0;31m");
                                printf("Enter the correct password!\n");
                                printf("\033[0m");
                                }
                                
                        }
                        else
                        {   
                                printf("\033[0;31m");
                                printf("User not registered.\n");
                                printf("\033[0m");
                        }
                        }
                        fclose(datafile);

                        break;

                case 4: 
                        system("cls");
                        printf("\t\t\t**Password retrieval Portal**\n");
                        
                        printf("Enter your username:\n");
                        getinput(username3);

                        strcat(nouse,username3);

                        datafile = fopen(nouse,"r");
                        while(fread(&user, sizeof(user), 1, datafile))
                        {   
                        if(!strcmp(user.userName,username3))
                        {
                                printf("Answer the following Security Question:\n");
                                printf("%s\n",user.secQue);
                                getinput(secAns2);
                                if(!strcmp(user.secAns,secAns2)){
                                        system("cls");
                                        printf("retrieving.......password\n");
                                        printf("\033[0;32m");
                                        printf("Success\n");
                                        printf("\033[0m");
                                        printf("Your password was : %s\n",user.password);
                                }else
                                        {
                                                system("cls");
                                                printf("\033[0;31m");
                                                printf("Incorrect answer!\n");
                                                printf("\033[0m");
                                        }
                        }
                        else
                        {
                                system("cls");
                                printf("\033[0;31m");
                                printf("No such user Found!\n");
                                printf("\033[0m");
                        }
                        }

                        fclose(datafile);
                        break;

                case 5: 
                        printf("\t\t\t**Admin Login Portal**\n");
                        cout<<"Enter username :"<<endl;
                        getinput(username5);

                        



                        // }
                return 0;
        }
       // }while(selection != 5);
}