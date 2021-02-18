#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_SIZE 20
#define MAX_USERS 10
#define MAX_GROUPS 20

int groups = 0;

struct group *groupList[MAX_GROUPS];

struct group {
    __uint64_t groupid;
    int noPeople;
    char groupName[MAX_STRING_SIZE];
    struct user *list[MAX_USERS];
    int money[MAX_USERS][MAX_USERS];
};

struct user {
    __uint64_t userid;
    char name[MAX_STRING_SIZE];
};

struct transaction {
    __uint64_t tid;
    int groupid;
    int giverid;
    // int borrowers[MAX_USERS];
    float amount;
};

int getRandomInt() {
    __uint64_t number = rand(), temp;
    temp = number;
    int count=0;
    while (temp != 0) {
        temp/= 10;     
        ++count;
    }
    if(count<4){
        for(int i=0;i<4-count;i++) number=number*10;
    }
    if(count>4){
        for(int i=0;i<count-4;i++) number=number/10;
    }
    return number;
}

struct group *getGroup(int key) {
    int lowIndex = 0, highIndex = groups, midIndex;
    while(lowIndex <= highIndex) {
        midIndex = lowIndex + (highIndex - lowIndex)/2;
        if(groupList[midIndex]->groupid == key)
            return groupList[midIndex];
        if(groupList[midIndex]->groupid > key)
            lowIndex = midIndex+1;
        if(groupList[midIndex]->groupid < key)
            highIndex = midIndex-1;
    }
}

void insertInList()
{
    if(groups==1){
        return;
    }
    struct group *key = groupList[groups-1];
    int j = groups-2;
    while(j>=0 && groupList[j]->groupid>key->groupid){
        groupList[j+1] = groupList[j];
        j--;
    }
    groupList[j+1] = key;
}

void createGroup(){
    struct group *newGroup = (struct group*)malloc(sizeof(struct group));
    newGroup->groupid = getRandomInt();
    scanf("%d",&newGroup->noPeople);
    scanf("%s",newGroup->groupName);
    for(int i=0;i<newGroup->noPeople;i++)
        for(int j=0;j<newGroup->noPeople;j++)
            newGroup->money[i][j]=0;
    for(int i=0;i<newGroup->noPeople; i++){
        struct user *usr = (struct user*)malloc(sizeof(struct user));
        usr->userid = getRandomInt();
        //currentUserID++;
        scanf("%s",usr->name);
        newGroup->list[i] = usr;
        // free(usr);
    }
    groupList[groups] = newGroup;
    groups++;
    insertInList();
    //currentGroupID++;
}


void makeTransaction()
{
    struct transaction *newtrans=(struct transaction*)malloc(sizeof(struct transaction));
    newtrans->tid=getRandomInt();
    //currentTransactionID++;
    scanf("%d",&newtrans->groupid);
    scanf("%d",&newtrans->giverid);
    scanf("%f",&newtrans->amount);
}

int main() {
    srand( time(0) );
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int nums;
    scanf("%d", &nums);
    for(int i=0; i<nums; i++)
        createGroup();
    for(int i=0; i<nums; i++) {
        printf("%d %s\t",groupList[i]->groupid,groupList[i]->groupName);
        for(int j=0;j<groupList[i]->noPeople;j++)
            printf("%s ",groupList[i]->list[j]->name);
        printf("\n");
    }
    return 0;
}