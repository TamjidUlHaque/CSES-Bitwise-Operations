#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define sesh '\n'
#define gap ' '
#define display(x) for(auto val:x) cout << val << ' ' ;

/*
    Intuition :- Question er value gula ekhane jei pyramid ta gothon kortese oi pyramid
    er peak value ta create korte kun element koybar kore vumika rakhtese eita calculation
    korle dekha jay proti ta cell er number_of_contribution = Pascal Triangle e oi cell er
    value . Ekhon pascal triangle amra eto boro value er jonne calculation korte parbo na .
    Tai amader ke kuno ekta technique use korte hobe ei issue ta resolve korar jonne.

    Amra jani kuno ekta number even songkhok bar Xor kora ar ekbar o Xor na kora same e
    kotha . Tahole amader array er jeishokol element er number of Contribution odd hobe
    kebol oi shokol element ke answer er moddhe ekbar xor kore dile e answer pawa jabe .

    Ekhon ((row)C(index)) er value ta calculation kora jabe na karon eto boro value er
    jonne mod chara factorial calculate kora shomvob na . Amra kebol parity check er jonne
    nCr formula ta ke utilize korbo .

    ((row)C(index)) = (row! / (index!) * ((row-index)!)) Ei value ta tokhon e odd hobe
    jokhon row! er moddhe 2 divisor hishabe thakbe na . Jodi amra limit porjonto shobgula
    value er jonne numberOf2 as a divisor calculate kore felte pari tahole jehetu vaag hocche
    tahole Biyug kore koyta 2 obosisto thakbe ta bole dite parbo .
*/

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int limit = 2e5+33 , answer = 0 ;
    vector<int> number_of_2_as_a_divisor_in_Factorial(limit,0) ;

    for(int i = 1 ; i < limit ; i++){
        number_of_2_as_a_divisor_in_Factorial[i] += number_of_2_as_a_divisor_in_Factorial[i-1] ;
        int temp = i ;
        while(temp%2==0){
            number_of_2_as_a_divisor_in_Factorial[i]++ ;
            temp /= 2 ;
        }
    }

    int n ; cin >> n ; vector<int> vec(n) , parity(n,-1) ;
    for(int i = 0 ; i < n ; i++) cin >> vec[i] ;

    for(int i = 0 ; i < n ; i++){
        int numerator = number_of_2_as_a_divisor_in_Factorial[n-1] ;
        int denom = number_of_2_as_a_divisor_in_Factorial[i] + number_of_2_as_a_divisor_in_Factorial[n-i-1] ;
        int rem = numerator - denom ;
        if(rem>0) parity[i] = 0 ;
        else parity[i] = 1 ;
    }

    for(int i = 0 ; i < n ; i++){
        if(parity[i]) answer ^= vec[i] ;
    }

    cout << answer << sesh ;

    return 0 ;
}
