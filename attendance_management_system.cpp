#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<windows.h>
#include<unistd.h>
using namespace std;
struct data
{
    char fullName[30];
    char email[30];
    char password[30];
    char userName[30];  
    char mobileNo[30];
    char secQue[30];
    char secAns[30];
};

void getinput(char input[30])
{   
    fgets(input, 30, stdin);
    input[strlen(input) - 1] = 0;
}


void getusername(char input[30],struct data user,FILE *datafile)
{   
    datafile = fopen("Users.html","r+");
    if( access( "C:\\Users\\Admin\\Desktop\\Users.html", F_OK ) == 0)
    {
        char usernamecheck[30];
        char usernamecheck2[30];
        getinput(usernamecheck);

        while(fread(&user, sizeof(struct data), 1, datafile)){
            
            if(!strcmp(user.userName,usernamecheck))
            {   
                printf("\033[0;31m");
                printf("The username is already taken\n");
                printf("Please enter another username\n");
                printf("\033[0m");
                getinput(input);
                 for(int j = 0; j< strlen(usernamecheck);j++){
                    usernamecheck[j] = input[j];
                }
    
            }
            else
            {
                for(int j = 0; j< strlen(usernamecheck);j++){
                    input[j] = usernamecheck[j];
                }
            }
        }
        
    }
    else
    {
        getinput(input);
    }
    fclose(datafile);
};

int main()
{
     int selection;
    FILE *datafile;
    struct data user;
    char username2[30];
    char password2[30];
    char username3[30];
    char secAns2[30];
    printf("\t\t\t****Login System***\n");
    printf("Choose your option from below:\n");
    printf("1.Signup\n");
    printf("2.Login\n");
    printf("3.Forgot Password\n");
    printf("Enter the serial number of your choice:\n");
    scanf("%d",&selection);
    fgetc(stdin);
    
    switch(selection){
        case 1:
                system("cls");
                printf("\t\t\t***Signup Portal***\n");
                printf("Please enter the required information:\n");
                printf("Enter your full name:\n");
                getinput(user.fullName);
                printf("Please enter your username:\n");
                getusername(user.userName,user,datafile);
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

                datafile = fopen("Users.html","a+");
                fwrite(&user, sizeof(struct data), 1, datafile);
                if(fwrite != 0){
                    printf("\033[0;32m");
                    printf("Your account has been created.\n");
                    printf("Your username is: %s\n",user.userName);
                    printf("\033[0m");
                }
                else
                {
                    printf("There was an error.\n");
                }
                fclose(datafile);
                break;

        case 2:   
                system("cls");
                printf("\t\t\t***Login Portal***\n");   
                printf("Enter your username:\n");
                getinput(username2);
                printf("Enter your password:\n");
                getinput(password2);

                system("cls");

                datafile = fopen("Users.html","r");
                while(fread(&user, sizeof(struct data), 1, datafile))
                {
                    if(!strcmp(user.userName,username2)){
                        if(!strcmp(user.password,password2)){
                            
                            printf("\033[0;32m");
                            printf("Successful login at %s\n\n",user.fullName);
                            printf("\033[0m");

                            printf("Your profile data is:\n");
                            printf("Full Name       : %s\n",user.fullName);
                            printf("Email           : %s\n",user.email);
                            printf("Username        : %s\n",user.userName);
                            printf("Contact details : %s\n",user.mobileNo);
                            printf("Password        : %s\n",user.password);
                            
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

        case 3: 
                system("cls");
                printf("\t\t\t***Password retrieval Portal***\n");
                
                printf("Enter your username:\n");
                getinput(username3);

                datafile = fopen("Users.html","r");
                while(fread(&user, sizeof(struct data), 1, datafile))
                {   
                    if(!strcmp(user.userName,username3)){
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
                }
        return 0;
}