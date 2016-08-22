//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1023
#include <cstdio>
int main () {
    char ch;
    char chs[26] = {'\0','V','X','S','W','D','F','G','U','H','J','K','N','B','I','O','\0','E','A','R','Y','C','Q','Z','T','\0'};
    char digs[] = {'9','`','1','2','3','4','5','6','7','8'};
    while(EOF!=(ch=getchar())) {
        switch(ch){
        case ' ':
        case '\n':
            break;
        case '[':
            ch='P';
            break;
        case ']':
            ch='[';
            break;
        case '\\':
            ch=']';
            break;
        case ';':
            ch='L';
            break;
        case '\'':
            ch=';';
            break;
        case ',':
            ch='M';
            break;
        case '.':
            ch=',';
            break;
        case '/':
            ch='.';
            break;
        case '-':
            ch='0';
            break;
        case '=':
            ch='-';
            break;
        default:
            if (ch>='0'&&ch<='9') ch=digs[ch-'0'];
            else ch=chs[ch-'A'];
        }
        printf("%c", ch);
    }
    return 0;
}

