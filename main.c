#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_SIZE 20
#define MAX_USERS 10

struct group
{
    int id;
    int noPeople;
    struct user *list[MAX_USERS];
};

struct user
{
    int userid;
    char name[MAX_STRING_SIZE];
};

int main(){
    return 0;
}