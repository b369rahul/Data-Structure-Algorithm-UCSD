#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
#define int long long
using namespace std;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in_order_reccursive(vector<int>&result,int i){
    if(left[i]==-1){
    result.push_back(key[i]);
    if(right[i]==-1)return;
    in_order_reccursive(result,right[i]); 
    return;}
    in_order_reccursive(result,left[i]);
    result.push_back(key[i]);
    if(right[i]==-1)return;
    in_order_reccursive(result,right[i]);    
    return;
  }

  void pre_order_reccursive(vector<int>&result,int i){
    result.push_back(key[i]);
    if(left[i]==-1){
      if(right[i]==-1)return;
      pre_order_reccursive(result,right[i]);
      return;
    }
    pre_order_reccursive(result,left[i]);

    if(right[i]==-1)return;
    pre_order_reccursive(result,right[i]);
    return;
  }

  void post_order_reccursive(vector<int>&result,int i){
    if(left[i]==-1){
      if(right[i]==-1){
        result.push_back(key[i]);
        return;}
      post_order_reccursive(result,right[i]);
      result.push_back(key[i]);
      return;
    }
    post_order_reccursive(result,left[i]);
    if(right[i]==-1){
      result.push_back(key[i]);
      return;}
    post_order_reccursive(result,right[i]);
    result.push_back(key[i]);
    return;
  }

  vector <int> in_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    in_order_reccursive(result,0);

    return result;
  }

  vector <int> pre_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    pre_order_reccursive(result,0);
    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    post_order_reccursive(result,0);
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int32_t main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int32_t main (int32_t argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

