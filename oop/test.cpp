#include <bits/stdc++.h>
using namespace std;
class PS{
private:
    int ts, ms;
public: 
    PS(){
        ts=0;
        ms=1;
    }
    PS(int ts, int ms){
        this ->ts=ts;
        this ->ms=ms;
    }
    ~PS(){
        
    } 
    // void nhap {
    // cout <<"nhap tu so";
    // cin >> ts;
    // cout>>"nhap mau so";
    // cin >> ms
    // }
    void xuat(){
        cout<<ts<<"/"<<ms<<endl;
    }
    PS operator +( PS b) {
         return PS(ts* b.ms + ms* b.ts, ms * b.ms) ; 
    }
    PS operator -( PS b) {
         return PS(ts* b.ms - ms* b.ts, ms * b.ms) ;} 
    PS operator *( PS b) {
         return PS(ts* b.ts, ms * b.ms) ;} 
    PS operator /( PS b) {
         return PS(ts* b.ms, ms * b.ts) ;} 




};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    PS a(1,2);
    PS b(3,4);
    PS kq = a*b;
    PS kqcong = a+b;
    PS kqtru =a-b;
    kqcong.xuat();
    kq.xuat();
    kqtru.xuat();

        return 0;
}