#include <iostream>
#include <memory>

using namespace std;

void client_function(shared_ptr<int> &p)
{
  shared_ptr<int> _pref(p);

  cout <<" client current reference count: " << _pref.use_count() <<" _pref value: "<< *_pref<<endl;

}

int main(int argc, const char **argv)
{
  int *p = new int(100);
  shared_ptr<int> pref(p);
  shared_ptr<int> pref2(pref);
  shared_ptr<int> pref3(pref);

  cout <<" ref count: "<< pref.use_count() <<" *p value: "<< *p <<" *perf2 value: "
       << *pref2 <<" *pref3 value: "<< *pref3 << endl;

  client_function(pref);

  *p = 101;

  shared_ptr<int> pref4(pref);
  
  cout <<" ref count: "<< pref.use_count() <<" *p value: "<< *p <<" *perf2 value: "
       << *pref2 <<" *pref3 value: "<< *pref3 <<" *pref4 value: "<< *pref4 << endl;

  return 0;
}
