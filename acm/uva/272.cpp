//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=208
#include <cstdio>
int main () {
    bool flag=false;
    char ch;

    while(EOF!=(ch=getchar())) {
        if (ch=='"'){
            printf("%s", flag?"''":"``");
            flag^=1;
        }
        else
            printf("%c", ch);
    }
    return 0;
}
