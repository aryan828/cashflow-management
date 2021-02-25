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
    float money[MAX_USERS][MAX_USERS];
};

struct user {
    __uint64_t userid;
    char name[MAX_STRING_SIZE];
};

struct transaction {
    __uint64_t tid;
    int groupid;
    int giverid;
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

struct group* getGroup(int key) {
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

void printMat(){
    int gid;
    printf("\nEnter Group-id: ");
    scanf("%d", &gid);
    struct group* temp = getGroup(gid);
    for(int i=0;i<temp->noPeople;i++){
        for(int j=0;j<temp->noPeople;j++){
            printf("%f ",temp->money[i][j]);
        }
        printf("\n");
    }
}

void insertInList() {
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
    printf("\nEnter number of people: ");
    scanf("%d",&newGroup->noPeople);
    printf("\nEnter Group Name: ");
    scanf("%s",newGroup->groupName);
    for(int i=0;i<newGroup->noPeople;i++)
        for(int j=0;j<newGroup->noPeople;j++)
            newGroup->money[i][j]=0;
    for(int i=0;i<newGroup->noPeople; i++){
        struct user *usr = (struct user*)malloc(sizeof(struct user));
        usr->userid = getRandomInt();
        printf("\nEnter name os user %d :", i);
        scanf("%s",usr->name);
        newGroup->list[i] = usr;
    }
    groupList[groups] = newGroup;
    groups++;
    insertInList();
}

void viewAllGroups(){
    printf("\nAvailable groups: \nGroup ID | Group Name");
    printf("\n----------------------\n");
    for(int i=0; i<groups;i++){
        printf("%ld     | %s\n",groupList[i]->groupid,groupList[i]->groupName);
    }
}

void viewGroup(int id){
    struct group* temp = getGroup(id);
    printf("\nGroup-id: %ld Group Name: %s\n",temp->groupid,temp->groupName);
    printf("User-id | Username");
    printf("\n----------------------\n");
    for(int i=0;i<temp->noPeople;i++){
        printf("%ld    | %s\n",temp->list[i]->userid,temp->list[i]->name);
    }
}

void makeTransaction()
{
    struct transaction *newtrans=(struct transaction*)malloc(sizeof(struct transaction));
    newtrans->tid=getRandomInt();
    viewAllGroups();
    printf("\nEnter group-id: ");
    scanf("%d",&newtrans->groupid);
    viewGroup(newtrans->groupid);
    printf("\nEnter user-id: ");
    scanf("%d",&newtrans->giverid);
    printf("\nEnter amount: ");
    scanf("%f",&newtrans->amount);
    struct group* temp=getGroup(newtrans->groupid);
    int cnt;
    for(int i=0;i<temp->noPeople;i++){
        if(temp->list[i]->userid==newtrans->giverid){
            cnt=i;
        }
    }
    for(int j=0;j<temp->noPeople;j++){
        temp->money[cnt][j]+=newtrans->amount/temp->noPeople;
    }
}

void setSeed(){
    srand( time(0) );
}

int getMin(float arr[], int N) 
{ 
    int minInd = 0; 
    for (int i=1; i<N; i++) 
        if (arr[i] < arr[minInd]) 
            minInd = i; 
    return minInd; 
} 

int getMax(float arr[], int N) 
{ 
    int maxInd = 0; 
    for (int i=1; i<N; i++) 
        if (arr[i] > arr[maxInd]) 
            maxInd = i; 
    return maxInd; 
}

float minOf2(float x, float y) 
{ 
    return (x<y)? x: y; 
}

void minCashFlowRec(float amount[], int N) 
{
    int mxCredit = getMax(amount, N), mxDebit = getMin(amount, N);
    if ((int)amount[mxCredit] == 0 && (int)amount[mxDebit] == 0) 
        return;
    float min = minOf2(-amount[mxDebit], amount[mxCredit]); 
    amount[mxCredit] -= min; 
    amount[mxDebit] += min;
    printf("Person %d pays %f to Person %d\n",mxDebit,min,mxCredit);
    minCashFlowRec(amount, N); 
} 

void minCashFlow(struct group *temp) 
{
    int N = temp->noPeople;
    float amount[N];
    for (int i = 0; i < N; i++)
    {
        amount[i] = 0;
    }
    

    for (int p=0; p<N; p++) 
       for (int i=0; i<N; i++) 
          amount[p] += (temp->money[i][p] -  temp->money[p][i]); 
  
    minCashFlowRec(amount, N); 
} 

int main() {
    setSeed();
    int loop = 1;
    struct group* temp;
    int id;
    while(loop) {
        printf("1.Create group  2.View all groups  3.View group  4.Exit  5.Add Transaction  6.PrintMat  7.Simplify Debts\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1: createGroup();
                    break;
            case 2: viewAllGroups();
                    break;
            case 3: viewAllGroups();
                    printf("Enter group-id: ");
                    scanf("%d",&id);
                    viewGroup(id);
                    break;
            case 4: loop = 0;
                    break;
            case 5: makeTransaction();
                    break;
            case 6: viewAllGroups();
                    printMat();
                    break;
            case 7: viewAllGroups();
                    printf("Enter group-id: ");
                    scanf("%d",&id);
                    temp = getGroup(id);
                    minCashFlow(temp);
                    break;
            default: break;
        }
    }

    return 0;
}