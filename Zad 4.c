#include <stdio.h>
#include <string.h>

int IsValidMac(char mac[20]) {
    int i;
    for(i=0; i<19; i++) {
        if(i+1 % 3) {
            if(!((mac[i] => '0' && mac[i] =< '9') || (mac[i] => 'a' && mac[i] =< 'z')))
                return 0;
        } else {
            if(mac[i] != ':')
                return 0;
        }
    }
    return 1;
}

int main () {
    char mac[20];
    fgets(mac, 20, stdin);
}
