#ifndef PROJECTSTD_H_INCLUDED
#define PROJECTSTD_H_INCLUDED

#include <iostream>

#define infoVertex(p) p->infoVertex
#define infoEdge(f) f->infoEdge
#define firstEdge(p) p->firstEdge
#define nextVertex(p) p->nextVertex
#define NextEdge(f) f->NextEdge
#define firstVertex(G) G.firstVertex

using namespace std;

struct infotypeVertex{
    string name, ID, nation, major, rn;
};

typedef struct elmtVertex *adrVertex;
typedef struct elmtEdge *adrEdge;

typedef struct elmtVertex{
    infotypeVertex infoVertex;
    adrEdge firstEdge;
    adrVertex nextVertex;
};

typedef struct elmtEdge{
    string infoEdge;
    adrEdge NextEdge;
};

typedef struct graph{
    adrVertex firstVertex;
};

/** RETURN TRUE IF EMPTY OTHERWISE RETURN FALSE*/
bool isEmptyGraph(graph G);
bool isEmptyChild(adrEdge p);

/** PROCEDURE CREATE GRAPGH AND CHILD ARE GOING TO CREATE EMPTY LIST*/
void createGraph(graph &G);
void createChild(adrEdge &p);

/** FUNCTION CREATEEDGE AND CREATEVERTEX ARE GOING TO ALLOCATE THE DATA IN ADDRESS*/
adrEdge createEdge(string Name);
adrVertex createVertex(string RN,string Name,string SID,string Nation,string Major);

/** PROCEDURE ADD PERSON AND FRIENDSHIP*/
void addPerson(graph &G,adrVertex p);
void insertEdge(adrVertex &p, adrEdge f);

/** PROCEDURE DELETE PERSON AND FRIENDSHIP*/
void deleteFirstPerson(graph &G, adrVertex &p);
void deleteAfterPerson(graph &G, adrVertex &p,adrVertex prec);
void deleteLastPerson(graph &G, adrVertex &p);
void deleteFirstEdge(adrVertex &p, adrEdge &f);
void deleteFriendship(adrVertex &p, string Name, adrEdge &f);
void deleteAfterEdge(adrVertex &p, adrEdge &f, adrEdge prec);
void deleteLastEdge(adrVertex &p, adrEdge &f);
void deletePerson(graph &G, string Name, adrVertex &p);
void deleteEdge(adrVertex &p, string Name, adrEdge &f);

/** PROCEDURE SEARCH THE PERSON AND FRIENDS */
adrVertex findVertex(graph G, string Name);
adrEdge findEdge(graph G,adrVertex p, string Name);
adrEdge findFriend(graph G, adrVertex p, string Name);
void findEdgeDel(graph G, adrVertex p, string Name);
void findMaxFriends(graph G, adrVertex p);

/**PROCEDURE SHOW DATA IN SEVERAL THINGS*/
void printData(graph G);
int highNumFrd(graph G, string Name);
int highNumFrdMax(graph G, adrVertex p);
void friendGroupNation(graph G, adrVertex p,string Nation);
void friendGroupMajor(graph G, adrVertex p, string Major);

/** MAIN PROCEDURE*/
int loading();
void FirstScreen();
void MainMenu(graph &G);
void Login();
void clrscr();

#endif // PROJECTSTD_H_INCLUDED
