#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_SIZE 20
#define MAX_USERS 10

int currentGroupID = 1;
int currentUserID = 1;
int currentTransactionID = 1;

struct group *groupList[5];

struct group
{
    int groupid;
    int noPeople;
    char groupName[MAX_STRING_SIZE];
    struct user *list[MAX_USERS];
    int money[MAX_USERS][MAX_USERS];
};

struct user
{
    int userid;
    char name[MAX_STRING_SIZE];
};

struct transaction
{
    int tid;
    int groupid;
    int giverid;
    // int borrowers[MAX_USERS];
    float amount;
};

struct group* createGroup(){
    struct group *newGroup = (struct group*)malloc(sizeof(struct group));
    newGroup->groupid = currentGroupID;
    scanf("%d",&newGroup->noPeople);
    scanf("%s",newGroup->groupName);
    for(int i=0;i<newGroup->noPeople;i++)
        for(int j=0;j<newGroup->noPeople;j++)
            newGroup->money[i][j]=0;
    for(int i=0;i<newGroup->noPeople; i++){
        struct user *usr = (struct user*)malloc(sizeof(struct user));
        usr->userid = currentUserID;
        currentUserID++;
        scanf("%s",usr->name);
        newGroup->list[i] = usr;
        // free(usr);
    }
    groupList[currentGroupID-1] = newGroup;
    currentGroupID++;
}

void makeTransaction()
{
    struct transaction *newtrans=(struct transaction*)malloc(sizeof(struct transaction));
    newtrans->tid=currentTransactionID;
    currentTransactionID++;
    scanf("%d",&newtrans->groupid);
    scanf("%d",&newtrans->giverid);
    scanf("%f",&newtrans->amount);
}

int main(){
    struct group *grp = createGroup();
    printf("\n%d %d\n%s\n",grp->groupid,grp->noPeople,grp->groupName);
    for(int i=0;i<grp->noPeople;i++){
        printf("%d %s\n",grp->list[i]->userid,grp->list[i]->name);
    }
    return 0;
}