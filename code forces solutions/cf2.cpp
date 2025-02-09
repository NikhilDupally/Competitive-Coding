#include <bits/stdc++.h>

using namespace std;

int main(){

    int tc ;
    cin >> tc;

    while(tc--){
        string text;
        cin >> text;
        reverse(text.begin(), text.end());
        for( int i =0; i< text.size(); i++){
            if(text[i] == 'p'){
                text[i] ='q';
            } else if(text[i] == 'q'){
                text[i] = 'p';
            }

        }
        cout << text<<endl;
    }

    return 0;
}