#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int BUCKETS = 10;
static unsigned long long colisions = 0;

void display(const vector<float> &array) {
   for(size_t i = 0; i<array.size(); i++)
      cout << array[i] << " ";
   cout << endl;
}
void bucketSort(vector<float> &array) {
   vector<float> bucket[BUCKETS];
   for(size_t i = 0; i < array.size(); i++)  {          //put elements into different buckets
      bucket[(int)array[i]/BUCKETS].push_back(array[i]);
   }
   for(int i = 0; i<BUCKETS; i++) {
      sort(bucket[i].begin(), bucket[i].end());       //sort individual vectors
   }
   size_t index = 0;
   for(int i = 0; i<BUCKETS; i++) {
       vector<float> temp = bucket[i];
       if(temp.size() > colisions){
           colisions = temp.size();
       }
      while(!temp.empty()) {
         array[index++] = *(temp.begin());
         temp.erase(temp.begin());
      }
   }
}
int main() {
   vector<float> arr;
   float n;
   while(cin >> n){
       if(n == 0){
           break;
       }
       arr.push_back(n);
   }
   bucketSort(arr);
   display(arr);
   cout << colisions;
}
