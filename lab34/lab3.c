#include <stdio.h>
#include "lab3.h"
const int M_SIZE = 50;

const int alphabet [] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                         'H', 'I', 'J', 'K', 'M', 'N', 'L', 'O', 'P',
                         'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
                         'Z'};
void sout(char *text, char format [3]){
    printf(format, text);
}
int CalculateDegree(int x, int degree){
    int res = 1;
    for(int i=0; i < degree; i++) res *= x;
    return res;
}
int convert(int n){
    if((n > 96) && (n <123)) n -= 32;
    if((n > 64) && (n < 91)) n -= 55;
    if ((n >47) && (n < 58)) n -= 48;
    return n;
}

int calc_dec(int num, int ns_st, int degree){
    int k = num, n = 0;
    //if (ns_st != 10) {
    num = 0;
    while(k > 0){
        num += (k % ns_st) * CalculateDegree(ns_st,degree);
        n++;
        k/=ns_st;
    }
    //}
    return num;
}

int check_valid(const char *num, int ns_st){
    int n, res = 0, ind = sizeof num-1;
    for(int i = 0; i < sizeof num; i++) if(num[i] == '\n') {
        ind = i;
        break;
    }
    for(int i = 0; i < sizeof num ; i++){
        if(num[i] == '\n') return res;
        n = convert((int) num[i]);
        if(n >= ns_st) return 0;
        res += calc_dec(n,ns_st, ind - i - 1);
    }
    return res;
}

void change_ns(int num, int ns_res){

    int res [M_SIZE];
    int k, n;
    k = 0;
    while (num > 0){
        n = num % ns_res;
        if (n >= 10) n = alphabet[(n-10) % 26];
        res[k] = n;
        num /= ns_res;
        k++;
    }
    printf("%s", "RES: ");
    for(int i = k - 1; i >= 0; i--){
        n = res[i];
        if (n >= 10) printf("%c", res[i]);
        else printf("%d", res[i]);
    }
}
void input(int ns_st, int ns_res){
    int flag = 0, res;
    char num[M_SIZE];

    while(fgets(num,M_SIZE,stdin) != NULL) {
        if(flag == 1) break;
        else flag = 1;
    }
    res = check_valid((char *) num, ns_st);
    if(!res){
        puts("ERROR! You have entered wrong number.\nThe digits in the number must be less than the number system");
    }else{
        change_ns(res,ns_res);
    }
}



int test(int num, int ns_res){
    int n = num;
    int k = 0, res = 0, c = 1;
    while (n > 0){
        res+= (n%ns_res) * c;
        c*=10;
        n /= ns_res;
        k++;
    }
    return res;
}
int lab3() {
    int x, z, w, p, r, oct_x;
    scanf("%d",&x);
    printf("NUM. DECIMAL: %d%c", x,'\n');

    oct_x = test(x,8);
    printf("TASK 2: %d%c", oct_x,'\n');

    w = (x&0xAAAFFF) << 2;
    printf("TASK 3: %x%c%c",w,' ','\n');

    z = ~(x&0xAAAFFF);
    printf("TASK 4.1: %d%c",x,' ');
    printf("TASK 4.2: %x%c%c",z,' ','\n');

    scanf("%x",&p);
    r = (x&0xAAAFFF) | (p&0xAAAFFF);
    printf("TASK 5: %x",r);
    return 0;
}


void task3(){
    int ns_st, ns_res, num;
    sout("Enter start NS: ", "%s");
    scanf(" %d",&ns_st);
    sout("Enter res NS: ", "%s");
    scanf("%d",&ns_res);
    sout("Enter num: ", "%s");
    input(ns_st, ns_res);
}