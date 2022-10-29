#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>                                               //to add ostream class template
#include<windows.h>
#include<unistd.h>
using namespace std;
class profile
{   
//     int employee_ID;    
//     static int no_of_employees;                                      //to count number of id's already made
    public:
        // int employee_ID;
        // static int no_of_employees;                                      //to count number of id's already made
        string fullName;
        string email;
        string password;
        string userName;  
        string mobileNo;
        string secQue;
        string secAns;
    
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

// void getinput(char input[30])
// {   
//     fgets(input, 30, stdin);
//     input[strlen(input) - 1] = 0;
// }


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
     int selection;
    FILE *datafile;
    //profile user;
    char username2[30];
    char password2[30];
    char username3[30];
    char secAns2[30];
    cout<<"\t\t\t****Login System***\n";
    cout<<"Choose your option from below:\n";
    cout<<"1.Signup\n";
    cout<<"2.Login\n";
    cout<<"1.Logout\n";
    cout<<"4.Forgot Password\n";
    cout<<"Enter the serial number of your choice:\n";
    cin>>selection;
    fgetc(stdin);
    
    switch(selection){
        case 1:
                system("cls");
                printf("\t\t\t***Signup Portal***\n");
                printf("Please enter the required information:\n");

                profile user;
                ofstream file_obj;                                                  // Object to write in file

                //int number_of_ids = user.getEmployeeID();
                // string filename = "User" + to_string(number_of_ids) + ".txt";

                // file_obj.open(filename, ios::app);

                // printf("Enter your full name:\n");
                // getinput(user.fullName);
                // printf("Please enter your username:\n");
                // getusername(user.userName,user,datafile);
                // printf("Please enter your email:\n");
                // getinput(user.email);
                // printf("Please enter your mobile no.:\n");
                // getinput(user.mobileNo);
                // printf("Please enter your password:\n");
                // getinput(user.password);
                // printf("Enter the security question:\n");
                // getinput(user.secQue);
                // printf("Enter the answer to security question:\n");
                // getinput(user.secAns);

                printf("Enter your full name:\n");
                getline(cin,user.fullName);

                string filename = "User_" + user.fullName;
                file_obj.open(filename, ios::app);

                printf("Please enter your username:\n");
                //getusername(user.userName,user,datafile);
                getline(cin,user.userName);
                printf("Please enter your email:\n");
                getline(cin,user.email);
                printf("Please enter your mobile no.:\n");
                getline(cin,user.mobileNo);
                printf("Please enter your password:\n");
                getline(cin,user.password);
                printf("Enter the security question:\n");
                getline(cin,user.secQue);
                printf("Enter the answer to security question:\n");
                getline(cin,user.secAns);

                system("cls");
                printf("Creating Account.......please wait\n");

                //datafile = fopen("Users.html","a+");
                // fwrite(&user, sizeof(), 1, datafile);

                file_obj.write((char*)&user, sizeof(user));

                // if(fwrite != 0){
                //     printf("\033[0;32m");
                //     printf("Your account has been created.\n");
                //     printf("Your username is: %s\n",user.userName);
                //     printf("\033[0m");
                // }
                // else
                // {
                //     printf("There was an error.\n");
                // }
                // fclose(datafile);
                break;

        // case 2:   
        //         system("cls");
        //         printf("\t\t\t***Login Portal***\n");   
        //         printf("Enter your username:\n");
        //         getinput(username2);
        //         printf("Enter your password:\n");
        //         getinput(password2);

        //         system("cls");

        //         datafile = fopen("Users.html","r");
        //         while(fread(&user, sizeof(struct data), 1, datafile))
        //         {
        //             if(!strcmp(user.userName,username2)){
        //                 if(!strcmp(user.password,password2)){
                            
        //                     printf("\033[0;32m");
        //                     printf("Successful login at %s\n\n",user.fullName);
        //                     printf("\033[0m");

        //                     printf("Your profile data is:\n");
        //                     printf("Full Name       : %s\n",user.fullName);
        //                     printf("Email           : %s\n",user.email);
        //                     printf("Username        : %s\n",user.userName);
        //                     printf("Contact details : %s\n",user.mobileNo);
        //                     printf("Password        : %s\n",user.password);
                            
        //                 }
        //                 else
        //                 {   
        //                     printf("\033[0;31m");
        //                     printf("Enter the correct password!\n");
        //                     printf("\033[0m");
        //                 }
                        
        //             }
        //             else
        //             {   
        //                 printf("\033[0;31m");
        //                 printf("User not registered.\n");
        //                 printf("\033[0m");
        //             }
        //         }
        //         fclose(datafile);
        //         break;

        // case 3:
        //         break;

        // case 4: 
        //         system("cls");
        //         printf("\t\t\t***Password retrieval Portal***\n");
                
        //         printf("Enter your username:\n");
        //         getinput(username3);

        //         datafile = fopen("Users.html","r");
        //         while(fread(&user, sizeof(struct data), 1, datafile))
        //         {   
        //             if(!strcmp(user.userName,username3)){
        //             printf("Answer the following Security Question:\n");
        //             printf("%s\n",user.secQue);
        //             getinput(secAns2);
        //             if(!strcmp(user.secAns,secAns2)){
        //             system("cls");
        //             printf("retrieving.......password\n");
        //             printf("\033[0;32m");
        //             printf("Success\n");
        //             printf("\033[0m");
        //             printf("Your password was : %s\n",user.password);
        //             }else
        //             {
        //                 system("cls");
        //                 printf("\033[0;31m");
        //                 printf("Incorrect answer!\n");
        //                 printf("\033[0m");
        //             }
        //             }
        //             else
        //             {
        //                 system("cls");
        //                 printf("\033[0;31m");
        //                 printf("No such user Found!\n");
        //                 printf("\033[0m");
        //             }
        //         }

        //         fclose(datafile);
        //         break;
                 }
        return 0;
}