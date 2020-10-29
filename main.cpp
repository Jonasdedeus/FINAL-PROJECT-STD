#include<iostream>
#include<windows.h>
#include<string>
#include "ProjectSTD.h"


using namespace std;

int main()
{
    graph G;
    createGraph(G);
    FirstScreen();    /**DISPLAY A FIRST SCREEN*/
    Login();          /**SHOULD ENTER THE USERNAME AND PASSWORD TO RUN THE PROGRAM*/
    MainMenu(G);      /**USERNAME: jonas ; PASSWRORD: armando*/
    return 0;
}

/** MAIN PROCEDURES*/
void MainMenu(graph &G){
    string Major, SID, Nation, RN, Name;
    string NamF,NamS,NameE;
    int choose;
    do{
        cout<<endl;
        cout<<endl;
        cout<<"                                                                   <>=====================================<>"<<endl;
        cout<<"                                                                        XX INTERNATIONAL DORMITORY XX"<<endl;
        cout<<"                                                                      <>==============================<>"<<endl;
        cout<<"                                                                               CHOOSE THE OPTION" << endl;
        cout<<"                                                                     -------------------------------------"<<endl;
        cout<<"                                                                         1. ADD PERSON "<<endl;
        cout<<"                                                                         2. DELETE PERSON "<<endl;
        cout<<"                                                                         3. ADD FRIENDSHIP "<<endl;
        cout<<"                                                                         4. DELETE FRIENDSHIP "<<endl;
        cout<<"                                                                         5. DISPLAY STUDENT DATA IN THE DORMITORY "<<endl;
        cout<<"                                                                         6. SEARCH STUDENT IN THE DORMITORY "<<endl;
        cout<<"                                                                         7. FIND A NUMBER OF FRIENDS "<<endl;
        cout<<"                                                                         8. DEPTH FIRST SEARCH "<<endl;
        cout<<"                                                                         9. POPULAR PERSON "<<endl;
        cout<<"                                                                         10.FRIENDS GROUP "<<endl;
        cout<<"                                                                         0. EXIT "<<endl;
        cout<<" "<<endl;
        cout<<"                                                                        Choose : ";
        cout<<"";cin>>choose;
        cout<<"                                                                    <>=====================================<>"<<endl;
        cout<<endl;
        switch(choose){
        case 1:
            adrVertex p;
            cout<<"                                                                          [<>]Input the data[<>]"<<endl;
            cout<<"                                                                          ======================="<<endl;
            cin.ignore();
            cout<<"                                                                        Full name    : ";
            getline(cin,Name);
            cout<<"                                                                        SID          : ";
            cin>>SID;
            cin.ignore();
            cout<<"                                                                        Major        : ";
            getline(cin,Major);
            cout<<"                                                                        Nationality  : ";
            getline(cin,Nation);
            cout<<"                                                                        Room Number  : ";
            getline(cin,RN);
            p = createVertex(RN,Name,SID,Nation,Major);
            addPerson(G,p);
            cout<<endl;
            cout<<"                                                                        DATA IS INSERTED"<<endl;
            break;
        case 2:
            cin.ignore();
            cout<<"                                                                        Who is going to be deleted  " <<endl;
            cout<<"                                                                        Full Name: ";
            getline(cin,Name);
            p = findVertex(G,Name);
                if(p!=NULL){
                    deletePerson(G,Name,p);
            cout<<"                                                                        "<<Name<<" is deleted "<<endl;
                }else{
                    cout<<"                                                                 There is no"<<Name<<endl;
                }
            break;
        case 3:
            adrVertex q;
            adrEdge g;
            cout<<"                                                                         [<>]ADD FRIEND[<>]"<<endl;
            cout<<"                                                                     ========================="<<endl;
            cin.ignore();
            cout<<"                                                                    <*> Your full name : ";
            getline(cin,NamF);
            cout<<endl;
            cout<<"                                                                    \t"<<NamF<<", who do you want to make a friend?  Full Name : ";
            getline(cin,NamS);
            cout<<endl;
                p = findVertex(G,NamF);
                q = findVertex(G,NamS);
                if(p!=NULL && q!=NULL){
                    adrEdge f = createEdge(NamS);
                    adrEdge g = createEdge(NamF);
                    if(findFriend(G,p,NamS)==NULL){
                        insertEdge(p,f);
                        insertEdge(q,g);
                        cout<<"                                                                      CONGRATULATION !!  Friend request is accepted "<<endl;
                    }else{
                        cout<<"                                                                      You are already friend"<<endl;
                    }
                }else if (q!=NULL){
                    cout<<"                                                                      Sorry "<<NamF<<", you are not register in the Dormitory "<<endl;
                }else if (p!=NULL){
                    cout<<"                                                                      Sorry "<<NamF<<", There is no "<<NamS<<endl;
                }else{
                    cout<<"                                                                      BOTH OF YOU HAVE NOT REGISTER YET. "<<endl;
                }
            break;
        case 4:
            cin.ignore();
            cout<<"                                                                        Your Name : " ;
            getline(cin,NamF);
            cout<<"\t                                                                       "<<NamF<<", With who do you want to delete friendship : ";
            getline(cin,NamS);
            p = findVertex(G,NamF);
            q = findVertex(G,NamS);
            if(p!=NULL && q!=NULL){
                if(findEdge(G,p,NamS)!=NULL){
                    adrEdge f = findFriend(G,p,NamS);
                    adrEdge g = findFriend(G,q,NamF);
                    deleteEdge(p,NamS,f);
                    deleteEdge(q,NamF,g);
            cout<<"                                                                         "<<NamF<<", You have just deleted your friendship with "<<NamS<<endl;
                }else{
                    cout<<"                                                                  Not Found";
                }
            }else{
                cout<<"                                                                      There is no Person";
            }
            break;
        case 5:
            cin.ignore();
            printData(G);
            break;
        case 6:
            cin.ignore();
            cout<<"                                                                            Input Name : ";
            getline(cin,NameE);
            cout<<endl;
                p = findVertex(G,NameE);
                if(p!=NULL){
                    cout<<"                                                                   Found: There is "<<NameE<<endl;
                }else{
                    cout<<"                                                                   Not Found: There is no "<<NameE<<endl;
                }
            break;
        case 7:
            cin.ignore();
            cout<<"                                                                           Your Full name: ";
            getline(cin,Name);
            cout<<endl;
            cout<<highNumFrd(G,Name);
            break;
        case 8:
            cout<<"                                                                       Check Whether both of you are friends or not"<<endl;
            cout<<"                                                                     ============================================" <<endl;
            cin.ignore();
            cout<<"                                                                       First Person : " ;
            getline(cin,NamF);
            cout<<"                                                                       Second Person : ";
            getline(cin,NamS);
            p = findVertex(G,NamF);
            q = findVertex(G,NamS);
            if(p!=NULL && q!=NULL){
                adrEdge f = findFriend(G,p,NamS);
                adrEdge g = findFriend(G,q,NamF);
                if(f!=NULL && g!=NULL){
                    cout<<"                                                                        Notifications : You are friends"<<endl;
                }else{
                    cout<<"                                                                        Notifications : You are not friends"<<endl;
                }
            }else if(p!=NULL){
                cout<<"                                                                "<<NamF<<" There is no "<<NamS<<endl;
            }else if(q!=NULL){
                cout<<"                                                                "<<NamS<<" There is no "<<NamF<<endl;
            }else{
                cout<<"                                                                   There exist no "<<NamF<<" and "<<NamS<<endl;
            }
            break;
        case 9:
            findMaxFriends(G,p);
            break;
        case 10:
            cin.ignore();
            cout<<"                                                                        Input Country: ";
            getline(cin,Nation);
            friendGroupNation(G,p,Nation);
            cout<<endl;

            cout<<"                                                                        Input Major: ";
            getline(cin,Major);
            friendGroupMajor(G,p,Major);
            break;
        case 0:
            cout<<"                                                                        THANK YOU, OBRIGADO, MERCI "<<endl;
            break;
        default:break;
        }
    }while(choose!=0);
}

void FirstScreen(){
    cout<<"\n\n\n\n\n\n\n\n\n\n";

    cout<<"                                                  [XX]======================================================================[XX]"<<endl;
    cout<<"                                                     ||                                                                    || "<<endl;
    cout<<"                                                   {}                      UNDIRECTED GRAPH OF FRIENDSHIP                    {} "<<endl;
    cout<<"                                                   {}                    ---------- FINAL PROJECT----------                  {} "<<endl;
    cout<<"                                                     ||                                                                    || "<<endl;
    cout<<"                                                  [XX]======================================================================[XX]"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                                                 Press keyboard ENTER..."<<endl;
    cin.ignore();

}

void Login(){
    string Name,pas;
    bool found = false;
    while(!found){
        cout<<"                                                             ====================Login Account===================="<<endl;
        cout<<"                                                             ====================================================="<<endl;
        cout<<"                                                              Username : ";
        cin>>Name;
        cout<<"                                                              Password : ";
        cin>>pas;
        if(Name=="jonas"&& pas=="armando"){
            found = true;
        }else{
        cout<<endl;
        cout<<"                                                                     ==================================="<<endl;
        cout<<"                                                                     || USERNAME OR PASSWORD IS WRONG ||"<<endl;
        cout<<"                                                                     ==================================="<<endl;
        cout<<""<<endl;
        cout<<"                                                          -------------------------------------------------------------"<<endl;
        cout<<endl;
        }
    }
    cout<<endl;
    cout<<"                                                              ===================================================="<<endl;
    cout<<"                                                              ===================================================="<<endl;

    clrscr();

    loading();
}

int loading(){

    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
    char a=177,b=219;
    cout<<" \n\n\n\t\t\t\t\t\t\t\t\tloading...";
    cout<<"\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t";
    for(int i= 0;i<=25;i++)
        cout<<a;
        Sleep(150);
    cout<<"\r";
    cout<<"\t\t\t\t\t\t\t\t\t";
    for(int i=0;i<=25;i++){
        cout<<b;
        Sleep(200);
    }
    cout<<" \n\n\n\t\t\t\t\t\t\t\t\tloading completed!";
    cout<<"\n\n";

    clrscr();
    return 0;
}

void clrscr(){
    system("CLS");
}
