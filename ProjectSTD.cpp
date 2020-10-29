#include "ProjectSTD.h"
#include<iostream>
#include<string>

/** RETURN TRUE IF EMPTY OTHERWISE RETURN FALSE*/

bool isEmptyGraph(graph G){
/*return true value if graph list empty*/

    return firstVertex(G)== NULL;
}

bool isEmptyChild(adrVertex p){
/*return true value if child list empty*/

    return firstEdge(p)== NULL;
}

/** PROCEDURE CREATE GRAPGH AND CHILD ARE GOING TO CREATE EMPTY LIST*/

void createGraph(graph &G){
/*I.S. -
  F.S. graph empty list created*/

    firstVertex(G)= NULL;
}

void createChild(adrVertex &p){
/*I.S. -
  F.S. child empty list created*/

    firstEdge(p)= NULL;
}

/** FUNCTION CREATEEDGE AND CREATEVERTEX ARE GOING TO ALLOCATE THE DATA IN ADDRESS*/

adrVertex createVertex(string RN, string Name, string SID , string Nation, string Major){
/*  Process: deploy address from allocation of a graph element if allocation succeed.
    F.S. Return the address otherwise return NULL */

    adrVertex p;
    p = new elmtVertex;
    infoVertex(p).name = Name;
    infoVertex(p).ID = SID;
    infoVertex(p).major = Major;
    infoVertex(p).nation = Nation;
    infoVertex(p).rn = RN;
    nextVertex(p)= NULL;
    firstEdge(p)=NULL;
    return p;
}

adrEdge createEdge(string Name){
/*  Process: deploy address from allocation of a vertex element if allocation succeed.
    F.S. Return the address otherwise return NULL */

    adrEdge f;
    f = new elmtEdge;
    infoEdge(f) = Name;
    NextEdge(f)= NULL;
    return f;
}

/** PROCEDURE ADD PERSON AND FRIENDSHIP*/

void addPerson(graph &G, adrVertex p){
/* I.S. random, person allocated
   F.S. placing the first person in graph element as an insert first, otherwise insert last*/

     if (firstVertex(G) == NULL) {
       firstVertex(G)= p;
       nextVertex(p)= NULL;
    } else {
        adrVertex lp = firstVertex(G);
        while(nextVertex(lp)!=NULL){
            lp = nextVertex(lp);
        }
        if(nextVertex(lp)==NULL){
            nextVertex(lp) = p ;
            nextVertex(p) = NULL;
        }
    }
}

void insertEdge(adrVertex &p, adrEdge f){
/* I.S. random, friend allocated
   F.S. placing the first friend in vertex element as an insert first*/

    if(isEmptyChild(p)){
        firstEdge(p)= f;
    }else{
        NextEdge(f)= firstEdge(p);
        firstEdge(p)= f;
    }

}

/** PROCEDURE DELETE PERSON AND FRIENDSHIP*/

void deleteFirstPerson(graph &G, adrVertex &p){
/* I.S. List is not empty
   F.S. is person from the first of the graph
    Before first person removed
    first person removed and graph might become empty
    The new first person is the successor before the old first person*/

    if(firstVertex(G)!=NULL){
        p = firstVertex(G);
        if(nextVertex(p)==NULL){
            createGraph(G);
        }else{
            firstVertex(G)= nextVertex(p);
            nextVertex(p)=NULL;
        }
    }
}

void deleteAfterPerson(graph &G, adrVertex &p,adrVertex prec){
/* I.S. Graph is not empty, PREC address is one of the person in the graph; P is the address from next(PREC)
   F.S. P removed from from the graph*/

    p = nextVertex(prec);
    nextVertex(prec)= nextVertex(p);
}

void deleteLastPerson(graph &G, adrVertex &p){
/* I.S. Graph is not empty
   F.S. is person from the end of the graph,
    Before last person removed.
    last person removed and graph might become empty
    The new last person is the person before the old last person*/

    adrVertex prec;
    prec = firstVertex(G);
    p = nextVertex(prec);
    while (nextVertex(p)!= NULL){
        prec = p;
        p = nextVertex(p);
    }
    nextVertex(prec) = NULL ;
}

void deletePerson(graph &G, string Name,adrVertex &p){
/* I.S. Graph is not empty. P is the address of the person that we have inputed the name
   F.S. The person had address P was deleted*/

    adrVertex prec;
    findEdgeDel(G,p,Name);
    if(firstVertex(G)== p){
        deleteFirstPerson(G,p);
    }else if(nextVertex(p)==NULL){
        deleteLastPerson(G,p);
    }else{
        prec = firstVertex(G);
        p = nextVertex(prec);
        while(infoVertex(p).name != Name){
            prec = p;
            p = nextVertex(p);
        }
        if(infoVertex(p).name == Name){
            deleteAfterPerson(G,p,prec);
        }
    }
}

void deleteFirstEdge(adrVertex &p, adrEdge &f){
/* I.S. FirstEdge is not empty
   F.S. is friend from the first of the vertex
    Before first friend remove
    first friend removed and firstEdge might become empty
    The new first friend is t    he successor before the old first friend*/

    if(firstEdge(p)!=NULL){
        f = firstEdge(p);
        if(NextEdge(f)==NULL){
            createChild(p);
        }else{
            firstEdge(p)= NextEdge(f);
            NextEdge(f)=NULL;
        }
    }
}

void deleteAfterEdge(adrVertex &p, adrEdge &f, adrEdge prec){
/* I.S. Vertex is not empty, PREC address is one of the friend in the vertex
   F.S. F is the address from next(PREC), removing next(PREC) from vertex*/

    f = NextEdge(prec);
    NextEdge(prec)= NextEdge(f);
}

void deleteLastEdge(adrVertex &p, adrEdge &f){
/* I.S. FirstEdge is not empty
   F.S. is friend from the last of the vertex
    Before last friend remove
    last friend removed and firstEdge might become empty
    The new last friend is the friend before the old last friend*/

    adrEdge prec;
    prec = firstEdge(p);
    f = NextEdge(prec);
    while (NextEdge(f)!= NULL){
        prec = f;
        f = NextEdge(f);
    }
    NextEdge(prec)= NULL;
}


void deleteFriendship(adrVertex &p, string Name, adrEdge &f){
/* I.S. Vertex is not empty
   F.S. friendship between two person was deleted */

    adrEdge prec;
    if(firstEdge(p)== f){
        deleteFirstEdge(p,f);
    }else if(NextEdge(f)==NULL){
        deleteLastEdge(p,f);
    }else{
        prec = firstEdge(p);
        f = NextEdge(prec);
        while(infoEdge(f) != Name){
            prec = f;
            f = NextEdge(f);
        }
        if(infoEdge(f) == Name){
            deleteAfterEdge(p,f,prec);
        }
    }
}

void deleteEdge(adrVertex &p, string Name, adrEdge &f){
/* I.S. Vertex is not empty
   F.S. friend will be deleted based on the name*/

    adrEdge prec;
    if(firstEdge(p)== f){
        deleteFirstEdge(p,f);
    }else if(NextEdge(f)==NULL){
        deleteLastEdge(p,f);
    }else{
        prec = firstEdge(p);
        f = NextEdge(prec);
        while(infoEdge(f) != Name){
            prec = f;
            f = NextEdge(f);
        }
        if(infoEdge(f) == Name){
            deleteAfterEdge(p,f,prec);
        }
    }
}

/** PROCEDURE SEARCH THE PERSON AND FRIENDS */

adrVertex findVertex(graph G, string Name){
/*search if there is a person with info(person). name = Name. If it exist, return the address of that person
and NULL if not*/

    if(firstVertex(G)==NULL){
        return NULL;
    } else {
        adrVertex p = firstVertex(G);
        while(p!=NULL && infoVertex(p).name!= Name){
            p = nextVertex(p);
        }
        if(p!=NULL){
            return p;
        } else {
            return NULL;
        }
    }
}

adrEdge findEdge(graph G, adrVertex p, string Name){
/*search if there is a friend with info(friend).name = Name. If it exist, return the address of that person
and looping until end, return NULL if not found*/

    adrEdge f;
    if(!isEmptyGraph(G)){
        p = firstVertex(G);
        while(p!=NULL){
            if(!isEmptyChild(p)){
                f = firstEdge(p);
                while(f!=NULL && infoEdge(f)!= Name){
                    f = NextEdge(f);
                }
                if(f!=NULL){
                    return f;
                }
            }
            p = nextVertex(p);
        }
        if(p!=NULL){
            return f;
        }else{
            return NULL;
        }
    }
}

void findEdgeDel(graph G, adrVertex p, string Name){
/*I.S. Graph and vertex is not empty
  F.S .search if there is a friend with info(person). name = Name. If it exist, delete that person*/

    adrEdge f;
    if(!isEmptyGraph(G)){
        p = firstVertex(G);
        while(p!=NULL){
            if(!isEmptyChild(p)){
                f = firstEdge(p);
                while(f!=NULL && infoEdge(f)!= Name){
                    f = NextEdge(f);
                }
                if(f!=NULL){
                    deleteFriendship(p,Name,f);
                }
            }
            p = nextVertex(p);
        }
        if(p!=NULL){
            deleteFriendship(p,Name,f);
        }
    }
}

adrEdge findFriend(graph G, adrVertex p, string Name){
/*search if there is a friend with info(friend).name = Name. If it exist, return the address of that person
and NULL if not*/

    adrEdge f;
    if(firstEdge(p)==NULL){
        return NULL;
    }else{
        f = firstEdge(p);
        while(f!=NULL && infoEdge(f) != Name){
            f = NextEdge(f);
        }
        if(f!=NULL){
            return f;
        }else{
            return NULL;
        }
    }
}

void findMaxFriends(graph G, adrVertex p){
/*I.S. Graph might be empty
  F.S. output the highest friend */

    adrVertex highest,equalP;
    equalP = NULL;
    if(firstVertex(G)==NULL){
        cout<<"                                                                             LIST IS EMPTY"<<endl;
    }else{
        p = firstVertex(G);
        if(nextVertex(p)==NULL){
                cout<<"                                                           "<<infoVertex(p).name<<", you do not have friends "<<endl;
        }else{
            highest = p;
            p = nextVertex(p);
            while(nextVertex(p)!=NULL){
                if(highNumFrdMax(G,highest)< highNumFrdMax(G,p)){
                    highest = p;
                    p = nextVertex(p);
                }else if(highNumFrdMax(G,highest)==highNumFrdMax(G,p)){
                    equalP = p;
                    p = nextVertex(p);
                }else{
                    p = nextVertex(p);
                }
            }
            if(highNumFrdMax(G,highest)!= highNumFrdMax(G,equalP)){
                if(highNumFrdMax(G,highest)<highNumFrdMax(G,p)){
                    highest = p;
                    cout<<"                                                           The most Popular Person is : "<<infoVertex(highest).name<<endl;
                }else if(highNumFrdMax(G,highest)==highNumFrdMax(G,p)){
                    cout<<"                                                           There is no one whose popular, because more than one person"<<endl;
                }else{
                    cout<<"                                                           The most Popular Person is : "<<infoVertex(highest).name<<endl;
                }
            }else{
                if(highNumFrdMax(G,highest) >= highNumFrdMax(G,p)){
                    cout<<"                                                           There is no one whose popular, because more than one person"<<endl;
                 }else{
                    highest = p;
                    cout<<"                                                           The most Popular Person is : "<<infoVertex(highest).name<<endl;
                 }
            }
        }
    }
}

/**PROCEDURE SHOW DATA IN SEVERAL THINGS*/

void printData(graph G){
/*I.S. Graph is might empty
  F.S. if graph is not empty, then display all the information belong to graph*/

    adrVertex p;
    adrEdge f,g;
    int n =1 ;
    if(firstVertex(G)==NULL){
        cout<<"                                                                         LIST IS EMPTY"<<endl;
    }else{
        p = firstVertex(G);
        cout<<"                                                           [<>]====================================================[<>]"<<endl;
        cout<<"                                                                  =<>=         --DORMITORY LIST--         =<>=    "<<endl;
        cout<<"                                                           [<>]====================================================[<>]"<<endl;
        while(p!=NULL){
            cout<<"                                                                  "<<n;
            cout<<".FULL NAME   : "<<infoVertex(p).name<<endl;
            cout<<"                                                                    SID         : "<<infoVertex(p).ID<<endl;
            cout<<"                                                                    MAJOR       : "<<infoVertex(p).major<<endl;
            cout<<"                                                                    NATIONALITY : "<<infoVertex(p).nation<<endl;
            cout<<"                                                                    ROOM NUMBER : "<<infoVertex(p).rn<<endl;
            cout<<"                                                                    FRIENDS     : ";
            f = firstEdge(p);
            n++;
            while(f!=NULL){
                cout<<infoEdge(f)<<"";
                f = NextEdge(f);
                cout<<" - ";
            }
        cout<<endl;
        cout<<"                                                           [<>]======================================================[<>]"<<endl;
            p = nextVertex(p);
        }
    }
}

int highNumFrd(graph G, string Name){
/*return the highest number of friend in the graph*/

    adrVertex p;
    adrEdge f;
    int n = 0;
    p = findVertex(G,Name);
    if(p!=NULL){
        f = firstEdge(p);
        if(f==NULL){
            cout<<"                                                                     "<<Name<<", You do not have any friends"<<endl;
        }else{
            while(f!=NULL){
                f = NextEdge(f);
                n++;
            }
            cout<<"                                                                 "<<Name<<", You have "<<n<<" friend/s "<<endl;
            return n;
        }
    }else{
        cout<<"                                                                             There is no "<<Name;
    }
}

int highNumFrdMax(graph G, adrVertex p){
/*return the most popular person in the graph*/

    adrEdge f;
    int n = 0;
    if(p!=NULL){
        f = firstEdge(p);
        if(f!=NULL){
            while(f!=NULL){
                f = NextEdge(f);
                n++;
            }
            return n;
        }
    }
}

void friendGroupNation(graph G, adrVertex p, string Nation){
/*I.S. Graph is not empty
  F.S. display all group from several country in the graph*/

    if(firstVertex(G)!=NULL){
        p = firstVertex(G);
        if(infoVertex(p).nation == Nation){
            while(p!=NULL){
                if(infoVertex(p).nation == Nation){
                    cout<<"                                                                                     - "<<infoVertex(p).name<<endl;
                }
                p = nextVertex(p);
            }
        }else{
            cout<<"                                                                             There is no "<<Nation<<" students"<<endl;
        }
    }
}

void friendGroupMajor(graph G, adrVertex p, string Major){
/*I.S. Graph is not empty
  F.S. display all group from several major in the graph*/

    if(firstVertex(G)!=NULL){
        p = firstVertex(G);
        if(infoVertex(p).major == Major){
            while(p!=NULL){
                if(infoVertex(p).major == Major){
                    cout<<"                                                                                     - "<<infoVertex(p).name<<endl;
                }
                p = nextVertex(p);
            }
        }else{
            cout<<"                                                                             There is no "<<Major<<" students"<<endl;
        }
    }else{
        cout<<"                                                                             LIST IS EMPTY "<<endl;
    }
}
