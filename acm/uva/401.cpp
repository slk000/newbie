//AC
#include <cstdio>
#include <cstring>
char str[22];
int len;
char mirror[] = {'A',0,0,0,'3',0,0,'H','I','L',0,'J','M',0,'O',0,0,0,'2','T','U','V','W','X','Y','5','1','S','E',0,'Z',0,0,'8',0};
bool isPalindrome, isMirror;
char getMirrorChar(char ch){
    if (ch >= 'A' && ch <= 'Z'){
        return mirror[ch-'A'];
    }
    else if(ch >='1' && ch <='9'){
        return mirror[ch-'1'+26];
    }
}
void solve(){
    
    char *head = str, *tail = str+len-1;
    while((head <= tail)){
        isPalindrome &= ((*head) == (*tail));
        isMirror &= ((*head) == getMirrorChar(*tail));
        head++;tail--;
    }
    return ;
}

int main () {
    while(EOF != scanf("%s", str)) {
        isPalindrome=isMirror=true;
        len = strlen(str);
        solve();
        if (!isPalindrome && !isMirror) {
            printf("%s -- is not a palindrome.\n", str);
        }
        else if(isPalindrome && !isMirror){
            printf("%s -- is a regular palindrome.\n", str);
        }
        else if(!isPalindrome && isMirror){
            printf("%s -- is a mirrored string.\n", str);
        }
        else{
            printf("%s -- is a mirrored palindrome.\n", str);
        }
        printf("\n");
    }
    return 0;
}
