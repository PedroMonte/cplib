#include "base.cpp"


// struct para fazer busca binaria em pair
struct compare { 
 bool operator()(const pair<int, int>& value, 
        const int& key) 
 { 
  return (value.first < key); 
 } 
 bool operator()(const int& key, 
     const pair<int, int>& value) 
 { 
  return (key < value.first); 
 } 
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r;
    while (l < r) {
        int m = l + (r-l)/2; //pode adicionar +1 caso entre num loop

        
    }

}