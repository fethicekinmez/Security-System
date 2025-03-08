#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){

    int choice, i=0;
    string user_name, password0, age;
    string user, pass, text, word;
    string old_pass, word1, password1, password2;
    string creds[2], cp[2];

    cout << "       Security System          " << endl;
    cout << " ______________________________ " << endl;
    cout << "|      1.Register              |" << endl;
    cout << "|      2.Login                 |" << endl;
    cout << "|      3.Change Password       |" << endl;
    cout << "|______4.Exit__________________|" << endl << endl;

    do{
        cout << endl << "Enter Your Choice: ";
        cin >> choice;

        switch (choice){
            case 1:
            {
                cout << " _____________________________ " << endl;
                cout << "|         Register            |" << endl;
                cout << " _____________________________ " << endl << endl;

                cout << "Please Enter User Name: " ;
                cin >> user_name;
                cout << "\nPlease Enter Password: " ;
                cin >> password0;
                cout << "\nPlease Enter Your Age: " ;
                cin >> age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1 << user_name << "\n";
                    of1 << password0;
                    cout << "Registration is SUCCESSFULL!" << endl;
                }
                of1.close();
            
                break;
            }

            case 2:
            {
                int i = 0;
                cout << " _____________________________ " << endl;
                cout << "|         Login               |" << endl;
                cout << " _____________________________ " << endl << endl;

                cout << "Please Enter User Name: " ;
                cin >> user;
                cout << "\nPlease Enter Password: " ;
                cin >> pass;

                ifstream of2;
                of2.open("file.txt");
                if(of2.is_open()){
                    while(!of2.eof()){
                        while(getline(of2, text)){  // read by line to line
                            istringstream iss(text);   
                            iss >> word;
                            creds[i] = word;
                            i++;
                        }

                        if(user == creds[0] && pass == creds[1]){
                            cout << "\nLOGIN SUCCESSFULL!!" << endl<<endl;
                            cout << "_____Details________"<< endl;
                            cout << "User name: " << user << endl;
                            cout << "Password: " << pass << endl;
                            cout << "Age: " << age << endl;
                        }
                        else{
                            cout << "\nIncorrect Credentials: Check username and password first!" << endl;
                            cout << "|      Press 2 to Login                 |" << endl;
                            cout << "|      Press 3 to Change Password       |" << endl;
                            break;
                        }
                    }
                }
                of2.close();

                break; 
            }    
            case 3:
            {
                int i = 0;

                cout << "|-----------Change Password------------|" << endl;
                cout << "Enter the old password: ";
                cin >> old_pass;

                ifstream of0;
                of0.open("file.txt");
                if(of0.is_open()){
                    while(!of0.eof()){
                        while(getline(of0, text)){  // read by line to line
                            istringstream iss(text);   
                            iss >> word1;
                            cp[i] = word1;
                            i++;
                        }
                        of0.close();

                        if(old_pass == cp[1]){
                            ofstream of1;
                            of1.open("file.txt");
                            if(of1.is_open()){
                                cout << "Enter the new password: ";
                                cin >> password1;
                                cout << "Enter the new password agaim: ";
                                cin >> password2;
                                if(password1 == password2){
                                    of1 << cp[0] << "\n";
                                    of1 << password1;
                                    cout << "Password change is SUCCESSFULL!!" << endl;
                                }
                                else{
                                    of1 << cp[0] << "\n";
                                    of1 << old_pass;
                                    cout << "Password DO NOT match!" << endl;
                                }
                                of1.close();
                            }
                            
                        }
                        else{
                            cout << "Please enter a valid password!" << endl;
                            break;
                        }
                        
                    }
                }
                
                break; 
            }
            case 4:
                cout << "----------------------Thank You----------------------" << endl;
                break;   
            default:
                cout << "Enter a valid choice!" << endl;
                break;
        }

    }while (choice != 4);
    

    return 0;
}