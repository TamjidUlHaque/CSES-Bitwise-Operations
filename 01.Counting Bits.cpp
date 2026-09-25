#include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
const ll mod = 1e9 + 7 ;
#define len(x) (int)((x).size())
#define sesh '\n'

/*
    Intuition :- Ei question er constraints etto boro je simulate kora
    impossible . Amader ke kuno ekta pattern khuje ber korte hobe answer
    calculate korar jonne .

    Jodi amra kichu decimal number er Binary form dekhi

    0000
    0001
    0010
    0011
    0100
    0101
    0110
    0111
    1000
    1001
    1010
    1011
    1100
    1101
    1110
    1111

    Tahole dekha jacche je one's er place e set bit alternate kortese
    for every pair of bits . Ten's er place e set bit proti 4 ghor er
    jonne ekta pattern mene choltese . Hundred's er place e 8 ghor er
    jonne pattern dekha jacche . Ei pattern follow kore amader ke answer
    er dike move korte hobe . Ekhane 2 er power porjonto ekta interval
    akare jodi amra chinta kori tahole dekha jabe powerOf2 er point e
    eshe ekta set puron hocche .
    Oi set e koto gula set bit ache oita jodi amra thik vabe calculate
    korte pari and porer number gula ke jodi kuno ekta pattern e fele
    dite pari tahole e amra khub sohoje answer peye jabo . Maximum power
    of 2 not exceeding the given limit n er porer proti ta value er MSB
    ta on thake oi most significant bit joto gula ache oi gula hishab
    kore baki gular jonne amra amader same function ke abar call korte
    pari . Taile answer peye jabo .

    Let ,
        x = maximum power of 2 not exceeding the limit ;
    Number of set bit pow(2,x) has in one's place = pow(2,x)/2
    Number of set bit pow(2,x) has in ten's place = pow(2,x)/2
    Number of set bit pow(2,x) has in one's place = pow(2,x)/2
    Jodi amra shobgula value ke jug kori tahole amra ja pabo
    ta holo noOfBits in x * (pow(2,x)/2) .
    Baki remaining value = n - pow(2,x) .
    Ekhane remaining value er shobgula te Most Significant Bit 1 .
    Answer er sathe (n-pow(2,x)+1) add hobe ar answer(n-pow(2,x))
    o add hobe karon baki number gula same format follow korbe .
*/

ll maximum_power_of_2_not_exceeding_limit(ll n){
    ll power = 1 ;
    while((1LL<<power)<=n) power++ ;
    return (power-1) ;
}

ll solve(ll n){
    if(n<2) return n ;
    ll x = maximum_power_of_2_not_exceeding_limit(n) ;
    ll y = (1LL<<x) ;
    ll result = x * (y/2) + (n-y+1) + solve(n-y) ;
    return result ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n ; cin >> n ; ll ans = solve(n) ;

    cout << ans << '\n' ;

    return 0 ;

}
